#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include "Node.h"
using namespace std;

class TableControler
{
public:
	/*
	Returns a list:
	Removes each row from a list containing a specific Property of a given Feature
	@param node A node containing the list
	@param carFeature The Feature of the car
	@param carProperty The Property of the car
	*/
	vector<Car> filterProperty(Node*, string carFeature, string carProperty);

	/*
	Returns a list:
	Removes the column coresponding to a given Feature
	@param node A node containing the list
	@param carFeature The Feature of the car
	*/
	vector<Car>& removeFeature(Node*, string carFeature);

	/*
	Returns an integer:
	Searches for a given Feature in a list and returns its position
	@param node A node containing the list
	@param carFeature The Feature of the car
	*/
	int getFeatureIndex(Node* node, string carFeature);
};

