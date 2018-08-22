#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ConfusionMatrix
{
private:
	int matrix[5][5] = { 0 };

public:
	/*
	Builds a matrix according to queriesResults list
	@param queriesResults A list with information about the queries
	*/
	ConfusionMatrix(vector<pair<int,int>>& queriesResults);

	/*
	Prints the created matrix
	*/
	void printConfusionMatrix();
};

