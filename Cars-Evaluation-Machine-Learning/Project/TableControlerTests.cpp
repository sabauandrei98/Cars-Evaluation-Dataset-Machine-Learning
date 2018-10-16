#include "TableControlerTests.h"

TableControlerTests::TableControlerTests()
{
	filterPropertyTests();
	removeFeatureTests();
	getFeatureIndexTests();
}

void TableControlerTests::filterPropertyTests()
{
	TableControler tableControler;
	DataBase db{ "data.txt", 100 };
	Node* node = new Node;
	node->cars = db.getLearningSet();
	node->features = db.getFeatureSet();
	assert(node->cars.size() == 1728);
	node->cars = tableControler.filterProperty(node, "safety", "low");
	assert(node->cars.size() == 576);
	node->cars = tableControler.filterProperty(node, "persons", "2");
	assert(node->cars.size() == 192);
	delete node;
}

void TableControlerTests::removeFeatureTests()
{
	TableControler tableControler;
	DataBase db{ "data.txt", 100 };
	Node* node = new Node;
	node->cars = db.getLearningSet();
	node->features = db.getFeatureSet();
	node->cars = tableControler.removeFeature(node, "safety");
	assert(node->cars[0].carProperty.size() == 6);
	node->cars = tableControler.removeFeature(node, "persons");
	assert(node->cars[0].carProperty.size() == 5);
	node->cars = tableControler.removeFeature(node, "main");
	assert(node->cars[0].carProperty.size() == 4);
	delete node;
}

void TableControlerTests::getFeatureIndexTests()
{
	TableControler tableControler;
	DataBase db{ "data.txt", 100 };
	Node* node = new Node;
	node->cars = db.getLearningSet();
	node->features = { "safety", "buying", "main" };
	assert(tableControler.getFeatureIndex(node, "safety") == 0);
	assert(tableControler.getFeatureIndex(node, "buying") == 1);
	assert(tableControler.getFeatureIndex(node, "main") == 2);
	assert(tableControler.getFeatureIndex(node, "ddasasd") == -1);
	delete node;
}
