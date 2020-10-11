#include "Lijst.hpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE( "operator<<" ){
   std::stringstream s;
   my_array array;
   array.add(2);
   array.add(3);

   s << array;
   
   REQUIRE( s.str() == "{2,3}" );   
}

TEST_CASE( "add" ){
   std::stringstream s;
   my_array array;
   array.add(4);
   array.add(2);
   array.add(6);

   s << array;

   REQUIRE( s.str() == "{4,2,6}" );   
}

TEST_CASE( "remove" ){
   std::stringstream s;
   my_array array;
   array.add(1);
   array.add(2);
   array.add(3);

   array.remove(1);
   array.remove(15);

   s << array;
   
   REQUIRE( s.str() == "{2,3}" ); 
}

TEST_CASE( "contains" ){
   my_array array;
   array.add(4);
   array.add(2);
   array.add(6);

   REQUIRE( array.contains(2) == true );  
}

