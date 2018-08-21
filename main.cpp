
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
  TEST_CASE("TESTANDO ACHAR UM NUMERO", "[find()]"){
    structures::ArrayList<int> list{};
    for ( auto it = 0; it != 10; it++ ){
      list.push_back( it );
    }
    REQUIRE( list.find( 5 ) == 5 );
    REQUIRE( static_cast<int>(list.find( 10 )) == -1);
  }
  TEST_CASE("TESTAR O TAMANHO E TAMANHO MAXIMO", "[size()][max_size_]"){
    structures::ArrayList<int> list{};
    for ( auto it = 0; it != 10; it++ ){
      list.push_back( it );
    }
    REQUIRE( list.size( ) == 10 );
    
}
