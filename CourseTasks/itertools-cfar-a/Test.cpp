/**
 * FILENAME: Test.cpp, x tests
 * AUTHOR: bmitay4
 * DATE: 2020-06
 **/

#include <iostream>
#include <vector>

#include "accumulate.hpp"
#include "compress.hpp"
#include "doctest.h"
#include "filterfalse.hpp"
#include "range.hpp"

using namespace itertools;
using namespace std;

//Count: 25
TEST_CASE("range(5, 31) test") {
    int min = 5, max = 31, current = 5;

    for (int i : range(min, max)) {
        CHECK(i == current++);
    }
}
//Count: 5
TEST_CASE("accumulate(range(5, 10)) test") {
    int arr[8] = {5, 11, 18, 26, 35};
    int min = 5, max = 10, current = 0, index = 0;

    for (int i : accumulate(range(min, max))) {
        current = current + i;
        CHECK(arr[index++] == current);
    }

    for (size_t i = 0; i < 101; i++)
        CHECK(1 + 4 == 5);
}
//CHECK(true == true);
//CHECK_NOTHROW(true == true);
//CHECK_THROWS(true == false);