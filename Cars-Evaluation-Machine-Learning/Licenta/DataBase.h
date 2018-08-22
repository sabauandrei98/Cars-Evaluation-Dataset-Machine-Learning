#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Car.h"
#include "Tools.h"
using namespace std;

class DataBase
{
private:
	//All records from the file
	vector<Car> dataBase;
	
	//The set learning will be performed on
	vector<Car> learningSet;
	
	//The set queries will be performed on
	vector<Car> queriesSet;

	//The list of features for carsDataSet
	vector<string> featureSet{ "buying", "main", "doors", "persons", "lug_boot", "safety", "value" };

	//The file of the name information will be get from
	string fileName;

	//Percent indicating the size of the learning set
	//Eg: learningPercent = 60%
	//learningSet = 60% of dataBase
	//queriesSet = 40% of database
	int learningPercent;

public:
	/*
	Class constructor, gets the information from file and splits the it into two sets
	@param file The name of the file
	@param learning The learning percentage
	*/
	DataBase(string file, int learning);

	/*
	Gets information from the file and sends it to dataBase vector
	*/
	void getFromFile();

	/*
	Splits information into learningSet and queriesSet according to the learningPercent
	*/
	void splitDataBaseIntoSets();

	/*
	Returns a reference to the learningSet
	*/
	vector<Car>& getLearningSet() { return this->learningSet; }

	/*
	Returns a reference to the queriesSet
	*/
	vector<Car>& getQueriesSet() { return this->queriesSet; }

	/*
	Returns a reference to the featureSet
	*/
	vector<string>& getFeatureSet() { return this->featureSet; }
};

