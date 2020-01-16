#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>


template <class T>
class Matrix
{
	template <typename T>
	using Mat = std::vector<std::vector<T>>;

public:
	Matrix(size_t rows_, size_t cols_) : iRows(rows_), iCols(cols_)
	{
		iMat = Mat<T>(rows_, std::vector<T>(cols_, 0));
	}

	Matrix():iRows(0), iCols(0)
	{
	}

	T Rows() const;
	T Cols() const;


	T operator() (size_t i, size_t j);
	void operator() (Mat<T> inputMatrix)
	{
		iMat = inputMatrix;
		iRows = inputMatrix.size(); iCols =inputMatrix[0].size();
	}

	void operator= (Mat<T> inputMatrix)
	{
		iMat = inputMatrix;
		iRows = inputMatrix.size(); iCols = inputMatrix[0].size();
	}

	void SetVal(size_t i, size_t j, T value_);
	void SetVal(Mat<T>  value_);
	void SetCol(size_t colNumber_, std::vector<T> valueArray_);
	void SetRow(size_t rowNumber_, std::vector<T> valueArray_);

	T operator+(Matrix &);
	T operator-(Matrix &);
	Matrix operator*(Matrix &);
	T transpose();

	T operator+(T);
	T operator-(T);
	Matrix operator*(T);
	T operator/(T);
	
	~Matrix();
	Mat<T> iMat;
private:
	size_t iRows, iCols;
};

template<class T>
class Vector
{
public:
	Vector();

	~Vector();

private:
};

template <class T>
inline T Matrix <T>::operator()(size_t i, size_t j)
{
	return iMat[i][j];
}

template <class T>
inline void Matrix <T>::SetVal(size_t i, size_t j, T value_)
{
	iMat[i][j] = value_;
}

template <class T>
inline void Matrix <T>::SetVal(Mat<T> value_)
{
	for (size_t row = 0, ipRow = 0; row < this->iRows && ipRow; row++, ipRow++)
	{
		for (size_t col = 0, ipCol = 0; col < this->iCols; col++, ipCol++)
		{
			iMat[row][col] = value_[ipRow][ipCol];
		}
	}
}

template <class T>
inline void Matrix <T>::SetRow(size_t rowNumber_, std::vector<T> valueArray_)
{
	for (size_t col = 0; col < valueArray_.size(); col++)
		iMat[rowNumber_][col] = valueArray_[col];
}

template <class T>
inline void Matrix <T>::SetCol(size_t colNumber_, std::vector<T> valueArray_)
{
	for (size_t row = 0; row < valueArray_.size(); row++)
		iMat[row][colNumber_] = valueArray_[row];
}

template <class T>
inline T Matrix <T>::Rows() const
{
	return this->iRows;
}

template <class T>
inline T Matrix <T>::Cols() const
{
	return this->iCols;
}

// Addition of Two Matrices
template <class T>
inline T Matrix <T>::operator+(Matrix &B)
{
	Matrix sum(iCols, iRows, 0.0);
	unsigned i, j;
	for (i = 0; i < iRows; i++)
	{
		for (j = 0; j < iCols; j++)
		{
			sum(i, j) = this->m_matrix[i][j] + B(i, j);
		}
	}
	return sum;
}

// Subtraction of Two Matrices
template <class T>
inline T Matrix <T>::operator-(Matrix & B) {
	Matrix diff(iCols, iRows, 0.0);
	unsigned i, j;
	for (i = 0; i < iRows; i++)
	{
		for (j = 0; j < iCols; j++)
		{
			diff(i, j) = this->m_matrix[i][j] - B(i, j);
		}
	}

	return diff;
}

// Scalar Multiplication 
template <class T>
inline Matrix<T> Matrix<T>::operator*(T scalar)
{
	Matrix result(this->iRows, this->iCols);
	for (size_t i = 0; i < this->iRows; i++)
	{
		for (size_t j = 0; j < this->iRows; j++)
		{
			result.SetVal(i, j, this->iMat[i][j] * scalar);
		}
	}
	return result;
}

// Scalar Division
template <class T>
inline T Matrix<T>:: operator/(T scalar)
{
	Matrix result(iRows, iCols, 0.0);
	unsigned i, j;
	for (i = 0; i < iRows; i++)
	{
		for (j = 0; j < iCols; j++)
		{
			result(i, j) = this->m_matrix[i][j] / scalar;
		}
	}
	return result;
}

// Take any given matrices transpose and returns another matrix
template <class T>
inline T Matrix<T>::transpose()
{
	Matrix Transpose(iCols, iRows, 0.0);
	for (unsigned i = 0; i < iCols; i++)
	{
		for (unsigned j = 0; j < iRows; j++) {
			Transpose(i, j) = this->m_matrix[j][i];
		}
	}
	return Transpose;
}

// Scalar Addition
template <class T>
inline T Matrix<T>::operator+(T scalar) {
	Matrix result(iRows, iCols, 0.0);
	unsigned i, j;
	for (i = 0; i < iRows; i++)
	{
		for (j = 0; j < iCols; j++)
		{
			result(i, j) = this->m_matrix[i][j] + scalar;
		}
	}
	return result;
}

// Scalar Subraction
template <class T>
inline T Matrix<T>::operator-(T scalar) {
	Matrix result(iRows, iCols, 0.0);
	unsigned i, j;
	for (i = 0; i < iRows; i++)
	{
		for (j = 0; j < iCols; j++)
		{
			result(i, j) = this->m_matrix[i][j] - scalar;
		}
	}
	return result;
}


// Multiplication of Two Matrices
template <class T>
inline Matrix<T> Matrix<T>::operator*(Matrix<T> & B) {
	Matrix multip(iRows, B.Cols());
	if (iCols == B.Rows())
	{
		double temp = 0.0;
		for (size_t i = 0; i < iRows; i++)
		{
			for (size_t j = 0; j < B.Cols(); j++)
			{
				temp = 0.0;
				for (size_t k = 0; k < iCols; k++)
				{
					temp += this->iMat[i][k] * B(k, j);
				}
				multip.SetVal(i, j,temp);
			}
		}
		return multip;
	}
}


template <class T>
inline Matrix<T>::~Matrix()
{
	//for (size_t i = 0; i < this->iRows; i++)
	//	delete mat[i];
	//delete mat;
}

template <class T> Vector<T>::Vector()
{
	std::cout << 0 << std::endl;
}

template <class T> Vector<T>::~Vector()
{

}