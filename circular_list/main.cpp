
#include "circular_list.h"
#include "catch.h"

  TEST_CASE("TESTANDO VAZIO" "[clear()][empty()]"){
    structures::CircularList<int> list{};
    REQUIRE( list.empty() == true );
    list.clear();
    REQUIRE( list.empty() == true );
  }
  TEST_CASE("TESTANDO ADICIONAR ELEMENTOS ATRAS E NA FRENTE E NO MEIO E INSERT_SORTED" "[push_back()][empty()][insert()]"){
    structures::CircularList<int> list{};
    REQUIRE( list.empty() == true );
    list.push_back( 2 );
    REQUIRE( list.empty() == false );
    list.push_front( 20 );
    CHECK( list[0] == 20 );
    CHECK( list[1] == 2 );
    list.insert(10, 1); // 20, 10 , 2, 0
    CHECK( list[1] == 10 );
    CHECK( list[2] == 2 );
    CHECK( list[0] == 20 ); 
    list.insert_sorted(0);
    CHECK( list[0] == 0 );
    CHECK( list[1] == 2 );
    CHECK( list[2] == 10 );
    CHECK( list[3] == 20 );
    CHECK_THROWS( list[-1] );
  }
  TEST_CASE("TESTANDO ENCHER E ESVAZIAR", "[push_back()][empty()][full()]"){
    structures::CircularList<int> list{};
    REQUIRE( list.empty() == true );
    for ( auto it = 0; it != 10; it++ ) {
      list.push_back( it );
    }
    REQUIRE( list.full() );
    REQUIRE_THROWS( list.push_back( 2 ) );
  }
  TEST_CASE("TESTANDO ADICIONAR ELEMENTOS ATRAS E POP E REMOVE" "[push_back()][pop()][pop_back()][remove[]]"){
    structures::CircularList<int> list{};
    REQUIRE( list.empty() == true );
    for ( auto it = 0; it != 10; it++ ) {
      list.push_back( it );
    }
    CHECK(list.at(9) == 9);
    CHECK(list.pop_back() == 9);
    REQUIRE( list.empty() == false );
    CHECK( list.full() == false );
    REQUIRE_THROWS(list.at(9));
    REQUIRE( list.at(8) == 8 );
    CHECK(list[0] == 0);
    CHECK(list.pop_front() == 0);
    CHECK(list[0] == 1);
    list.remove(1);
    CHECK( list[0] == 2 );
  }
  TEST_CASE("TESTANDO ACHAR UM NUMERO", "[find()]"){
    structures::CircularList<int> list{};
    for ( auto it = 0; it != 10; it++ ){
      list.push_back( it );
    }
    REQUIRE( list.find( 5 ) == 5 );
    REQUIRE( static_cast<int>(list.find( 10 )) == list.size());
  }
  TEST_CASE("TESTAR O TAMANHO E TAMANHO MAXIMO", "[size()][max_size_]"){
    structures::CircularList<int> list{20};
    for ( auto it = 0; it != 10; it++ ){
      list.push_back( it );
    }
    REQUIRE( list.size( ) == 10 );
    REQUIRE( list.max_size( ) == 20 );
}
  TEST_CASE("TESTAR BUSCA POR POSICAO", "at(),[]"){
    structures::CircularList<int> list{};
    for ( auto it = 0; it != 10; it++ ){
      list.push_back( it );
    }
    REQUIRE( list.size( ) == 10 );
    REQUIRE_THROWS( list.at( 10 ) );
    REQUIRE_THROWS_WITH( list.at( -1 ), "out of range" );
    for (auto it = 0; it != 10; it++){
    REQUIRE( list.at( it ) == it);
    REQUIRE( list[it] == it );
  }
    REQUIRE( list.contains(1) );
    REQUIRE( !list.contains(1000) );
  }























  //
