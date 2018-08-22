#include "ConfusionMatrix.h"

ConfusionMatrix::ConfusionMatrix(vector<pair<int, int>>& queriesResults)
{
	///CONSOLE LOG INFO
	cout <<"\n\n===CONFUSION MATRIX===\n";

	for (int index = 0; index < queriesResults.size(); index++)
		matrix[queriesResults[index].first][queriesResults[index].second]++;

	printConfusionMatrix();
}

void ConfusionMatrix::printConfusionMatrix()
{
	int confusionMatrixRows = 4;
	int confusionMatrixColumns = 4;
	int emptySpacesSize = 3;

	for (int row = 1; row <= confusionMatrixRows; row++)
	{
		for (int col = 1; col <= confusionMatrixColumns; col++)
		{
			int matrixElement = max(matrix[row][col], 1);
			int matrixElementSize = 0;
			while (matrixElement)
			{
				matrixElement /= 10;
				matrixElementSize++;
			}
			for (int i = 1; i <= (emptySpacesSize - matrixElementSize); i++)
				cout << " ";
			cout << matrix[row][col] << " | ";
		}
		cout << '\n';
	}
}

