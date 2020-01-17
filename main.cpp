/*
	This is main file it contains some test to display the working of 
	Matrix and Vector class
*/


#include "Header.h"
#include "Vector.h"

using namespace task;
int main()
{
	task::Matrix<double> B({ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} });
	std::cout << "Matrix B:" << B;
	task::Matrix<double> C({ {4, 5, 6}, {7, 8, 9}, {1, 2, 3} });
	std::cout << "Matrix C:" << C;

	task::Vector<double> X({ 1, 2, 3 });
	std::cout << "Vector X:" << X;

	task::Vector<double> Y({ 4, 5, 6 });
	std::cout << "Vector Y:" << Y;

	Matrix <double> Ans(B*C);
	std::cout << "B*C " << Ans;

	Ans = C * B;
	std::cout << "C*B " << Ans;

	Ans = C + B;
	std::cout << "C+B " << Ans;

	Ans = B + C;
	std::cout << "B+C " << Ans;


	Ans = C - B;
	std::cout << "C-B " << Ans;

	Ans = B - C;
	std::cout << "B-C " << Ans;

	Ans = B * 1.5;
	std::cout<< "B * 1.5" << Ans;

	Ans = B + 1.5;
	std::cout<< "B + 1.5" << Ans;

	Ans = B - 1.5;
	std::cout<< "B - 1.5" << Ans;

	Ans = B / 1.5;
	std::cout<< "B / 1.5" << Ans;

	Ans = X * B;
	std::cout << "X * B" << Ans;

	Vector <double> vectAns;
	vectAns = X + Y;
	std::cout << "X + Y" << vectAns;

	vectAns = X - Y;
	std::cout << "X - Y" << vectAns;

	vectAns = X * 1.3;
	std::cout << "X * 1.3" << vectAns;

	vectAns = X + 1.3;
	std::cout << "X + 1.3" << vectAns;

	vectAns = X - 1.3;
	std::cout << "X - 1.3" << vectAns;

	vectAns = X / 1.3;
	std::cout << "X / 1.3" << vectAns;
	return 0;
}