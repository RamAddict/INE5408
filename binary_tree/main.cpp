#include "binary_tree.h"
#include "catch.h"

    TEST_CASE("creating queue and adding elements to it") {
        structures::BinaryTree<double> tree {};
        CHECK(tree.size() == 0);
        //CHECK(tree.pre_order().empty());
        tree.insert(8);
        CHECK(tree.size() == 1);
        tree.insert(7);
        CHECK(tree.size() == 2);
        tree.insert(9);
        CHECK(tree.size() == 3);
        tree.insert(6);
        CHECK(tree.size() == 4);
        tree.insert(7.5);
        CHECK(7.5 < 8);
        CHECK(7.5 > 7);
        auto list = tree.pre_order();
        std::cout << "pre order: ";
        for (int i = 0; i != list.size(); i++)
            std::cout << list.at(i) << " ";
        list = tree.post_order();
        std::cout << std::endl << "post order: ";
        for (int i = 0; i != tree.size(); i++)
            std::cout << list.at(i) << " ";
        list = tree.in_order();
        std::cout << std::endl << "in order: ";
        for (int i = 0; i != tree.size(); i++)
            std::cout << list.at(i) << " ";
        CHECK(tree.contains(7));
        CHECK(tree.contains(7.5));
        CHECK(tree.contains(6));
        CHECK(tree.contains(8));
        CHECK(tree.contains(9));
        CHECK(!tree.contains(7.2));
    }