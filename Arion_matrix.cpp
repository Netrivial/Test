#include <iostream>
#include <vector>
	
#include "Arion_matrix.hpp"
#include "Arion_const.hpp"



void SumMatrix(Matrix_x& matrix_main, Matrix_x help_matrix)
{
	setlocale(LC_ALL, "Russian");

	if (matrix_main.size_x != help_matrix.size_x)
	{
		cout << "Векторы разных размеров!" << endl << endl;
		return;
	}

	for (int i = 0; i < matrix_main.size_x; i++)	
	{
			matrix_main.matrix[i] = matrix_main.matrix[i] + help_matrix.matrix[i];
	}
}

void SumMatrix(Matrix_xy& matrix_main, Matrix_xy help_matrix)
{
	setlocale(LC_ALL, "Russian");

	if (matrix_main.size_y != help_matrix.size_y || matrix_main.size_x != help_matrix.size_x)
	{
		cout << "Матрицы разных размеров!" << endl << endl;
		return;
	}

	for (int i = 0; i < matrix_main.size_y; i++)
	{
		for (int j = 0; j < matrix_main.size_x; j++)
		{
			matrix_main.matrix[i][j] = matrix_main.matrix[i][j] + help_matrix.matrix[i][j] ;
		}
	}
}



void MinusMatrix(Matrix_x& matrix_main, Matrix_x help_matrix)
{
	setlocale(LC_ALL, "Russian");

	if (matrix_main.size_x != help_matrix.size_x)
	{
		cout << "Невозможно произвести разность данных векторов!" << endl << endl;
		return;
	}

	for (int i = 0; i < matrix_main.size_x; i++)
		{
			matrix_main.matrix[i] = matrix_main.matrix[i] - help_matrix.matrix[i];
		}
}

void MinusMatrix(Matrix_xy& matrix_main, Matrix_xy help_matrix)
{
	setlocale(LC_ALL, "Russian");

	if (matrix_main.size_y != help_matrix.size_y || matrix_main.size_x != help_matrix.size_x)
	{
		cout << "Невозможно произвести разность данных матриц!" << endl << endl;
	}
		
	for (int i = 0; i < matrix_main.size_y; i++)
	{
		for (int j = 0; j < matrix_main.size_x; j++)
		{
			matrix_main.matrix[i][j] = matrix_main.matrix[i][j] - help_matrix.matrix[i][j];
		}
	}
}



void MultiplicationMatrix(Matrix_x& matrix_main, double value)
{
	for (int i = 0; i < matrix_main.size_x; i++) {
		matrix_main.matrix[i] = matrix_main.matrix[i] * value;
	}
}

void MultiplicationMatrix(Matrix_xy& matrix_main, double value)
{
	for (int i = 0; i < matrix_main.size_y; i++)
	{
		for (int j = 0; j < matrix_main.size_x; j++)
		{
			matrix_main.matrix[i][j] = matrix_main.matrix[i][j] * value;
		}
	}
}

Matrix_xy MultiplicationMatrix(Matrix_x matrix_main, Matrix_x help_matrix)
{
	Matrix_xy matrix(matrix_main.size_x, help_matrix.size_x);

	setlocale(LC_ALL, "Russian");

	if (matrix_main.mode == help_matrix.mode)
	{
		cout << "Такие векторы не могут быть умножены!" << endl << endl;
	}
	else if (matrix_main.size_x != help_matrix.size_x)
	{
		cout << "Такие векторы не могут быть умножены!" << endl << endl;
	}
	else if (matrix_main.mode == "column")
	{
		for (int i = 0; i < matrix_main.size_x; i++)
		{
			for (int j = 0; j < matrix_main.size_x; j++)
			{
				matrix.matrix[i][j] = matrix_main.matrix[i] * help_matrix.matrix[j];
			}
		}

		return matrix;
	}
	else
	{
		for (int i = 0; i < matrix_main.size_x; i++)
		{
			for (int j = 0; j < matrix_main.size_x; j++)
			{
				matrix.matrix[i][j] = matrix_main.matrix[j] * help_matrix.matrix[i];
			}
		}

		return matrix;
	}
}

Matrix_x MultiplicationMatrix(Matrix_x matrix_main, Matrix_xy help_matrix)
{
	Matrix_x matrix(help_matrix.size_y, "column");

	setlocale(LC_ALL, "Russian");

	if (matrix_main.size_x != help_matrix.size_x)
	{
		cout << "Невозможно умножить такой вектор на матрицу!" << endl << endl;
	}
	else if (matrix_main.mode != "column")
	{
		cout << "Вектор должен быть вектором-столбцом!" << endl << endl;
	}
	else
	{
		for (int i = 0; i < help_matrix.size_y; i++)
		{
			for (int j = 0; j < help_matrix.size_x; j++)
			{
				matrix.matrix[i] = matrix.matrix[i] + matrix_main.matrix[j] * help_matrix.matrix[i][j];
			}
		}

		return matrix;
	}
}

Matrix_xy MultiplicationMatrix(Matrix_xy matrix_main, Matrix_xy help_matrix)
{
	setlocale(LC_ALL, "Russian");

	if (matrix_main.size_x != help_matrix.size_y)
	{
		cout << "Матрицы разных размеров!" << endl << endl;
	}
	else if (matrix_main.size_x == help_matrix.size_y)
	{
		Matrix_xy matrix(matrix_main.size_y, help_matrix.size_x);

		for (int i = 0; i < matrix_main.size_y; i++)
		{
			for (int j = 0; j < help_matrix.size_x; j++)
			{
				for (int k = 0; k < matrix_main.size_x; k++)
				{
					matrix.matrix[i][j] = matrix.matrix[i][j] + matrix_main.matrix[i][k] * help_matrix.matrix[k][j];

				}
			}
		}

		return matrix;
	}
}



void DivisionMatrix(Matrix_x& matrix, double value)
{
	setlocale(LC_ALL, "Russian");
	if (value == 0)
	{
		cout << "На ноль делить нельзя!" << endl << endl;
	}

	else
	{
		for (int i = 0; i < matrix.size_x; i++)
		{
			matrix.matrix[i] = matrix.matrix[i] / value;
		}
	}
}

void DivisionMatrix(Matrix_xy& matrix, double value)
{
	setlocale(LC_ALL, "Russian");
	
	if (value == 0)
	{
		cout << "На ноль делить нельзя!" << endl << endl;
	}
	else
	{
		for (int i = 0; i < matrix.size_y; i++)
		{
			for (int j = 0; j < matrix.size_x; j++)
			{
				matrix.matrix[i][j] = matrix.matrix[i][j] / value;
			}
		}
	}
}
