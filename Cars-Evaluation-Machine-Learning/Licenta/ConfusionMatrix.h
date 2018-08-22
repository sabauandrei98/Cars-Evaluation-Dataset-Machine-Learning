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
	ConfusionMatrix(vector<pair<int,int>>& queriesResults);
	void printConfusionMatrix();
};

