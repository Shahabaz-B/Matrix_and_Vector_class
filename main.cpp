#include "Header.h"

int main()
{
	task::Matrix<double> A({ {1, 2}, { 2,3 } });
	std::cout << "A "<< A;
	task::Matrix<double> B;
	B = { {1, 2, 3}, { 2,3, 4 } };
	std::cout << "B "<< B;

	task::Matrix<double> C( B * A);
	std::cout << "B * A " << C;

	/*task::Matrix<double> X;
	X = { {1.0,2.0},{3.0, 4.0} };
	std::cout << "X " << X;

	X = X.transpose();
	std::cout << "X.transpose() " << X;


	task::Matrix<double> AB = A * B;
	std::cout << "A * B " << AB;

	AB = A + B;
	std::cout << "A + B " << AB;

	AB = A - B;
	std::cout << "A - B " << AB;

	task::Matrix<double> D = B * 3;
	std::cout << "B * 3 " << D;

	task::Matrix<double> E = B + 3.1;
	std::cout << "B + 3 " << E;

	task::Matrix<int> Z;
	Z = { {1,2},{3,4} };
	task::Matrix<int> sum = Z+X;

	task::Matrix<double> F = B - 3;
	std::cout << "B - 3 " << F;

	task::Matrix<double> G = B / 3.0005;
	std::cout << "B / 3 " << G;*/

	return 0;
}