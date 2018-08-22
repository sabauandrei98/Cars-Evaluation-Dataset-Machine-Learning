#include "ToolsTests.h"

ToolsTests::ToolsTests()
{
	tokenizeTests();
	stringToIntegerTests();
	integerToStringTests();
	initialFeatureIndexTests();
	getFeaturePropertyTests();
	trueValuesTests();
	shuffleVectorTests();
}

void ToolsTests::tokenizeTests()
{
	vector<string> result = tools.tokenize("ana,are,mere", ',');
	assert(result[0] == "ana");
	assert(result[1] == "are");
	assert(result[2] == "mere");
}

void ToolsTests::stringToIntegerTests()
{
	assert(tools.getBuyingToInt("vhigh") == 1);
	assert(tools.getBuyingToInt("high") == 2);
	assert(tools.getBuyingToInt("med") == 3);
	assert(tools.getBuyingToInt("low") == 4);
	assert(tools.getBuyingToInt("aaa") == -1);

	assert(tools.getMainToInt("vhigh") == 1);
	assert(tools.getMainToInt("high") == 2);
	assert(tools.getMainToInt("med") == 3);
	assert(tools.getMainToInt("low") == 4);
	assert(tools.getMainToInt("aaa") == -1);

	assert(tools.getDoorsToInt("2") == 1);
	assert(tools.getDoorsToInt("3") == 2);
	assert(tools.getDoorsToInt("4") == 3);
	assert(tools.getDoorsToInt("5more") == 4);
	assert(tools.getDoorsToInt("aaa") == -1);

	assert(tools.getPersonsToInt("2") == 1);
	assert(tools.getPersonsToInt("4") == 2);
	assert(tools.getPersonsToInt("more") == 3);
	assert(tools.getPersonsToInt("aaa") == -1);

	assert(tools.getLug_bootToInt("small") == 1);
	assert(tools.getLug_bootToInt("med") == 2);
	assert(tools.getLug_bootToInt("big") == 3);
	assert(tools.getLug_bootToInt("aaa") == -1);

	assert(tools.getSafetyToInt("low") == 1);
	assert(tools.getSafetyToInt("med") == 2);
	assert(tools.getSafetyToInt("high") == 3);
	assert(tools.getSafetyToInt("aaa") == -1);

	assert(tools.getValueToInt("unacc") == 1);
	assert(tools.getValueToInt("acc") == 2);
	assert(tools.getValueToInt("good") == 3);
	assert(tools.getValueToInt("vgood") == 4);
	assert(tools.getValueToInt("aaa") == -1);
}

void ToolsTests::integerToStringTests()
{
	assert(tools.getBuyingToString(1) == "vhigh");
	assert(tools.getBuyingToString(2) == "high");
	assert(tools.getBuyingToString(3) == "med");
	assert(tools.getBuyingToString(4) == "low");
	assert(tools.getBuyingToString(-1) == "null");

	assert(tools.getMainToString(1) == "vhigh");
	assert(tools.getMainToString(2) == "high");
	assert(tools.getMainToString(3) == "med");
	assert(tools.getMainToString(4) == "low");
	assert(tools.getMainToString(-1) == "null");

	assert(tools.getDoorsToString(1) == "2");
	assert(tools.getDoorsToString(2) == "3");
	assert(tools.getDoorsToString(3) == "4");
	assert(tools.getDoorsToString(4) == "5more");
	assert(tools.getDoorsToString(-1) == "null");

	assert(tools.getPersonsToString(1) == "2");
	assert(tools.getPersonsToString(2) == "4");
	assert(tools.getPersonsToString(3) == "more");
	assert(tools.getPersonsToString(-1) == "null");

	assert(tools.getLug_bootToString(1) == "small");
	assert(tools.getLug_bootToString(2) == "med");
	assert(tools.getLug_bootToString(3) == "big");
	assert(tools.getLug_bootToString(-1) == "null");

	assert(tools.getSafetyToString(1) == "low");
	assert(tools.getSafetyToString(2) == "med");
	assert(tools.getSafetyToString(3) == "high");
	assert(tools.getSafetyToString(-1) == "null");

	assert(tools.getValueToString(1) == "unacc");
	assert(tools.getValueToString(2) == "acc");
	assert(tools.getValueToString(3) == "good");
	assert(tools.getValueToString(4) == "vgood");
	assert(tools.getValueToString(-1) == "null");
}

void ToolsTests::initialFeatureIndexTests()
{
	assert(tools.initialFeatureIndex("buying") == 0);
	assert(tools.initialFeatureIndex("main") == 1);
	assert(tools.initialFeatureIndex("doors") == 2);
	assert(tools.initialFeatureIndex("persons") == 3);
	assert(tools.initialFeatureIndex("lug_boot") == 4);
	assert(tools.initialFeatureIndex("safety") == 5);
	assert(tools.initialFeatureIndex("value") == 6);
}

void ToolsTests::getFeaturePropertyTests()
{
	assert(tools.getFeatureProperty("buying", 1) == "vhigh");
	assert(tools.getFeatureProperty("main", 1) == "vhigh");
	assert(tools.getFeatureProperty("doors", 1) == "2");
	assert(tools.getFeatureProperty("persons", 1) == "2");
	assert(tools.getFeatureProperty("lug_boot", 1) == "small");
	assert(tools.getFeatureProperty("safety", 1) == "low");
	assert(tools.getFeatureProperty("value", 1) == "unacc");
	assert(tools.getFeatureProperty("aaaa", 1) == "null");

	assert(tools.getFeatureProperty("buying", "vhigh") == 1);
	assert(tools.getFeatureProperty("main", "vhigh") == 1);
	assert(tools.getFeatureProperty("doors", "2") == 1);
	assert(tools.getFeatureProperty("persons", "2") == 1);
	assert(tools.getFeatureProperty("lug_boot", "small") == 1);
	assert(tools.getFeatureProperty("safety", "low") == 1);
	assert(tools.getFeatureProperty("value", "unacc") == 1);
	assert(tools.getFeatureProperty("aaaa", "unacc") == -1);
}

void ToolsTests::trueValuesTests()
{
	vector<bool> list;
	list.push_back(false);
	assert(tools.trueValues(list) == 0);
	list.push_back(true);
	assert(tools.trueValues(list) == 1);
	list.push_back(false);
	assert(tools.trueValues(list) == 1);
	list.push_back(true);
	assert(tools.trueValues(list) == 2);
}

void ToolsTests::shuffleVectorTests()
{
	vector<int> list;
	for (int i = 0; i < 100; i++)
		list.push_back(i);

	int numberOfTests = 10;
	for (int i = 0; i < numberOfTests; i++)
	{
		tools.shuffleVector(list);
		bool ok = true;
		for (int j = 0; j < list.size(); j++)
			if (list[j] != j)
				ok = false;

		if (ok)
			assert(false);
	}
	assert(true);
}

