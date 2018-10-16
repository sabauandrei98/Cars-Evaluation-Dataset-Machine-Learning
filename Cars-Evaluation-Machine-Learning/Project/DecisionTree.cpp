#include "DecisionTree.h"

DecisionTree::DecisionTree(vector<Car>& learningSet, vector<string>& featureSet)
{
	///CONSOLE LOG INFO
	cout << "===Decision Tree===\n";
	cout << "Showing clear paths and their final values:\n\n";

	Node* node = new Node;
	node->carFeature = "root";
	node->features = featureSet;
	node->cars = learningSet;
	this->root = node;
	this->buildTree(this->root, "");
}

void DecisionTree::buildTree(Node* node, string path)
{
	//DOMINANT PROPERTY
	if (node->dominantProperty)
	{
		if (node->similarityInfo.first >= minSimilarityPercent)
		{
			Node* newNode = new Node;
			newNode->carFeature = "value";
			newNode->carProperty = node->similarityInfo.second;
			node->next.push_back(newNode);

			path += node->carFeature + "." + node->carProperty + " -> ";

			///CONSOLE LOG INFO
			cout << "Path: " << path << " [" << node->similarityInfo.second << "]\n";

			return;
		}
	}

	//INFORMATION GAIN
	Tools tools;
	TableControler tableControler;

	string bestFeature = this->bestEntropyFeature(node);

	//LEAF REACHED
	if (bestFeature == "null")
	{
		Node* newNode = new Node;
		newNode->carFeature = "value";
		newNode->carProperty = node->similarityInfo.second;
		node->next.push_back(newNode);
		return;
	}

	string bestProperty = this->bestEntropyProperty(node, bestFeature);

	path += node->carFeature + "." + node->carProperty + " -> ";

	for (int propertyValue = minPropertyVal; propertyValue <= maxPropertyVal; propertyValue++)
	{
		if (tools.getFeatureProperty(bestFeature, propertyValue) == "null")
			continue;

		Node* newNode = new Node;
		newNode->carFeature = bestFeature;
		newNode->carProperty = tools.getFeatureProperty(bestFeature, propertyValue);
		newNode->similarityInfo = getMaxSimilarityInfo(node, newNode->carFeature, newNode->carProperty);
		newNode->features = node->features;
		newNode->cars = tableControler.filterProperty(node, bestFeature, tools.getFeatureProperty(bestFeature, propertyValue));
		newNode->cars = tableControler.removeFeature(newNode, bestFeature);
		newNode->features.erase(newNode->features.begin() + tableControler.getFeatureIndex(node, bestFeature));

		if (newNode->carProperty == bestProperty)
			newNode->dominantProperty = true;

		node->next.push_back(newNode);

		if (newNode->features.size() > 1)
			this->buildTree(newNode, path);
	}	
}

pair<double, string> DecisionTree::getMaxSimilarityInfo(Node* node, string carFeature, string carProperty)
{
	Tools tools;
	TableControler tableControler;
	int thisPropertyRecords = 0;
	int qualityRecords[maxPropertyVal + 1] = { 0 };

	for (int tableIndex = 0; tableIndex < node->cars.size(); tableIndex++)
	{
		if (node->cars[tableIndex].carProperty[tableControler.getFeatureIndex(node, carFeature)] == tools.getFeatureProperty(carFeature,carProperty))
		{
			int valueType = node->cars[tableIndex].carProperty[node->cars[tableIndex].carProperty.size() - 1];
			qualityRecords[valueType]++;
			thisPropertyRecords++;
		}
	}
	
	double maxSimilarityValue = 0;
	string carValue = "";
	for (int qualityIndex = minPropertyVal; qualityIndex <= maxPropertyVal; qualityIndex++)
	{
		if (qualityRecords[qualityIndex] == 0)
			continue;

		double similarity = (double)qualityRecords[qualityIndex] / thisPropertyRecords;
		if (similarity > maxSimilarityValue)
		{
			maxSimilarityValue = similarity;
			carValue = tools.getFeatureProperty("value", qualityIndex);
		}
	}
	return make_pair(maxSimilarityValue * 100, carValue);
}

string DecisionTree::bestEntropyFeature(Node* node)
{
	double bestValue = LONG_MAX;
	string bestFeature = "null";
	for (int carFeatureIndex = 0; carFeatureIndex < node->features.size() - 1; carFeatureIndex++)
	{
		double localValue = this->calculateFeatureEntropy(node->cars, carFeatureIndex);
		if (localValue < bestValue && localValue != 0)
		{
			bestValue = localValue;
			bestFeature = node->features[carFeatureIndex];
		}
	}
	return bestFeature;
}

string DecisionTree::bestEntropyProperty(Node* node, string carFeature)
{
	Tools tools;
	TableControler tableControler;
	double bestValue = LONG_MAX;
	string bestProperty = "";
	int featureIndex = tableControler.getFeatureIndex(node, carFeature);

	for (int carPropertyValue = minPropertyVal; carPropertyValue <= maxPropertyVal; carPropertyValue++)
	{
		double localValue = this->calculatePropertyEntropy(node->cars, featureIndex, carPropertyValue);
		if (localValue < bestValue && tools.getFeatureProperty(carFeature, carPropertyValue) != "null")
		{
			bestValue = localValue;
			bestProperty = tools.getFeatureProperty(carFeature, carPropertyValue);
		}
	}
	return bestProperty;
}

double DecisionTree::calculateFeatureEntropy(vector<Car>& table, int carFeatureIndex)
{
	double featureEntropy = 0;

	for (int carPropertyValue = minPropertyVal; carPropertyValue <= maxPropertyVal; carPropertyValue++)
	{
		featureEntropy += calculatePropertyEntropy(table, carFeatureIndex, carPropertyValue);
	}
	return featureEntropy;
}

double DecisionTree::calculatePropertyEntropy(vector<Car>& table, int carFeatureIndex, int carProperty)
{
	int carPropertyValue_occurrences = 0;
	int quality_occurrences[maxPropertyVal + 1] = { 0 };

	for (int tableIndex = 0; tableIndex < table.size(); tableIndex++)
		if (table[tableIndex].carProperty[carFeatureIndex] == carProperty)
		{
			int valueType = table[tableIndex].carProperty[table[tableIndex].carProperty.size() - 1];
			quality_occurrences[valueType]++;
			carPropertyValue_occurrences++;
		}

	double propertyEntropy = 0;
	for (int qualityIndex = minPropertyVal; qualityIndex <= maxPropertyVal; qualityIndex++)
	{
		if (quality_occurrences[qualityIndex] == 0)
			continue;

		double probability = (double)quality_occurrences[qualityIndex] / carPropertyValue_occurrences;
		propertyEntropy -= probability * log2(probability);
	}
	return (double)(carPropertyValue_occurrences) / table.size() * propertyEntropy;
}

void DecisionTree::cutTree(Node* node)
{
	if (node->next.size() == 0)
	{
		delete node;
		return;
	}

	for (int childIndex = 0; childIndex < node->next.size(); childIndex++)
	{
		cutTree(node->next[childIndex]);
	}
	delete node;
}

DecisionTree::~DecisionTree()
{
	cutTree(root);
}

