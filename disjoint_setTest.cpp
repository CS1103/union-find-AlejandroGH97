//
// Created by alejandro on 5/24/19.
//
#include "catch2.h"
#include "disjoint_set.h"
#include <vector>
#include <array>
#include <deque>

TEST_CASE("Test arena:") {

    disjoint_set<std::vector> test1(5);

    test1.join(1,0);
    test1.join(3,1);
    test1.join(2,0);
    test1.join(7,0);
    test1.join(8,4);
    test1.join(4,5);
    test1.join(6,4);
    REQUIRE(test1.find(1)==0);
    REQUIRE(test1.find(0)==0);
    REQUIRE(test1.find(3)==0);
    REQUIRE(test1.find(8)==test1.find(6));
    REQUIRE(test1.find(7)==test1.find(3));
    REQUIRE(test1.same(8,5)==true);
    REQUIRE(test1.same(3,5)==false);
    REQUIRE(test1.same(2,7)==true);


}