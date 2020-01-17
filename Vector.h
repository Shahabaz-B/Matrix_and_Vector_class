#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include "Header.h"
namespace task
{

	template<class T>
	class Vector : protected Matrix
	{
		
	public:
		Vector(size_t size_) : size(size_)
		{
			iVect.resize(size_);
		}

		Vector() :size(0)
		{

		}

		Vector(std::vector<T> inputVector)
		{
			iVect = inputVector;
			size = inputVector.size();
		}

		T Size() const;

		T operator() (size_t i);

		void operator= (std::vector<T> inputVector)
		{
			iVect = inputVector;
			size = inputVector.size();
		}

		void SetValue(size_t i, size_t j, T value_);

		void SetValue(Mat<T>  value_);

		void SetCol(size_t colNumber_, std::vector<T> valueArray_);

		void SetRow(size_t rowNumber_, std::vector<T> valueArray_);

		template<typename U>
		Vector<T> operator+(Vector<U>);

		template<typename U>
		Vector<T> operator-(Vector<U>);

		template<typename U>
		Vector<T> operator*(Vector<U>);

		Vector<T> transpose();

		template<typename U>
		Vector<T> operator+(U);


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
		std::vector<T> iVect;
		size_t size;
	};

	template <class T> Vector<T>::~Vector()
	{

	}
}