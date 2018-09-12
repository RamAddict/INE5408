
#include "linked_list.h"
#include "catch.h"

TEST_CASE("creating linked_list") {
  structures::LinkedList<int> list{};
    SECTION("addding elements") {
      //list.push_back(0);
      //list.push_back(1);
      
      CHECK_NOTHROW(list.push_front(100));
      CHECK_NOTHROW(list.push_front(10));
      CHECK(!list.empty());
      CHECK(list.size() == 2);
      CHECK(list.at(0) == 10);
      CHECK(list.at(1) == 100);
      CHECK_NOTHROW(list.push_back(20));
      CHECK(list.at(0) == 10);
      CHECK(list.at(1) == 100);
      CHECK(list.at(2) == 20);
      CHECK(list.size() == 3);
      CHECK_NOTHROW(list.insert(800, 1));
      CHECK(list.at(1) == 800);
      CHECK(list.at(2) == 100);
      CHECK(list.at(0) == 10);
      CHECK(list.at(3) == 20);
      CHECK(list.size() == 4);
      CHECK_NOTHROW(list.insert_sorted(0));
      CHECK(list.size() == 5);
      CHECK(list.at(0) == 0);
      CHECK(list.at(1) == 10);
      CHECK(list.at(2) == 20);
      CHECK(list.at(3) == 100);
      CHECK(list.at(4) == 800);
      CHECK_NOTHROW(list.insert_sorted(40));
      CHECK(list.at(0) == 0);
      CHECK(list.at(1) == 10);
      CHECK(list.at(2) == 20);
      CHECK(list.at(3) == 40);
      CHECK(list.at(4) == 100);
      CHECK(list.at(5) == 800);
      CHECK(list.size() == 6);
    }
    SECTION("killing elements") {
      list.push_back(800);
      list.push_front(200);
      CHECK(list.pop_back() == 800);
      CHECK(list.size() == 1);
      CHECK(list.at(0) == 200);
      CHECK(list.pop_front() == 200);
      CHECK(list.size() == 0);
      list.push_back(1);
      list.push_back(90);
      list.push_back(143);
      CHECK(list.pop_front() == 1);
      CHECK(list.size() == 2);
      CHECK(list.at(0) == 90);
      CHECK(list.at(1) == 143);
      list.push_front(8);
      list.pop(1); // 90
      CHECK(list.at(0) == 8);
      CHECK(list.at(1) == 143);
      CHECK(list.find(143) == 1);
      list.insert(100, 1);
      list.insert(1000, 1);
      CHECK(list.at(1) == 1000);
      CHECK(list.at(2) == 100);
      CHECK(list.find(100) == 2);
      CHECK(list.find(143) == 3);
      CHECK(list.find(1020) == 4);
      list.remove(100);
      CHECK(list.at(0) == 8);
      CHECK(list.at(1) == 1000);
      CHECK(list.at(2) == 143);
      CHECK_THROWS(list.at(3));
      CHECK(list.contains(100) == false);
      CHECK(list.contains(143) == true);
    }





}























  //
