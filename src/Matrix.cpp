/*
This file contains all the contents of Matrix class type and its respective
functions

Author : Shahabaz Bagwan
Date : 17.01.2020
*/

#include <matrixAndVectors/Matrix.hpp>

namespace MatVect {

  // To print matrix
  template < class T >
  std::ostream& operator<<( std::ostream& stream, Matrix< T >& data )
  {
    stream << "\n";
    for( size_t i = 0; i < data.Rows(); i++ ) {
      stream << "  ";
      for( size_t j = 0; j < data.Cols(); j++ ) {
        stream << data( i, j ) << "  ";
      }
      stream << "\n";
    }
    stream << "\n";
    return stream;
  }

  // Returns value from matrix at index i, j
  template < class T > inline T Matrix< T >::operator()( size_t i, size_t j )
  {
    return iMat[ i ][ j ];
  }

  template < class T >
  inline void Matrix< T >::SetValue( size_t i, size_t j, T value_ )
  {
    this->iMat[ i ][ j ] = value_;
  }

  // sets a particular row with given std::vector value
  template < class T >
  inline void Matrix< T >::SetRow( size_t rowNumber_,
                                   std::vector< T > valueArray_ )
  {
    for( size_t col = 0; col < valueArray_.size(); col++ )
      iMat[ rowNumber_ ][ col ] = valueArray_[ col ];
  }

  // sets a particular column with given std::vector value
  template < class T >
  inline void Matrix< T >::SetCol( size_t colNumber_,
                                   std::vector< T > valueArray_ )
  {
    for( size_t row = 0; row < valueArray_.size(); row++ )
      iMat[ row ][ colNumber_ ] = valueArray_[ row ];
  }

  // Provides number of rows of matrix
  template < class T > inline T Matrix< T >::Rows() const
  {
    return this->iRows;
  }

  // Provides number of columns of matrix
  template < class T > inline T Matrix< T >::Cols() const
  {
    return this->iCols;
  }

  // Adds matrices
  template < class T >
  template < typename U >
  inline Matrix< T > Matrix< T >::operator+( Matrix< U > B )
  {
    try {
      if( ( this->iRows == B.Rows() ) && ( this->iCols == B.Cols() ) ) {
        Matrix< T > result( this->iCols, this->iRows );

        for( size_t i = 0; i < this->iRows; i++ ) {
          for( size_t j = 0; j < this->iCols; j++ ) {
            result.SetValue( i, j, this->iMat[ i ][ j ] + B( i, j ) );
          }
        }
        return result;
      } else {
        std::range_error e( "Dimension mismatch while adding matrices\n" );
        throw e;
      }
    } catch( const std::exception& e ) {
      std::cout << e.what();
    }
  }

  // Subtracts matrices
  template < class T >
  template < typename U >
  inline Matrix< T > Matrix< T >::operator-( Matrix< U > B )
  {
    try {
      if( ( this->iRows == B.Rows() ) && ( this->iCols == B.Cols() ) ) {
        Matrix< T > result( this->iCols, this->iRows );

        for( size_t i = 0; i < this->iRows; i++ ) {
          for( size_t j = 0; j < this->iCols; j++ ) {
            result.SetValue( i, j, this->iMat[ i ][ j ] - B( i, j ) );
          }
        }
        return result;
      } else {
        std::range_error e( "Dimension mismatch while subtracting matrices\n" );
        throw e;
      }
    } catch( const std::exception& e ) {
      std::cout << e.what();
    }
  }

  // Multiplies matrices
  template < class T >
  template < typename U >
  inline Matrix< T > Matrix< T >::operator*( Matrix< U > B )
  {
    try {

      if( this->iCols == B.Rows() ) {
        Matrix< T > result( this->iRows, B.Cols() );

        double value = 0.0;
        for( size_t i = 0; i < this->iRows; i++ ) {
          for( size_t j = 0; j < B.Cols(); j++ ) {
            value = 0.0;
            for( size_t k = 0; k < this->iCols; k++ ) {
              value += this->iMat[ i ][ k ] * B( k, j );
            }
            result.SetValue( i, j, value );
          }
        }
        return result;
      } else {
        std::range_error e( "Dimension mismatch while multiplying matrices\n" );
        throw e;
      }
    } catch( const std::exception& e ) {
      std::cout << e.what();
    }
  }

  // Multiplies a scalar value with matrix
  template < class T >
  template < typename U >
  inline Matrix< T > Matrix< T >::operator*( U scalar )
  {
    Matrix< T > result( this->iRows, this->iCols );
    for( size_t i = 0; i < this->iRows; i++ ) {
      for( size_t j = 0; j < this->iCols; j++ ) {
        result.SetValue( i, j, this->iMat[ i ][ j ] * scalar );
      }
    }
    return result;
  }

  // Divides matrix value with a scalar
  template < class T >
  template < typename U >
  inline Matrix< T > Matrix< T >::operator/( U scalar )
  {
    Matrix< T > result( this->iRows, this->iCols );

    for( size_t i = 0; i < this->iRows; i++ ) {
      for( size_t j = 0; j < this->iCols; j++ ) {
        result.SetValue( i, j, this->iMat[ i ][ j ] / scalar );
      }
    }
    return result;
  }

  // Provides transpose of a matrix
  template < class T > inline Matrix< T > Matrix< T >::transpose()
  {
    Matrix< T > Transpose( this->iCols, this->iRows );
    for( size_t i = 0; i < iCols; i++ ) {
      for( size_t j = 0; j < iRows; j++ ) {
        Transpose.SetValue( i, j, this->iMat[ j ][ i ] );
      }
    }
    return Transpose;
  }

  // Adds a scalar value to matrix
  template < class T >
  template < class U >
  inline Matrix< T > Matrix< T >::operator+( U scalar )
  {
    Matrix< T > result( this->iRows, this->iCols );

    for( size_t i = 0; i < iRows; i++ ) {
      for( size_t j = 0; j < iCols; j++ ) {
        result.SetValue( i, j, this->iMat[ i ][ j ] + scalar );
      }
    }
    return result;
  }

  // Subtracts a scalar value from matrix
  template < class T >
  template < typename U >
  inline Matrix< T > Matrix< T >::operator-( U scalar )
  {
    Matrix< T > result( this->iRows, this->iCols );

    for( size_t i = 0; i < iRows; i++ ) {
      for( size_t j = 0; j < iCols; j++ ) {
        result.SetValue( i, j, this->iMat[ i ][ j ] - scalar );
      }
    }
    return result;
  }

  // Destructor to clear memory
  template < class T > inline Matrix< T >::~Matrix() { this->iMat.clear(); }

} // namespace MatVect
