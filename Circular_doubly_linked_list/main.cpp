#include "doubly_linked_list.h"
#include "catch.h"

    TEST_CASE("") {
        structures::DoublyCircularList<int> list;
        // list.push_back(11);
        // list.push_front(1);
        CHECK_THROWS(list.insert(123,1));
        // list.insert(123, 0);
        // CHECK(123 == list.at(0));
        // CHECK_THROWS(list.insert(123,-1));
        // CHECK_THROWS(list.at(1));
        // list.clear();

        list.insert_sorted(10);
        list.insert_sorted(-10);
        list.insert_sorted(42);
        list.insert_sorted(0);

        CHECK(-10 == list.at(0));
        CHECK(0 == list.at(1));
        CHECK(10 == list.at(2));
        CHECK(42 == list.at(3));
        std:: cout << list.at(4);
    }