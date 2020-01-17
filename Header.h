#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>

namespace task
{
	template <class T = double>
	class Matrix
	{
	protected:
		template <typename T>
		using Mat = std::vector<std::vector<T>>;

	public:
		Matrix(size_t rows_, size_t cols_) : iRows(rows_), iCols(cols_)
		{
			iMat = Mat<T>(rows_, std::vector<T>(cols_, 0));
		}

		Matrix() :iRows(0), iCols(0)
		{
		}

		Matrix(Mat<T> inputMatrix)
		{
			iMat = inputMatrix;
			iRows = inputMatrix.size(); iCols = inputMatrix[0].size();
		}

		T Rows() const;
		T Cols() const;

		T operator() (size_t i, size_t j);

		void operator= (Mat<T> inputMatrix)
		{
			iMat = inputMatrix;
			iRows = inputMatrix.size(); iCols = inputMatrix[0].size();
		}

		void SetValue(size_t i, size_t j, T value_);

		void SetCol(size_t colNumber_, std::vector<T> valueArray_);

		void SetRow(size_t rowNumber_, std::vector<T> valueArray_);

		template<typename U>
		Matrix<T> operator+(Matrix<U>);

		template<typename U>
		Matrix<T> operator-(Matrix<U>);

		template<typename U>
		Matrix<T> operator*(Matrix<U>);

		Matrix<T> transpose();

		template<typename U>
		Matrix<T> operator+(U);


		template<typename U>
		Matrix<T> operator-(U);

		template<typename U>
		Matrix<T> operator*(U);

			template<typename U>
		Matrix<T> operator/(U);

		template <typename U>
		friend std::ostream& operator<<(std::ostream& stream, Matrix<U> &dt);

		~Matrix();

	private:
		Mat<T> iMat;
		size_t iRows, iCols;
	};

	template <class T>
	std::ostream& operator<<(std::ostream& stream, Matrix<T> &dt)
	{
		stream << "\n";
		for (size_t i = 0; i < dt.Rows(); i++)
		{
			stream << "  ";
			for (size_t j = 0; j < dt.Cols(); j++)
			{
				stream << dt(i, j) << "  ";
			}
			stream << "\n";
		}
		stream << "\n";
		return stream;
	}

	template <class T>
	inline T Matrix <T>::operator()(size_t i, size_t j)
	{
		return iMat[i][j];
	}

	template <class T>
	inline void Matrix <T>::SetValue(size_t i, size_t j, T value_)
	{
		this->iMat[i][j] = value_;
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
	template <typename U>
	inline Matrix<T> Matrix <T>::operator+(Matrix<U> B)
	{
		try
		{
			if ((this->iRows == B.Rows()) && (this->iCols == B.Cols()))
			{
				Matrix<T> result(this->iCols, this->iRows);

				for (size_t i = 0; i < this->iRows; i++)
				{
					for (size_t j = 0; j < this->iCols; j++)
					{
						result.SetValue(i, j, this->iMat[i][j] + B(i, j));
					}
				}
				return result;
			}
			else
			{
				std::range_error e("Dimension mismatch while adding matrices\n");
				throw e;
			}
		}
		catch (const std::exception& e) {
			std::cout << e.what();
		}
	}

	// Subtraction of Two Matrices
	template <class T>
	template <typename U>
	inline Matrix<T> Matrix <T>::operator-(Matrix<U> B) {
		try
		{
			if ((this->iRows == B.Rows()) && (this->iCols == B.Cols()))
			{
				Matrix<T> result(this->iCols, this->iRows);

				for (size_t i = 0; i < this->iRows; i++)
				{
					for (size_t j = 0; j < this->iCols; j++)
					{
						result.SetValue(i, j, this->iMat[i][j] - B(i, j));
					}
				}
				return result;
			}
			else
			{
				std::range_error e("Dimension mismatch while subtracting matrices\n");
				throw e;
			}
		}
		catch (const std::exception& e) {
			std::cout << e.what();
		}
	}

	// Multiplication of Two Matrices
	template <class T>
	template <typename U>
	inline Matrix<T> Matrix<T>::operator*(Matrix<U> B)
	{
		try
		{

			if (this->iCols == B.Rows())
			{
				Matrix<T> result(this->iRows, B.Cols());

				double value = 0.0;
				for (size_t i = 0; i < this->iRows; i++)
				{
					for (size_t j = 0; j < B.Cols(); j++)
					{
						value = 0.0;
						for (size_t k = 0; k < this->iCols; k++)
						{
							value += this->iMat[i][k] * B(k, j);
						}
						result.SetValue(i, j, value);
					}
				}
				return result;
			}
			else
			{
				std::range_error e("Dimension mismatch while multiplying matrices\n");
				throw e;
			}
		}
		catch (const std::exception& e) {
			std::cout << e.what();
		}
	}



	// Scalar Multiplication 
	template <class T>
	template <typename U>
	inline Matrix<T> Matrix<T>::operator*(U scalar)
	{
		Matrix<T> result(this->iRows, this->iCols);
		for (size_t i = 0; i < this->iRows; i++)
		{
			for (size_t j = 0; j < this->iCols; j++)
			{
				result.SetValue(i, j, this->iMat[i][j] * scalar);
			}
		}
		return result;
	}

	


	// Scalar Division
	template <class T>
	template <typename U>
	inline Matrix<T> Matrix<T>:: operator/(U scalar)
	{
		Matrix<T> result(this->iRows, this->iCols);

		for (size_t i = 0; i < this->iRows; i++)
		{
			for (size_t j = 0; j < this->iCols; j++)
			{
				result.SetValue(i, j, this->iMat[i][j] / scalar);
			}
		}
		return result;
	}

	// Take any given matrices transpose and returns another matrix
	template <class T>
	inline Matrix<T> Matrix<T>::transpose()
	{
		Matrix<T> Transpose(this->iCols, this->iRows);
		for (size_t i = 0; i < iCols; i++)
		{
			for (size_t j = 0; j < iRows; j++)
			{
				Transpose.SetValue(i, j, this->iMat[j][i]);
			}
		}
		return Transpose;
	}

	// Scalar Addition
	template <class T>
	template <class U>
	inline Matrix<T> Matrix<T>::operator+(U scalar)
	{
		Matrix<T> result(this->iRows, this->iCols);

		for (size_t i = 0; i < iRows; i++)
		{
			for (size_t j = 0; j < iCols; j++)
			{
				result.SetValue(i, j, this->iMat[i][j] + scalar);
			}
		}
		return result;
	}

	// Scalar Subraction
	template <class T>
	template <typename U>
	inline Matrix<T> Matrix<T>::operator-(U scalar)
	{
		Matrix<T> result(this->iRows, this->iCols);

		for (size_t i = 0; i < iRows; i++)
		{
			for (size_t j = 0; j < iCols; j++)
			{
				result.SetValue(i, j, this->iMat[i][j] - scalar);
			}
		}
		return result;
	}

	template <class T>
	inline Matrix<T>::~Matrix()
	{
		this->iMat.clear();
	}

}