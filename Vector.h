#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include "Header.h"
namespace task
{

	template<class T>
	class Vector : public Matrix<T>
	{

	public:
		Vector(size_t size_) : size(size_)
		{
			iVect = Matrix::Mat<T>(1, std::vector<T>(size_, 0));
		}

		Vector() :size(0)
		{

		}

		Vector(std::vector<T> inputVector)
		{
			iVect.resize(1);
			iVect[0] = inputVector;
			size = inputVector.size();
		}

		T Size() const;

		T operator() (size_t i);

		void operator= (std::vector<T> inputVector)
		{
			iVect.resize(1);
			iVect[0] = inputVector;
			size = inputVector.size();
		}

		void SetValue(size_t index_, T value_);

		template<typename U>
		Vector<T> operator+(Vector<U> B);

		template<typename U>
		Vector<T> operator-(Vector<U>);

		template<typename U>
		Vector<T> operator*(Vector<U>);

		template<typename U>
		Vector<T> operator+(U value_);


		template<typename U>
		Vector<T> operator-(U);

		template<typename U>
		Vector<T> operator*(U);


		template<typename U>
		Vector<T> operator/(U);

		template <typename U>
		friend std::ostream& operator<<(std::ostream& stream, Vector<U> &dt);

		~Vector();

	private:
		Matrix::Mat<T> iVect;
		size_t size;
	};

	template <class T>
	inline T Vector <T>::Size() const
	{
		return this->size;
	}

	template<class T>
	inline T Vector<T>::operator()(size_t i)
	{
		return iVect[0][i];
	}

	template<class T>
	inline void Vector<T>::SetValue(size_t index_, T value_)
	{
		this->iVect[0][index_] = value_;
	}

	template<class T>
	inline Vector<T>::~Vector()
	{
		this->iVect.clear();
	}

	template<class T>
	template<typename U>
	inline Vector<T> Vector<T>::operator+(Vector<U> B)
	{
		try
		{
			if (this->size == B.Size())
			{
				Vector<T> result(this->size);


				for (size_t j = 0; j < this->size; j++)
				{
					result.SetValue(j, this->iVect[0][j] + B(j));
				}

				return result;
			}
			else
			{
				std::range_error e("Dimension mismatch while adding vectors\n");
				throw e;
			}
		}
		catch (const std::exception& e) {
			std::cout << e.what();
		}
	}

	template<class T>
	template<typename U>
	inline Vector<T> Vector<T>::operator-(Vector<U> B)
	{
		try
		{
			if (this->size == B.Size())
			{
				Vector<T> result(this->size);


				for (size_t j = 0; j < this->size; j++)
				{
					result.SetValue(j, this->iVect[0][j] - B(j));
				}

				return result;
			}
			else
			{
				std::range_error e("Dimension mismatch while subtracting vectors\n");
				throw e;
			}
		}
		catch (const std::exception& e) {
			std::cout << e.what();
		}
	}

	template<class T>
	template<typename U>
	inline Vector<T> Vector<T>::operator*(Vector<U> B)
	{
		try
		{
			if (this->size == B.Size())
			{
				Vector<T> result(this->size);


				for (size_t j = 0; j < this->size; j++)
				{
					result.SetValue(j, this->iVect[0][j] * B(j));
				}

				return result;
			}
			else
			{
				std::range_error e("Dimension mismatch while multiplying vectors\n");
				throw e;
			}
		}
		catch (const std::exception& e) {
			std::cout << e.what();
		}
	}

	template<class T>
	template<typename U>
	inline Vector<T> Vector<T>::operator+(U value_)
	{
		Vector<T> result(this->size);

		for (size_t i = 0; i < this->size; i++)
		{

			result.SetValue(i, this->iVect[0][i] + value_);

		}
		return result;
	}

	template<class T>
	template<typename U>
	inline Vector<T> Vector<T>::operator-(U value_)
	{
		Vector<T> result(this->size);

		for (size_t i = 0; i < this->size; i++)
		{

			result.SetValue(i, this->iVect[0][i] - value_);

		}
		return result;
	}

	template<class T>
	template<typename U>
	inline Vector<T> Vector<T>::operator*(U value_)
	{
		Vector<T> result(this->size);

		for (size_t i = 0; i < this->size; i++)
		{

			result.SetValue(i, this->iVect[0][i] * value_);

		}
		return result;
	}

	template<class T>
	template<typename U>
	inline Vector<T> Vector<T>::operator/(U value_)
	{
		Vector<T> result(this->size);

		for (size_t i = 0; i < this->size; i++)
		{

			result.SetValue(i, this->iVect[0][i] / value_);

		}
		return result;
	}

	template<typename U>
	std::ostream & operator<<(std::ostream & stream, Vector<U>& dt)
	{
		stream << "\n";
		for (size_t i = 0; i < dt.Size(); i++)
		{
			stream << dt(i) << "  ";
		}
		stream << "\n";

		return stream;
	}
}