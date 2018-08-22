#include "Tools.h"

vector<string> Tools::tokenize(string str, char delimiter)
{
	vector <string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}

bool Tools::tryParse(string& input, int& output) {
	try {
		output = stoi(input);
	}
	catch (std::invalid_argument) {
		return false;
	}
	return true;
}

int Tools::initialFeatureIndex(string feature)
{
	if (feature == "buying")
		return 0;
	if (feature == "main")
		return 1;
	if (feature == "doors")
		return 2;
	if (feature == "persons")
		return 3;
	if (feature == "lug_boot")
		return 4;
	if (feature == "safety")
		return 5;
	if (feature == "value")
		return 6;
}

int Tools::trueValues(vector<bool>& values)
{
	int val = 0;
	for (int i = 0; i < values.size(); i++)
		if (values[i])
			val++;
	return val;
}

int Tools::getFeatureProperty(string carFeature, string propertyValue)
{
	if (carFeature == "buying")
		return getBuyingToInt(propertyValue);
	if (carFeature == "main")
		return getMainToInt(propertyValue);
	if (carFeature == "doors")
		return getDoorsToInt(propertyValue);
	if (carFeature == "persons")
		return getPersonsToInt(propertyValue);
	if (carFeature == "lug_boot")
		return getLug_bootToInt(propertyValue);
	if (carFeature == "safety")
		return getSafetyToInt(propertyValue);
	if (carFeature == "value")
		return getValueToInt(propertyValue);

	return -1;
}

string Tools::getFeatureProperty(string carFeature, int propertyValue)
{
	if (carFeature == "buying")
		return getBuyingToString(propertyValue);
	if (carFeature == "main")
		return getMainToString(propertyValue);
	if (carFeature == "doors")
		return getDoorsToString(propertyValue);
	if (carFeature == "persons")
		return getPersonsToString(propertyValue);
	if (carFeature == "lug_boot")
		return getLug_bootToString(propertyValue);
	if (carFeature == "safety")
		return getSafetyToString(propertyValue);
	if (carFeature == "value")
		return getValueToString(propertyValue);

	return "null";
}

int Tools::getBuyingToInt(string b)
{
	if (b == "vhigh")
		return 1;
	if (b == "high")
		return 2;
	if (b == "med")
		return 3;
	if (b == "low")
		return 4;

	return -1;
}

int Tools::getMainToInt(string m)
{
	if (m == "vhigh")
		return 1;
	if (m == "high")
		return 2;
	if (m == "med")
		return 3;
	if (m == "low")
		return 4;

	return -1;
}

int Tools::getDoorsToInt(string d)
{
	if (d == "2")
		return 1;
	if (d == "3")
		return 2;
	if (d == "4")
		return 3;
	if (d == "5more")
		return 4;

	return -1;
}

int Tools::getPersonsToInt(string p)
{
	if (p == "2")
		return 1;
	if (p == "4")
		return 2;
	if (p == "more")
		return 3;

	return -1;
}

int Tools::getLug_bootToInt(string l)
{
	if (l == "small")
		return 1;
	if (l == "med")
		return 2;
	if (l == "big")
		return 3;

	return -1;
}

int Tools::getSafetyToInt(string s)
{
	if (s == "low")
		return 1;
	if (s == "med")
		return 2;
	if (s == "high")
		return 3;

	return -1;
}

int Tools::getValueToInt(string v)
{
	if (v == "unacc")
		return 1;
	if (v == "acc")
		return 2;
	if (v == "good")
		return 3;
	if (v == "vgood")
		return 4;

	return -1;
}

string Tools::getBuyingToString(int b)
{
	if (b == 1)
		return "vhigh";
	if (b == 2)
		return "high";
	if (b == 3)
		return "med";
	if (b == 4)
		return "low";

	return "null";
}

string Tools::getMainToString(int m)
{
	if (m == 1)
		return "vhigh";
	if (m == 2)
		return "high";
	if (m == 3)
		return "med";
	if (m == 4)
		return "low";

	return "null";
}

string Tools::getDoorsToString(int d)
{
	if (d == 1)
		return "2";
	if (d == 2)
		return "3";
	if (d == 3)
		return "4";
	if (d == 4)
		return "5more";

	return "null";
}

string Tools::getPersonsToString(int p)
{
	if (p == 1)
		return "2";
	if (p == 2)
		return "4";
	if (p == 3)
		return "more";

	return "null";
}

string Tools::getLug_bootToString(int l)
{
	if (l == 1)
		return "small";
	if (l == 2)
		return "med";
	if (l == 3)
		return "big";

	return "null";
}

string Tools::getSafetyToString(int s)
{
	if (s == 1)
		return "low";
	if (s == 2)
		return "med";
	if (s == 3)
		return "high";

	return "null";
}

string Tools::getValueToString(int v)
{
	if (v == 1)
		return "unacc";
	if (v == 2)
		return "acc";
	if (v == 3)
		return "good";
	if (v == 4)
		return "vgood";

	return "null";
}

