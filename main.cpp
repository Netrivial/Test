#include <iostream>

#include "Arion_lib.hpp"

using namespace std;

int main() {
	Matrix_x test(4, "column");
	Matrix_xy help_test(5, 5);
	//Matrix_xy help_test_2(4, 3);

	test.matrix_rand();
	test.show_matrix();

	help_test.matrix_rand();
	help_test.show_matrix();

	//help_test_2.matrix_rand();
	//help_test_2.show_matrix();

	double det = help_test.Determinant(help_test);
	cout << det;

	return 0;
}
