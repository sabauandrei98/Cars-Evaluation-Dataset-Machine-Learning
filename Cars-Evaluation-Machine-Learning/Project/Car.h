#pragma once

#include <iostream>
#include <string>
#include "Tools.h"
using namespace std;

class Car
{
public:
	//A list of 7 integers: 
	//6 integers - each representing a property for a feature
	//1 integer - representing the final value of the car
	vector<int> carProperty;

	//Constructor which gets the a specific set of properties and adds them
	//to the carProperty list as integers
	Car(string b, string m, string d, string p, string l, string s, string v)
	{
		Tools tools;
		carProperty.push_back(tools.getBuyingToInt(b));
		carProperty.push_back(tools.getMainToInt(m));
		carProperty.push_back(tools.getDoorsToInt(d));
		carProperty.push_back(tools.getPersonsToInt(p));
		carProperty.push_back(tools.getLug_bootToInt(l));
		carProperty.push_back(tools.getSafetyToInt(s));
		carProperty.push_back(tools.getValueToInt(v));
	}
};

