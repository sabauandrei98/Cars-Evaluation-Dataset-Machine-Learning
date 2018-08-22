#include "TableControler.h"


vector<Car> TableControler::filterProperty(Node* node, string carFeature, string carProperty)
{
	Tools tools;
	int featureIndex = getFeatureIndex(node, carFeature);
	vector<Car> filteredTable;

	for (int tableIndex = 0; tableIndex < node->cars.size(); tableIndex++)
		if (node->cars[tableIndex].carProperty[featureIndex] == tools.getFeatureProperty(carFeature, carProperty))
			filteredTable.push_back(node->cars[tableIndex]);

	return filteredTable;
}

vector<Car>& TableControler::removeFeature(Node* node, string carFeature)
{
	int featureIndex = getFeatureIndex(node, carFeature);

	for (int tableIndex = 0; tableIndex < node->cars.size(); tableIndex++)
	{
		node->cars[tableIndex].carProperty.erase(node->cars[tableIndex].carProperty.begin() + featureIndex);
	}

	return node->cars;
}

int TableControler::getFeatureIndex(Node* node, string carFeature)
{
	int featureIndex = -1;

	for (int carFeatureIndex = 0; carFeatureIndex < node->features.size(); carFeatureIndex++)
	{
		if (node->features[carFeatureIndex] == carFeature)
			featureIndex = carFeatureIndex;
	}
	return featureIndex;
}