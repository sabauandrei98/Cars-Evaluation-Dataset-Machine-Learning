#include "QueriesTests.h"

QueriesTests::QueriesTests()
{
	queriesTests();
}

void QueriesTests::queriesTests()
{
	DataBase db{ "data.txt", 99 };
	DecisionTree dt{ db.getLearningSet(), db.getFeatureSet() };
	Queries queries{ db.getQueriesSet(), dt.getTreeRoot() };
	queries.runQueries();
	string result = "";

	Car car1{ "vhigh", "vhigh", "2", "2", "small", "low", "unacc" };
	queries.findQueryValue(dt.getTreeRoot(), car1, result);
	assert(result == "unacc");

	Car car2{ "low","low","5more","more","big","high","vgood" };
	queries.findQueryValue(dt.getTreeRoot(), car2, result);
	assert(result == "vgood");

}
