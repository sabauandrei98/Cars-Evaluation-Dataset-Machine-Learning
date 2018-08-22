#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>
#include <random>
using namespace std;

class Tools
{
public:
	/*
	Gets a line from file and splits it according to the delimiter, returning a list of items
	@param str A string containing the line
	@param delimiter A char delimiter
	*/
	vector<string> tokenize(string str, char delimiter);

	/* String property to integer */
	int getBuyingToInt(string b);

	/* String property to integer */
	int getMainToInt(string m);

	/* String property to integer */
	int getDoorsToInt(string d);

	/* String property to integer */
	int getPersonsToInt(string p);

	/* String property to integer */
	int getLug_bootToInt(string l);

	/* String property to integer */
	int getSafetyToInt(string s);

	/* String property to integer */
	int getValueToInt(string v);

	/* Integer property to string */
	string getBuyingToString(int b);

	/* Integer property to string */
	string getMainToString(int m);

	/* Integer property to string */
	string getDoorsToString(int d);

	/* Integer property to string */
	string getPersonsToString(int p);

	/* Integer property to string */
	string getLug_bootToString(int l);

	/* Integer property to string */
	string getSafetyToString(int s);

	/* Integer property to string */
	string getValueToString(int v);

	/*
	Returns an integer for a given Feature and Property
	@param carFeature The Feature of the car
	@param propertyValue The Property of the car

	Eg: getFeatureProperty("safety", "low") => 1
	*/
	int getFeatureProperty(string carFeature, string propertyValue);

	/*
	Returns an integer for a given Feature
	@param feature The Feature of the car

	Eg: initialFeatureIndex("buying") => 0
	initialFeatureIndex("safety") => 5
	*/
	int initialFeatureIndex(string feature);

	/*
	Returns a string for a given Feature and Property
	@param carFeature The Feature of the car
	@param propertyValue The Property of the car

	Eg: getFeatureProperty("safety", 1) => "low"
	*/
	string getFeatureProperty(string carFeature, int propertyValue);

	/*
	Shuffle a container
	@param first Iterator pointing to first element
	@param last Iterator pointing to last element
	@param g Random Engine
	*/
	template <class RandomAccessIterator, class URNG>
	void shuffle(RandomAccessIterator first, RandomAccessIterator last, URNG&& g)
	{
		for (auto i = (last - first) - 1; i>0; --i) {
			std::uniform_int_distribution<decltype(i)> d(0, i);
			swap(first[i], first[d(g)]);
		}
	}

	/*
	Shuffle a container
	@param list The list
	*/
	template <class Item>
	void shuffleVector(vector<Item>& list)
	{
		srand(time(NULL));
		unsigned seed = chrono::system_clock::now().time_since_epoch().count();
		shuffle(list.begin(), list.end(), default_random_engine(seed));
	}

	/*
	Returns the number of "true" values in a list of bools
	@param values List of bools
	*/
	int trueValues(vector<bool>& values);
};



