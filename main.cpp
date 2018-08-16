#include "ArrayList.h"


  TEST_CASE("TESTANDO VAZIO" "[clear()]"){
    structures::ArrayList<int> list{};
    REQUIRE( list.empty() == true );
    list.clear();
    REQUIRE( list.empty() == true );
  }
