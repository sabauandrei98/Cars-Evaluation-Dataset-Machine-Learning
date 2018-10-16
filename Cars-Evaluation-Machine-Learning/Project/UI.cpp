#include "UI.h"

UI::UI()
{
	runUI();
}

void UI::printMenu()
{
	cout << "\nWelcome to the application !\n";
	cout << "~ Type 0 to exit\n";
	cout << "~ Choose a learning percent between 1 and 99:\n";
	cout << ">> ";
}

void UI::runUI()
{
	Tools tools;

	bool application_exit = false;
	while (!application_exit)
	{
		printMenu();
		int learningPercent = 0;
		bool goodPercent = false;

		string line;
		cin >> line;
		while (!goodPercent)
		{
			goodPercent = tools.tryParse(line, learningPercent);
			if (goodPercent)
				if (learningPercent < 1 || learningPercent > 99)
				{
					goodPercent = false;

					if (learningPercent == 0)
						return;
				}

			if (goodPercent)
				break;

			cout << "Incorrect input !\n>>";
			cin >> line;
		}

		runCase(learningPercent);
	}
}

void UI::runCase(int learningPercent)
{
	DataBase db{ "data.txt", learningPercent };
	DecisionTree dt{ db.getLearningSet(), db.getFeatureSet() };
	Queries queries{ db.getQueriesSet(), dt.getTreeRoot() };
	ConfusionMatrix confusionMatrix{ queries.getQueriesResult() };
}
