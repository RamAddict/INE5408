
#include "String_list.h"


  TEST_CASE("TESTANDO VAZIO" "[clear()][empty()]"){
    structures::ArrayList<int> list{};
    REQUIRE( list.empty() == true );
    list.clear();
    REQUIRE( list.empty() == true );
  }
  TEST_CASE("TESTANDO ADICIONAR ELEMENTOS ATRAS E NA FRENTE E NO MEIO E INSERT_SORTED" "[push_back()][empty()][insert()]"){
    structures::ArrayList<int> list{};
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
    structures::ArrayList<int> list{};
    REQUIRE( list.empty() == true );
    for ( auto it = 0; it != 10; it++ ) {
      list.push_back( it );
    }
    REQUIRE( list.full() );
    REQUIRE_THROWS( list.push_back( 2 ) );
  }
  TEST_CASE("TESTANDO ADICIONAR ELEMENTOS ATRAS E POP E REMOVE" "[push_back()][pop()][pop_back()][remove[]]"){
    structures::ArrayList<int> list{};
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
    structures::ArrayList<int> list{};
    for ( auto it = 0; it != 10; it++ ){
      list.push_back( it );
    }
    REQUIRE( list.find( 5 ) == 5 );
    REQUIRE( static_cast<int>(list.find( 10 )) == list.size());
  }
  TEST_CASE("TESTAR O TAMANHO E TAMANHO MAXIMO", "[size()][max_size_]"){
    structures::ArrayList<int> list{20};
    for ( auto it = 0; it != 10; it++ ){
      list.push_back( it );
    }
    REQUIRE( list.size( ) == 10 );
    REQUIRE( list.max_size( ) == 20 );
}
  TEST_CASE("TESTAR BUSCA POR POSICAO", "at(),[]"){
    structures::ArrayList<int> list{};
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
  TEST_CASE("creating an ArrayListSting") {
    {
    structures::ArrayListString list{};
    }
    structures::ArrayListString list{12};
  }
  TEST_CASE("insert sorted") {
    const char *city[10] = {"Blumenau", "Chapeco", "Criciuma", \
    "Florianopolis", "Itajai", "Jaragua_do_Sul", "Joinville", \
    "Lages", "Palhoca", "Sao_Jose"};
    structures::ArrayListString list{};
    for (auto i = 9; i >= 0; --i) {
        list.insert_sorted(city[i]);
    }
    for (auto i = 0; i < 10; ++i) {
        CHECK_THAT(city[i], Catch::Matchers::Equals(list[i]));
    }

    list.clear();

    // list.insert_sorted("10");
    // list.insert_sorted("-10");
    // list.insert_sorted("42");
    // list.insert_sorted("0");
    // CHECK("-10", list[0]);
    // CHECK_THAT("0", list[1]);
    // CHECK_THAT("10", list[2]);
    // CHECK_THAT("42", list[3]);
  }






















  //
