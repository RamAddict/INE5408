#include "ArrayList.h"


  TEST_CASE("TESTANDO VAZIO" "[clear()][empty()]"){
    structures::ArrayList<int> list{};
    REQUIRE( list.empty() == true );
    list.clear();
    REQUIRE( list.empty() == true );
  }
  TEST_CASE("TESTANDO ADICIONAR ELEMENTOS ATRAS" "[push_back()][empty()]"){
    structures::ArrayList<int> list{};
    REQUIRE( list.empty() == true );
    list.push_back( 2 );
    REQUIRE( list.empty() == false );
  }
  TEST_CASE("TESTANDO ENCHER E ESVAZIAR", "[push_back()][empty()][full()]"){
    structures::ArrayList<int> list{};
    REQUIRE( list.empty() == true );
    for ( auto it = 0; it != 10; it++ ) {
      list.push_back( it );
    }
    REQUIRE( list.full() );
    REQUIRE_THROWS( list.push_back( 2 ) );
  }
  TEST_CASE("TESTANDO ADICIONAR ELEMENTOS ATRAS" "[push_back()][pop()]"){
    structures::ArrayList<int> list{};
    REQUIRE( list.empty() == true );
    for ( auto it = 0; it != 10; it++ ) {
      list.push_back( it );
    }
    REQUIRE( list.empty() == false );
    list.pop( 0 );
    CHECK( list.full() == false );
  }
