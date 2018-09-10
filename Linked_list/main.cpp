
#include "linked_list.h"
#include "catch.h"

TEST_CASE("creating linked_list") {
  structures::LinkedList<int> list{};
    SECTION("addding a single element at beggining") {
      CHECK_NOTHROW(list.push_front(100));
      CHECK_NOTHROW(list.push_front(10));
      CHECK(!list.empty());
      CHECK(list.size() == 2);
      CHECK(list.at(0) == 10);
      CHECK(list.at(1) == 100);
    }






}























  //
