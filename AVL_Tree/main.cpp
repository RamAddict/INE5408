#include "avl_tree.h"
#include "catch.h"

    TEST_CASE("creating queue and adding elements to it") {
        structures::AVLTree<double> tree {};
        CHECK(tree.size() == 0);
        // CHECK(tree.pre_order().empty());
        tree.insert(10);
        CHECK(tree.size() == 1);
        tree.insert(20);
        CHECK(tree.size() == 2);
        tree.insert(30);
        CHECK(tree.size() == 3);
        tree.insert(40);
        CHECK(tree.size() == 4);
        tree.insert(50);
        tree.insert(25);
        auto list = tree.pre_order();
        std::cout << "pre order: ";
        for (int i = 0; i != list.size(); i++)
            std::cout << list.at(i) << " ";
        list = tree.post_order();
        std::cout << std::endl << "post order: ";
        for (int i = 0; i != list.size(); i++)
            std::cout << list.at(i) << " ";
        list = tree.in_order();
        std::cout << std::endl << "in order: ";
        for (int i = 0; i != list.size(); i++)
            std::cout << list.at(i) << " ";
        CHECK(tree.contains(10));
        CHECK(tree.contains(20));
        CHECK(tree.contains(30));
        CHECK(tree.contains(40));
        CHECK(tree.contains(50));
        CHECK(!tree.contains(7.2));
        CHECK_NOTHROW(tree.remove(10));
        CHECK(!tree.contains(10));
        list = tree.pre_order();
        std::cout << "pre order: ";
        for (int i = 0; i != list.size(); i++)
            std::cout << list.at(i) << " ";
        // tree.remove(9);
    }
        TEST_CASE("creating queu") {
        structures::AVLTree<std::string> tree {};
        CHECK(tree.size() == 0);
        tree.insert("a");
    }