#include "Header.h"
#include "Vector.h"

int main()
{
	task::Vector<double> A({ 1, 2, 3 });

	task::Matrix<double> B({ {1, 2, 3 }, {1, 2, 3 }, {1, 2, 3 } });

	task::Matrix<double> C(A*B);
	std::cout << C;

	return 0;
}