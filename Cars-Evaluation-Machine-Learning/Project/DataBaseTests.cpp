#include "DataBaseTests.h"

DataBaseTests::DataBaseTests()
{
	dataBaseTests();
}

void DataBaseTests::dataBaseTests()
{
	DataBase db{ "data.txt", 80 };
	assert(db.getFeatureSet().size() == 7);
	assert(db.getLearningSet().size() == 1382);
	assert(db.getQueriesSet().size() == 346);
}
