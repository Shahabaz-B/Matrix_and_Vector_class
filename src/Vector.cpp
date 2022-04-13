/*
This file contains all the contents of Vector class type and its respective
functions

Author : Shahabaz Bagwan
Date : 17.01.2020
*/

#include <matrixAndVectors/Vector.hpp>

namespace MatVect {

  // Provides size of the vector
  template < class T > inline T Vector< T >::Size() const { return this->size; }

  // Returns value from vector at index i
  template < class T > inline T Vector< T >::operator()( size_t i )
  {
    return iVect[ 0 ][ i ];
  }

  // Sets the value at index i
  template < class T >
  inline void Vector< T >::SetValue( size_t index_, T value_ )
  {
    this->iVect[ 0 ][ index_ ] = value_;
  }

  // Destructor to clear memory
  template < class T > inline Vector< T >::~Vector() { this->iVect.clear(); }

  // Adds vectors
  template < class T >
  template < typename U >
  inline Vector< T > Vector< T >::operator+( Vector< U > B )
  {
    try {
      if( this->size == B.Size() ) {
        Vector< T > result( this->size );

        for( size_t j = 0; j < this->size; j++ ) {
          result.SetValue( j, this->iVect[ 0 ][ j ] + B( j ) );
        }

        return result;
      } else {
        std::range_error e( "Dimension mismatch while adding vectors\n" );
        throw e;
      }
    } catch( const std::exception& e ) {
      std::cout << e.what();
    }
  }

  // Subtracts vectors
  template < class T >
  template < typename U >
  inline Vector< T > Vector< T >::operator-( Vector< U > B )
  {
    try {
      if( this->size == B.Size() ) {
        Vector< T > result( this->size );

        for( size_t j = 0; j < this->size; j++ ) {
          result.SetValue( j, this->iVect[ 0 ][ j ] - B( j ) );
        }

        return result;
      } else {
        std::range_error e( "Dimension mismatch while subtracting vectors\n" );
        throw e;
      }
    } catch( const std::exception& e ) {
      std::cout << e.what();
    }
  }

  // Multiplies vector with matrix
  template < class T >
  template < typename U >
  inline Matrix< U > Vector< T >::operator*( Matrix< U > B )
  {
    Matrix< U > helper( 1, this->Size() );
    for( size_t i = 0; i < this->Size(); i++ ) {
      helper.SetValue( 0, i, this->iVect[ 0 ][ i ] );
    }

    return helper * B;
  }

  // Adds scalar to vectors
  template < class T >
  template < typename U >
  inline Vector< T > Vector< T >::operator+( U value_ )
  {
    Vector< T > result( this->size );

    for( size_t i = 0; i < this->size; i++ ) {

      result.SetValue( i, this->iVect[ 0 ][ i ] + value_ );
    }
    return result;
  }

  // Subtracts scalar from vectors
  template < class T >
  template < typename U >
  inline Vector< T > Vector< T >::operator-( U value_ )
  {
    Vector< T > result( this->size );

    for( size_t i = 0; i < this->size; i++ ) {

      result.SetValue( i, this->iVect[ 0 ][ i ] - value_ );
    }
    return result;
  }

  // Multiplies scalar with vectors
  template < class T >
  template < typename U >
  inline Vector< T > Vector< T >::operator*( U value_ )
  {
    Vector< T > result( this->size );

    for( size_t i = 0; i < this->size; i++ ) {

      result.SetValue( i, this->iVect[ 0 ][ i ] * value_ );
    }
    return result;
  }

  // Divides vector values with scalar
  template < class T >
  template < typename U >
  inline Vector< T > Vector< T >::operator/( U value_ )
  {
    Vector< T > result( this->size );

    for( size_t i = 0; i < this->size; i++ ) {

      result.SetValue( i, this->iVect[ 0 ][ i ] / value_ );
    }
    return result;
  }

  // Prints vector values
  template < typename U >
  std::ostream& operator<<( std::ostream& stream, Vector< U >& dt )
  {
    stream << "\n";
    for( size_t i = 0; i < dt.Size(); i++ ) {
      stream << dt( i ) << "  ";
    }
    stream << "\n\n";

    return stream;
  }
} // namespace MatVect
