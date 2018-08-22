#pragma once
#include "DataBase.h"
#include "DecisionTree.h"
#include "Queries.h"
#include "ConfusionMatrix.h"
#include "Tools.h"

class UI
{
public:
	UI();

	/*
	Handles the interaction between user and ui
	*/
	void runUI();

	/*
	Creates a scenario according to the Learning Percent
	@param learningPercent The learning percent
	*/
	void runCase(int learningPercent);

	/*
	Prints a user friendly interface for the user
	*/
	void printMenu();
};

