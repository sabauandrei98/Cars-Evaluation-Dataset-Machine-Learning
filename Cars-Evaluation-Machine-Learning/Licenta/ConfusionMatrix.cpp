#include "ConfusionMatrix.h"

ConfusionMatrix::ConfusionMatrix(vector<pair<int, int>>& queriesResults)
{
	///CONSOLE LOG INFO
	cout << endl << endl << "===CONFUSION MATRIX===" << endl;

	for (int index = 0; index < queriesResults.size(); index++)
		matrix[queriesResults[index].first][queriesResults[index].second]++;

	printConfusionMatrix();
}

void ConfusionMatrix::printConfusionMatrix()
{
	for (int row = 1; row <= 4; row++)
	{
		for (int col = 1; col <= 4; col++)
		{
			int aux = max(matrix[row][col], 1);
			int sz = 0;
			while (aux)
			{
				aux /= 10;
				sz++;
			}
			for (int i = 1; i <= (3 - sz); i++)
				cout << " ";
			cout << matrix[row][col] << " | ";
		}
		cout << endl;
	}
}

