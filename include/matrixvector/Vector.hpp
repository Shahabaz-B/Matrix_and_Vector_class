/*
This file contains all the contents of Vector class type and its respective
functions

Author : Shahabaz Bagwan
Date : 17.01.2020
*/

#pragma once
#include "Matrix.hpp"
#include <iostream>
#include <stdio.h>
#include <vector>

namespace MatVect {
  template < class T = double > class Vector
  {

  protected:
    template < typename T > using Mat = std::vector< std::vector< T > >;

  public:
    // Constructor to provide initial size of vector
    Vector( size_t size_ ) : size( size_ )
    {
      iVect = Mat< T >( 1, std::vector< T >( size_, 0 ) );
    }

    // Default constructor
    Vector() : size( 0 ) {}

    // Constructor with direct vector data input
    Vector( std::vector< T > inputVector )
    {
      iVect.resize( 1 );
      iVect[ 0 ] = inputVector;
      size       = inputVector.size();
    }

    // Provides size of the vector
    T Size() const;

    // Returns value from vector at index i
    T operator()( size_t i );

    // Sets the value at index i
    void SetValue( size_t index_, T value_ );

    // Adds vectors
    template < typename U > Vector< T > operator+( Vector< U > B );

    // Subtracts vectors
    template < typename U > Vector< T > operator-( Vector< U > );

    // Multiplies vector with matrix
    template < typename U > Matrix< U > operator*( Matrix< U > );

    // Adds scalar to vectors
    template < typename U > Vector< T > operator+( U value_ );

    // Subtracts scalar from vectors
    template < typename U > Vector< T > operator-( U value_ );

    // Multiplies scalar with vectors
    template < typename U > Vector< T > operator*( U value_ );

    // Divides vector values with scalar
    template < typename U > Vector< T > operator/( U value_ );

    // Prints vector values
    template < typename U >
    friend std::ostream& operator<<( std::ostream& stream, Vector< U >& dt );

    // Destructor to clear memory
    ~Vector();

  private:
    Mat< T > iVect;
    size_t size;
  };
} // namespace MatVect
