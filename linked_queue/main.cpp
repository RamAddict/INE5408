#include "linked_queue.h"
#include "catch.h"

    TEST_CASE("creating queue and adding elements to it") {
        structures::LinkedQueue<int> queue {};
        queue.enqueue(10);
        CHECK(10 == queue.back());
        CHECK(10 == queue.front());

        for (int i = 0; i != 10; i++) {
            queue.enqueue(i);
            CHECK(i == queue.back());
        }
        CHECK(10 == queue.front());
        CHECK(queue.dequeue() == 10);
        CHECK(queue.front() == 0);
        for (int i = 0; i != 10; i++) {
            CHECK(queue.front() == i);
            queue.dequeue();
        }
        structures::LinkedQueue<int> queue2 {};
        CHECK(queue2.empty() == true);
        CHECK_THROWS(queue2.front());
        CHECK_THROWS(queue2.back());

        queue2.enqueue(2);

        CHECK(queue2.empty() == false);
        CHECK(queue2.front() == 2);
        CHECK(queue2.back() == 2);
    }