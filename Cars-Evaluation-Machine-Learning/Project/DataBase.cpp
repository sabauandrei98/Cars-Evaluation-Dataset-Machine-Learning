#include "DataBase.h"

DataBase::DataBase(string file, int learning) : fileName(file), learningPercent(learning)
{
	this->getFromFile();
	this->splitDataBaseIntoSets();
}

void DataBase::splitDataBaseIntoSets()
{
	int learningSetSize = this->dataBase.size() * this->learningPercent / 100;

	Tools tools;
	tools.shuffleVector(this->dataBase);

	for (int setIndex = 0; setIndex < learningSetSize; setIndex++)
		learningSet.push_back(dataBase[setIndex]);

	for (int setIndex = learningSetSize; setIndex < this->dataBase.size(); setIndex++)
		queriesSet.push_back(dataBase[setIndex - learningSetSize]);
}

void DataBase::getFromFile()
{
	ifstream f(this->fileName);

	while (!f.eof())
	{
		string line;
		getline(f, line);
		Tools tools = Tools();

		vector<string> row = tools.tokenize(line, ',');
		Car car{ row[0], row[1], row[2], row[3], row[4], row[5], row[6] };
		this->dataBase.push_back(car);
	}
}