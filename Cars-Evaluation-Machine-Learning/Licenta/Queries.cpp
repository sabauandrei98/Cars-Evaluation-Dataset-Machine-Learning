#include "Queries.h"

void Queries::runQueries()
{
	///CONSOLE LOG INFO
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << endl << endl << "===Running Queries===" << endl << endl;
	cout << "Queries: " << this->queriesSet.size() << endl;


	Tools tools;
	int failedQueries = 0;
	for (int setIndex = 0; setIndex < this->queriesSet.size(); setIndex++)
	{
		string treeValue = "unacc"; findQueryValue(root, queriesSet[setIndex], treeValue);
		string queryValue = tools.getFeatureProperty("value", queriesSet[setIndex].carProperty[6]);
		if (treeValue != queryValue)
			failedQueries++;

		queriesResults.push_back(make_pair(tools.getValueToInt(treeValue), tools.getValueToInt(queryValue)));

		///CONSOLE LOG INFO
		if (queryValue == treeValue)
			SetConsoleTextAttribute(hConsole, 10);
		else
			SetConsoleTextAttribute(hConsole, 12);
		cout << "Query:" << setIndex << " [db=" << treeValue << "] [query=" << queryValue << "]" << endl;
	}

	///CONSOLE LOG INFO
	SetConsoleTextAttribute(hConsole, 7);
	cout << endl << "===Queries results===" << endl;
	cout << "Passed " << this->queriesSet.size() - failedQueries << " out of " << this->queriesSet.size() << " (" <<
		(double)(this->queriesSet.size() - failedQueries) / this->queriesSet.size() * 100 << "%)" << endl;
}

void Queries::findQueryValue(Node* node, Car& query, string& result)
{
	Tools tools;
	for (int i = 0; i < node->next.size(); i++)
	{
		if (node->next[i]->carFeature == "value")
		{
			if (node->next[i]->carProperty != "")
			{
				result = node->next[i]->carProperty;
				return;
			}
		}

		string treeFeatureValue = node->next[i]->carProperty;
		int queryProperty = query.carProperty[tools.initialFeatureIndex(node->next[i]->carFeature)];
		string queryFeatureValue = tools.getFeatureProperty(node->next[i]->carFeature, queryProperty);

		if (treeFeatureValue == queryFeatureValue)
			findQueryValue(node->next[i], query, result);
	}
}