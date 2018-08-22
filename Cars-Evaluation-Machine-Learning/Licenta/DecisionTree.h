#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include "Node.h"
#include "TableControler.h"
using namespace std;

#define minSimilarityPercent 90
#define minPropertyVal 1
#define maxPropertyVal 4

class DecisionTree
{
private:
	//Pointer to the root of the tree
	Node* root;

public:
	/*
	Class constructor, creates the root of the tree and starts to build it
	@param learning The learning set
	@param feature The feature set
	*/
	DecisionTree(vector<Car>& learning, vector<string>& feature);

	/*
	The main function of the class, generates recursively a tree node
	@param node Pointer to current node
	@param path Path from the root to the current node
	*/
	void buildTree(Node* node, string path);

	/*
	Returns pointer to the tree root
	*/
	Node* getTreeRoot() { return this->root; }

	/*
	Returns double: the entropy for a given Feature and Property
	@param table The set operation will be performed on
	@param carFeatureIndex Index of the Feature
	@param carProperty Value of the Property
	*/
	double calculatePropertyEntropy(vector<Car>& table, int carFeatureIndex, int carProperty);

	/*
	Returns double: the entropy for a given Feature
	@param table The set operation will be performed on
	@param carFeatureIndex Index of the Feature
	*/
	double calculateFeatureEntropy(vector<Car>& table, int carFeatureIndex);

	/*
	Returns string: the best entropy property for a given Node and Feature
	@param node The Node operation will be performed on
	@param carFeature Index of the Feature
	*/
	string bestEntropyProperty(Node* node, string carFeature);

	/*
	Returns string: the best entropy feature for a given Node
	@param node The Node operation will be performed on
	*/
	string bestEntropyFeature(Node* node);

	/*
	Returns a pair of double and string which represents a percent and a final value
	@param node The Node operation will be performed on
	@param carFeature The feature of the car
	@param carProperty The property of the car
	Eg: (80, "unacc")
	This means that we are 80% sure that this car is "unacc"
	*/
	pair<double, string> getMaxSimilarityInfo(Node* node, string carFeature, string carProperty);
};

