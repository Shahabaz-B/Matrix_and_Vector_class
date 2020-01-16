#include "Header.h"

int main()
{
	Matrix<size_t> A(3, 3);
	A.SetVal(1, 1, 5);
	std::cout << A(1, 1);
	A.SetRow(0, { 3,4 });
	A.SetCol(0, { 4,5 });
	Matrix<size_t> B;
	B = { {1,2,3}, {3,3, 4} , {1,2,2} };
	Matrix<size_t> C = A*B;
	Matrix<size_t> D = B*3;
	return 0;
}