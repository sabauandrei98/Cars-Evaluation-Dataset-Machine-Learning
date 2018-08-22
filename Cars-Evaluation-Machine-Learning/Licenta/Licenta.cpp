#include <iostream>
#include <Windows.h>
#include "DataBase.h"
#include "DecisionTree.h"
#include "Queries.h"
#include "ConfusionMatrix.h"
#include "TestsControler.h"
using namespace std;

void runCase()
{
	int learningPercent = 88;
	DataBase db{ "data.txt", learningPercent };
	DecisionTree dt{ db.getLearningSet(), db.getFeatureSet() };
	Queries queries{ db.getQueriesSet(), dt.getTreeRoot() };
	ConfusionMatrix confusionMatrix{ queries.getQueriesResult() };
}

void runTests()
{
	TestsControler tests;
}

int main()
{
	//runCase();
	runTests();

	system("pause");
    return 0;
}

