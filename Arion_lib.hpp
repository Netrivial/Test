#pragma once

//		    ______              ______________       ______        ______________       ____ ___       ______
//         /    \ \            |   _____   \__\     |    | |      /           \  \     |     \  \     |    | |
//        /      \ \		   |  | |   |  |  |     |    | |     /    _____    \__\    |      \  \    |    | |
//       /   /\   \ \		   |  | |   |  |  |     |    | |    |    | |   |    |  |   |    |\ \  \   |    | |
//      /   / /\   \ \		   |  |_|___|  |__|     |    | |    |    | |   |    |  |   |    | \ \  \  |    | |
//     /   /_/__\   \ \		   |   ____   /__/      |    | |    |    | |   |    |  |   |    | |\ \  \ |    | |
//    /   ________   \ \	   |  | |  \  \ \       |    | |    |    | |___|    |  |   |    | | \ \  \|    | |
//   /   / /      \   \ \	   |  | |   \  \ \      |    | |    |    |/____|    |__|   |    | |  \ \__|    | |
//  /   / /        \   \ \     |  | |    \  \ \     |    | |     \             /  /    |    | |   \        | |
// /___/_/          \___\_\    |__|_|     \__\_\    |____|_|      \___________/__/     |____|_|    \_______|_|


#include <vector>
#include <random>
#include <ctime>

#include "const_math_lib.hpp"

using namespace std;



class Matrix_x
{
	public:
		Matrix_x() : size_x(max_x), matrix(max_x), mode("row")
		{
			for (int i = 0; i < size_x; i++)
			{
				matrix[i] = 0;
			}	
		}

		Matrix_x(int _size_x, string _mode = "row") : size_x(_size_x), matrix(_size_x), mode(_mode)
		{
			for (int i = 0; i < size_x; i++)
			{
				matrix[i] = 0;
			}
		}

		void matrix_rand()
		{
			srand(time(nullptr));

			for (int i = 0; i < size_x; i++)
			{
				matrix[i] = rand() % 10;
			}
		}

		void show_matrix()
		{
			if (mode == "row")
			{
				for (int i = 0; i < size_x; i++)
				{
					cout << matrix[i] << " ";
				}
				cout << endl << endl;
			}
			else if(mode == "column")
			{
				for (int i = 0; i < size_x; i++)
				{
					cout << matrix[i] << endl;
				}

				cout << endl;
			}
		}

		void transporation()
		{
			if (mode == "row")
			{
				mode = "column";
			}
			else
			{
				mode = "row";
			}
		}

		int size_x;
		vector <double> matrix;
		string mode;
};

class Matrix_xy
{
	public:
		Matrix_xy() : size_x(max_x), size_y(max_y), matrix(max_y, vector <double>(max_x))
		{
			for (int i = 0; i < size_y; i++)
			{
				vector <double> temp;
				for (int j = 0; j < size_x; j++)
				{
					temp.push_back(0);
				}
				matrix.push_back(temp);
			}
		}

		Matrix_xy(int _size_y, int _size_x) : size_x(_size_x), size_y(_size_y), matrix(_size_y, vector <double>(_size_x))
		{
			for (int i = 0; i < size_y; i++)
			{
				vector <double> temp;
				for (int j = 0; j < size_x; j++)
				{
					temp.push_back(0);
				}
				matrix.push_back(temp);
			}
		}


		void matrix_rand()
		{
			srand(time(nullptr));

			for (int i = 0; i < size_y; i++)
			{
				for (int j = 0; j < size_x; j++)
				{
					matrix[i][j] = rand() % 10;
				}
			}
		}

		void show_matrix()
		{
			for (int i = 0; i < size_y; i++)
			{
				for (int j = 0; j < size_x; j++)
				{
					cout << matrix[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}

		void transporation()
		{
			vector <vector <double>> help_vec(size_x, vector <double>(size_y));

			for (int i = 0; i < size_x; i++)
			{
				for (int j = 0; j < size_y; j++)
				{
					help_vec[i][j] = matrix[j][i];
				}
			}

			matrix.resize(size_x);
			matrix[0].resize(size_y);
			matrix = help_vec;

			size_x = matrix[0].size();
			size_y = matrix.size();
		}

		double Determinant(Matrix_xy matrix)
		{
			setlocale(LC_ALL, "Russian");

			Matrix_xy help_matrix(matrix.size_x - 1, matrix.size_x - 1);
			help_matrix.copy_size = matrix.copy_size -= 1;
			matrix.copy_size = matrix.size_y;

			double det = 0;

			if (matrix.size_x != matrix.size_y)
			{
				cout << "Невозможно определить определитель у такой матрицы!" << endl << endl;

			}
			else
			{
				if (matrix.size_x == 1)
				{
					return matrix.matrix[0][0];
				}
				else if (matrix.size_x == 2)
				{
					return matrix.matrix[0][0] * matrix.matrix[1][1] - matrix.matrix[0][1] * matrix.matrix[1][0];
				}
				else if (matrix.size_x >= 3)
				{

					for (int k = 0; k < help_matrix.copy_size + 1; k++)
					{
						for (int i = 1; i < help_matrix.copy_size + 1; i++)
						{
							for (int j = 0; j < help_matrix.copy_size + 1; j++)
							{
								if (j == k)
								{
									continue;
								}
								else if (j < k)
								{
									help_matrix.matrix[i - 1][j] = matrix.matrix[i][j];
								}
								else
								{
									help_matrix.matrix[i - 1][j - 1] = matrix.matrix[i][j];
								}
							}
						}
						det += pow(-1, k + 2) * matrix.matrix[0][k] * Determinant(help_matrix);
					}
					return det;
				}
			}
		}

		int Rang(Matrix_xy matrix)
		{

		}


		int size_x;
		int size_y;
		vector <vector <double>> matrix;

		private:
			int copy_size = size_y;
};



void SumMatrix(Matrix_x& matrix_main, Matrix_x help_matrix);
void SumMatrix(Matrix_xy& matrix_main, Matrix_xy help_matrix);


void MinusMatrix(Matrix_x& matrix_main, Matrix_x help_matrix);
void MinusMatrix(Matrix_xy& matrix_main, Matrix_xy help_matrix);


void MultiplicationMatrix(Matrix_x& matrix_main, double value);
void MultiplicationMatrix(Matrix_xy& matrix_main, double value);
Matrix_xy MultiplicationMatrix(Matrix_x matrix_main, Matrix_x help_matrix);
Matrix_x MultiplicationMatrix(Matrix_x matrix_main, Matrix_xy help_matrix);
Matrix_xy MultiplicationMatrix(Matrix_xy matrix_main, Matrix_xy help_matrix);

void DivisionMatrix(Matrix_x& matrix, double value);
void DivisionMatrix(Matrix_xy& matrix, double value);
