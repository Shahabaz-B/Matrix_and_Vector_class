/*
This file contains all the contents of Matrix class type and its respective
functions

Author : Shahabaz Bagwan
Date : 17.01.2020
*/

#pragma once
#include <iostream>
#include <stdio.h>
#include <vector>

namespace MatVect {
  template < class T = double > class Matrix
  {
    template < typename T > using Mat = std::vector< std::vector< T > >;

  public:
    // Constructor to provide initial size of matrix
    Matrix( size_t rows_, size_t cols_ ) : iRows( rows_ ), iCols( cols_ )
    {
      iMat = Mat< T >( rows_, std::vector< T >( cols_, 0 ) );
    }

    // Default constructor
    Matrix() : iRows( 0 ), iCols( 0 ) {}

    // Constructor with direct matrix data input
    Matrix( Mat< T > inputMatrix )
    {
      iMat  = inputMatrix;
      iRows = inputMatrix.size();
      iCols = inputMatrix[ 0 ].size();
    }

    // Provides number of rows of matrix
    T Rows() const;

    // Provides number of columns of matrix
    T Cols() const;

    // Returns value from matrix at index i, j
    T operator()( size_t i, size_t j );

    // sets the value at index i, j
    void SetValue( size_t i, size_t j, T value_ );

    // sets a particular column with given std::vector value
    void SetCol( size_t colNumber_, std::vector< T > valueArray_ );

    // sets a particular row with given std::vector value
    void SetRow( size_t rowNumber_, std::vector< T > valueArray_ );

    // Adds matrices
    template < typename U > Matrix< T > operator+( Matrix< U > );

    // Subtracts matrices
    template < typename U > Matrix< T > operator-( Matrix< U > );

    // Multiplies matrices
    template < typename U > Matrix< T > operator*( Matrix< U > );

    // Provides transpose of a matrix
    Matrix< T > transpose();

    // Adds a scalar value to matrix
    template < typename U > Matrix< T > operator+( U );

    // Subtracts a scalar value from matrix
    template < typename U > Matrix< T > operator-( U );

    // Multiplies a scalar value with matrix
    template < typename U > Matrix< T > operator*( U );

    // Divides matrix value with a scalar
    template < typename U > Matrix< T > operator/( U );

    // Prints matrix
    template < typename U >
    friend std::ostream& operator<<( std::ostream& stream, Matrix< U >& dt );

    // Destructor to clear memory
    ~Matrix();

  private:
    Mat< T > iMat;
    size_t iRows, iCols;
  };
} // namespace MatVect
