#include "Header.h"

//template <class T> Matrix<T>::Matrix()
//{
//	std::cout << "Constructor, allocate..." << std::endl;
//}
//
//template <class T> T Matrix<T>::Matrix2()
//{
//	int x(0);
//	return 0;
//}
//
//// No brainer - returns row #
//template <class T> T Matrix<T>::getRows() const
//{
//	return this->m_rowSize;
//}
//
//// returns col #
//template <class T> T Matrix<T>::getCols() const
//{
//	return this->m_colSize;
//}
//
//// Addition of Two Matrices
//template <class T> T Matrix<T>::operator+(Matrix &B) {
//	Matrix sum(m_colSize, m_rowSize, 0.0);
//	unsigned i, j;
//	for (i = 0; i < m_rowSize; i++)
//	{
//		for (j = 0; j < m_colSize; j++)
//		{
//			sum(i, j) = this->m_matrix[i][j] + B(i, j);
//		}
//	}
//	return sum;
//}
//
//// Subtraction of Two Matrices
//template <class T> T Matrix<T>::operator-(Matrix & B) {
//	Matrix diff(m_colSize, m_rowSize, 0.0);
//	unsigned i, j;
//	for (i = 0; i < m_rowSize; i++)
//	{
//		for (j = 0; j < m_colSize; j++)
//		{
//			diff(i, j) = this->m_matrix[i][j] - B(i, j);
//		}
//	}
//
//	return diff;
//}
//
//// Scalar Multiplication
//template <class T> T Matrix<T>::operator*(double scalar) {
//	Matrix result(m_rowSize, m_colSize, 0.0);
//	unsigned i, j;
//	for (i = 0; i < m_rowSize; i++)
//	{
//		for (j = 0; j < m_colSize; j++)
//		{
//			result(i, j) = this->m_matrix[i][j] * scalar;
//		}
//	}
//	return result;
//}
//
//// Scalar Division
//template <class T> T Matrix<T>::operator/(double scalar) {
//	Matrix result(m_rowSize, m_colSize, 0.0);
//	unsigned i, j;
//	for (i = 0; i < m_rowSize; i++)
//	{
//		for (j = 0; j < m_colSize; j++)
//		{
//			result(i, j) = this->m_matrix[i][j] / scalar;
//		}
//	}
//	return result;
//}
//
//// Take any given matrices transpose and returns another matrix
//template <class T> T Matrix<T>::transpose()
//{
//	Matrix Transpose(m_colSize, m_rowSize, 0.0);
//	for (unsigned i = 0; i < m_colSize; i++)
//	{
//		for (unsigned j = 0; j < m_rowSize; j++) {
//			Transpose(i, j) = this->m_matrix[j][i];
//		}
//	}
//	return Transpose;
//}
//
//// Scalar Addition
//template <class T> T Matrix<T>::operator+(double scalar) {
//	Matrix result(m_rowSize, m_colSize, 0.0);
//	unsigned i, j;
//	for (i = 0; i < m_rowSize; i++)
//	{
//		for (j = 0; j < m_colSize; j++)
//		{
//			result(i, j) = this->m_matrix[i][j] + scalar;
//		}
//	}
//	return result;
//}
//
//// Scalar Subraction
//template <class T> T Matrix<T>::operator-(double scalar) {
//	Matrix result(m_rowSize, m_colSize, 0.0);
//	unsigned i, j;
//	for (i = 0; i < m_rowSize; i++)
//	{
//		for (j = 0; j < m_colSize; j++)
//		{
//			result(i, j) = this->m_matrix[i][j] - scalar;
//		}
//	}
//	return result;
//}
//
//// Multiplication of Two Matrices
//template <class T> T Matrix<T>::operator*(Matrix & B) {
//	Matrix multip(m_rowSize, B.getCols(), 0.0);
//	if (m_colSize == B.getRows())
//	{
//		unsigned i, j, k;
//		double temp = 0.0;
//		for (i = 0; i < m_rowSize; i++)
//		{
//			for (j = 0; j < B.getCols(); j++)
//			{
//				temp = 0.0;
//				for (k = 0; k < m_colSize; k++)
//				{
//					temp += m_matrix[i][k] * B(k, j);
//				}
//				multip(i, j) = temp;
//				//cout << multip(i,j) << " ";
//			}
//			//cout << endl;
//		}
//		return multip;
//	}
//	else
//	{
//		return "Error";
//	}
//}
//
//// Prints the matrix beautifully
//template <class T> T Matrix<T>::print() const
//{
//	std::cout << "Matrix: " << std::endl;
//	for (unsigned i = 0; i < m_rowSize; i++) {
//		for (unsigned j = 0; j < m_colSize; j++) {
//			std::cout << "[" << m_matrix[i][j] << "] ";
//		}
//		std::cout << std::endl;
//	}
//}
//
//template <class T> T Matrix<T>::Matrix3()
//{
//	return 0;
//}
//
//template <class T> T Matrix<T>::Matrix4()
//{
//	return 0;
//}
//
//template <class T> T Matrix<T>::Matrix5()
//{
//	return 0;
//}
//
//template <class T> T Matrix<T>::MatrixX()
//{
//	return 0;
//}
//
//template <class T> Matrix<T>::~Matrix()
//{
//	
//}

template <class T> Vector<T>::Vector()
{
	return 0;
}

template <class T> T Vector<T>::Vector2()
{
	return 0;
}

template <class T> T Vector<T>::Vector3()
{
	return 0;
}

template <class T> T Vector<T>::Vector4()
{
	return 0;
}

template <class T> T Vector<T>::Vector5()
{
	return 0;
}

template <class T> T Vector<T>::VectorX()
{
	return 0;
}

template <class T> Vector<T>::~Vector()
{
	return 0;
}