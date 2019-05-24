//
// Created by alejandro on 5/24/19.
//
#include "catch2.h"
#include "disjoint_set.h"
#include <vector>
#include <array>
#include <deque>

TEST_CASE("Test arena:") {

    disjoint_set<5,std::vector<int>> test1;

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

    disjoint_set<5,std::deque<int>> test2;

    test2.join(1,0);
    test2.join(3,1);
    test2.join(2,0);
    test2.join(7,0);
    test2.join(8,4);
    test2.join(4,5);
    test2.join(6,4);
    REQUIRE(test2.find(1)==0);
    REQUIRE(test2.find(0)==0);
    REQUIRE(test2.find(3)==0);
    REQUIRE(test2.find(8)==test2.find(6));
    REQUIRE(test2.find(7)==test2.find(3));
    REQUIRE(test2.same(8,5)==true);
    REQUIRE(test2.same(3,5)==false);
    REQUIRE(test2.same(2,7)==true);

    disjoint_set<5,std::array<int,5>> test3;

    test3.join(1,0);
    test3.join(3,1);
    test3.join(2,0);
    test3.join(7,0);
    test3.join(8,4);
    test3.join(4,5);
    test3.join(6,4);
    REQUIRE(test3.find(1)==0);
    REQUIRE(test3.find(0)==0);
    REQUIRE(test3.find(3)==0);
    REQUIRE(test3.find(8)==test2.find(6));
    REQUIRE(test3.find(7)==test2.find(3));
    REQUIRE(test3.same(8,5)==true);
    REQUIRE(test3.same(3,5)==false);
    REQUIRE(test3.same(2,7)==true);


}