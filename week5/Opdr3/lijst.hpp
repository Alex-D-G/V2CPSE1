#include <iostream>
#include <array>

#ifndef _LIJST_HPP
#define _LIJST_HPP

template< typename T, int N>
class my_array {
private:
   std::array< T, N > array;
   int array_size=0;

public:
   void add( T var ){
      if(array_size==N){
         return;
      }
      for( const auto & x : array ){
         if(x==var){
            return;
         }
      }
      array[ array_size ] = var;
      array_size+=1;
   }

   void remove(T var){                 
      for( int i=0; i<array_size; i++ ){
         if(array[i] == var){
            array_size -= 1;
            for(int j=i; j<array_size; j++){
               array[j] = array[j+1];
            }
            break;
         }
      }
   }

   T max(){
      T maximum = array[0];
      for( int i=0; i<array_size; i++ ){
         if( array[i] > maximum ){
            maximum = array[i];
         }
      }
      return maximum;
   }

   bool contains( T var ){
      for( const auto & x : array ){
         if(x==var){
            return true;
         }
      }
      return false;
   }

   friend std::ostream& operator<<( std::ostream & lhs, const my_array &rhs){
      lhs << "{";
      for( int i=0; i<rhs.array_size; i++ ){
         lhs << rhs.array[ i ];
         if(!(i==rhs.array_size-1)){
            lhs << ",";
         }
      }
      lhs << "}";
      return lhs;
   }

};

#endif
