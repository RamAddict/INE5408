#include "ArrayList.h"


  TEST_CASE("TESTANDO VAZIO" "[clear()]"){
    structures::ArrayList<int> list{};
    REQUIRE( list.empty() == true );
    list.clear();
    REQUIRE( list.empty() == true );
  }
  TEST_CASE("TESTANDO ADICIONAR ELEMENTOS ATRAS" "[push_back()]"){
    structures::ArrayList<int> list{};
      REQUIRE( list.empty() == true );
      list.push_back( 2 );
  }
