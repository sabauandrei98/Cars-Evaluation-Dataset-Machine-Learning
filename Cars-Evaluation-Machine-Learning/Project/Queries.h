#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include "Node.h"
#include "Tools.h"
#include "TableControler.h"
using namespace std;

class Queries
{
private:
	//The set containing the queries
	vector<Car> queriesSet;

	//Pointer to the root of the tree
	Node* root;

	//Pairs of the form:
	// (treeResultValue, queryValue) 
	vector<pair<int, int>> queriesResults;
	
public:
	Queries(vector<Car>& q, Node* treeRoot) : queriesSet(q), root(treeRoot) { runQueries(); };

	/*
	Take each Query and check it
	*/
	void runQueries();

	/*
	Search the value of a query in Decision Tree
	@param node Searching start point
	@param query Query to find
	@param result The information found
	*/
	void findQueryValue(Node* node, Car& query, string& result);

	vector<pair<int, int>>& getQueriesResult() { return queriesResults; }
};

