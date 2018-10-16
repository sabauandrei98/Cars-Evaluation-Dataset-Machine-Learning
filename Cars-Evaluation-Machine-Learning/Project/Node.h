#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include "Car.h"

using namespace std;

class Node
{
public:
	//Dominant carFeature of this node
	string carFeature;

	//Dominant carProperty of this node
	string carProperty;

	//True, if the carFeature and carProperty gave the best information
	//In the Information Gain process
	bool dominantProperty = false;

	//A pair of double and string which represents a percent and a final value
	//Eg: (80, "unacc")
	//This means that we are 80% sure that this car is "unacc"
	pair<double, string> similarityInfo = make_pair(0, "");

	//Table of remaining cars after:
	//Cutting carFeature column
	//Cutting carProperty rows
	vector<Car> cars;

	//Remaining features
	vector<string> features;

	//List of pointers to the next nodes in the Decision Tree
	vector<Node*> next;
};

