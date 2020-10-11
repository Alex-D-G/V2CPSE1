#include <iostream>
#include <array>

#ifndef _LIJST_HPP
#define _LIJST_HPP

class my_array {
private:
   std::array< int, 10 > array;
   int array_size=0;

public:
   void add( int number ){
      if(array_size==10){
         return;
      }
      for( const auto & x : array ){
         if(x==number){
            return;
         }
      }
      array[ array_size ] = number;
      array_size+=1;
   }

   void remove(int number){                 
      for( int i=0; i<array_size; i++ ){
         if(array[i] == number){
            array_size -= 1;
            for(int j=i; j<array_size; j++){
               array[j] = array[j+1];
            }
            break;
         }
      }
   }

   bool contains( int number ){
      for( const auto & x : array ){
         if(x==number){
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
