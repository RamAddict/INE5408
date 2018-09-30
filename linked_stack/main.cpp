#include "linked_stack.h"
#include "catch.h"

    TEST_CASE("nao sabe programar", "c++") {
        structures::LinkedStack<int> stack{};
        stack.push(1);
        CHECK(stack.top() == 1);
        CHECK(stack.size() == 1);
        CHECK(stack.pop() == 1);
        CHECK(stack.size() == 0);

        for (int i = 0; i != 10; i++) {
            stack.push(i);
            CHECK(stack.top() == i);
            std::cout << i;
        }

        for (int i = 9; i != 0; i--) {
            CHECK(stack.top() == i);
            stack.pop();
        }
        

    }
