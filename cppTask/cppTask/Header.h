#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include <tuple>

using std::vector;
using std::tuple;

//template<class T>
//class Matrix
//{
//public:
//
//	Matrix();
//
//	T Matrix2();
//	T Matrix3();
//	T Matrix4();
//	T Matrix5();
//	T MatrixX();
//
//	T getRows() const;
//	T getCols() const;
//
//	T operator+(Matrix &);
//	T operator-(Matrix &);
//	T operator*(Matrix &);
//	T transpose();
//
//	// Scalar Operations
//	T operator+(double);
//	T operator-(double);
//	T operator*(double);
//	T operator/(double);
//	T print() const;
//	~Matrix();
//
//private:
//	unsigned m_rowSize;
//	unsigned m_colSize;
//	vector<vector<double> > m_matrix;
//};

template<class T>
class Vector
{
public:
	Vector();

	T Vector2();
	T Vector3();
	T Vector4();
	T Vector5();
	T VectorX();

	~Vector();

private:
};
