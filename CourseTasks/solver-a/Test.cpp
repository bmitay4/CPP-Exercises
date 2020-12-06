/**
 * FILENAME: Test.cpp
 * 
 * AUTHOR: bmitay4
 * 
 * DATE: 2020-04
 * */

#include <complex>
#include <string>

#include "doctest.h"
#include "solver.hpp"

using namespace std;
using namespace solver;

//Count: 25
TEST_CASE("Test Addition Operator") {
    RealVariable x;
    ComplexVariable y;

    CHECK(solve(x + 4 == 6) == double(2));
    CHECK(solve(4 + x == 6) == double(2));
    CHECK(solve(x + x == 5) == double(2.5));
    CHECK(solve(1 + x == 1.5) == double(0.5));
    CHECK(solve(1 + x == 0) == double(-1));
    CHECK(solve(x + 4 == -2) == double(-2));
    CHECK(solve(x + 1 == 0.9) == double(-0.1));
    CHECK(solve(10 + x + 4 == 18) == double(4));
    CHECK(solve(x + 2.5 + 4 == 8.5) == double(2));
    CHECK(solve(3 + x + x + 1 == 54) == double(25));
    CHECK(solve(x + x + x + x == 81) == double(20.25));
    CHECK(solve(x + x == 1) == double(0.5));

    CHECK_THROWS(solve(x == x + 10));
    CHECK_THROWS(solve(x + 0 == x + 1));
    CHECK_THROWS(solve(2 + x == x + 4));
    CHECK_THROWS(solve(2 + x + 10 == x));
    CHECK_THROWS(solve(5 + x + 2 == x + 9));

    CHECK(solve(y + 7i == 3i) == complex<double>(-4i));
    CHECK(solve(4i + y == 6i) == complex<double>(2i));
    CHECK(solve(y + y == 4i) == complex<double>(2i));
    CHECK(solve(4.5i + 1.5i + y == 6.5i) == complex<double>(0.5i));
    CHECK(solve(1i + y + y + 8i == 9i) == complex<double>(0i));
    CHECK(solve(6i + y + 2i == 12.5i) == complex<double>(4.5i));
    CHECK(solve(y + 2.5i + 4i == 8.5i) == complex<double>(2i));
    CHECK(solve(y + y + y + y == 1i) == complex<double>(0.25i));
}
//Count: 25
TEST_CASE("Test Subtraction Operator") {
    RealVariable x;
    ComplexVariable y;

    CHECK(solve(x - 4 == -2) == double(2));
    CHECK(solve(4 - x == -1) == double(5));
    CHECK(solve(x - x == 0) == double(5));
    CHECK(solve(10 - x - 4 == 3) == double(3));
    CHECK(solve(x - 2.5 - 4 == -6.5) == double(0));
    CHECK(solve(3 - x - 1 == -5) == double(7));
    CHECK(solve(x - x - x - x == -10) == double(5));
    CHECK(solve(2 - x - 1 - x == 1) == double(0));
    CHECK(solve(x - 1 == 1) == double(1));
    CHECK(solve(20 - x == 4.5) == double(15.5));
    CHECK(solve(x - 2 - x == -2) == double(0));
    CHECK(solve(7.5 - x - 1.5 == 1) == double(5));

    CHECK_THROWS(solve(x == x - 10));
    CHECK_THROWS(solve(x - 0 == x - 1));
    CHECK_THROWS(solve(2 - x == 4 - x));
    CHECK_THROWS(solve(2 - x + 10 == 1 - x + 2));
    CHECK_THROWS(solve(5 - x + 2 == 2 - x + 90));

    CHECK(solve(7i - y == 3i) == complex<double>(4i));
    CHECK(solve(-4i - y == 6i) == complex<double>(2i));
    CHECK(solve(y - 2i == 4i) == complex<double>(6i));
    CHECK(solve(4.5i - 1.5i - y == 6.5i) == complex<double>(0.5i));
    CHECK(solve(1i - y - y - 8i == 9i) == complex<double>(-2i));
    CHECK(solve(6i - y - 2i == 12.5i) == complex<double>(-8.5i));
    CHECK(solve(y - 2.5i - 4i == 8.5i) == complex<double>(15i));
    CHECK(solve(y - y - y - y == 1i) == complex<double>(-0.25i));
}
//Count: 20
TEST_CASE("Test Multiplication Operator") {
    RealVariable x;
    ComplexVariable y;

    CHECK(solve(2 * x + 4 == 6) == double(1));
    CHECK(solve(4 + 1 * x == 6) == double(2));
    CHECK(solve(x + 2 * x == 3) == double(1));
    CHECK(solve(10 + 4 * x + 4 == 18) == double(1));
    CHECK(solve(2 * x + 2.5 + 4 == 8.5) == double(1));
    CHECK(solve(4 * x == 0) == double(0));
    CHECK(solve(10 * x + 100 == -1 + 10 * x) == double(0));
    CHECK(solve(5 * x + 1 == 16) == double(3));
    CHECK(solve(x + 20 == 2 * x + 5) == double(15));
    CHECK(solve(2 * x + 1.5 == 0.5) == double(-0.5));

    CHECK_THROWS(solve(3 * x == 3 * x + 1));
    CHECK_THROWS(solve(0 * x == 1));
    CHECK_THROWS(solve(1 * x + 2 * x == -3.5 * x + 2));
    CHECK_THROWS(solve(10 * x + 1 == 0));
    CHECK_THROWS(solve(2 * x - 9 == 2 * x));

    CHECK(solve(2 * y - 1i == 1i) == complex<double>(1i));
    CHECK(solve(4i * y == 6i) == complex<double>(1.5));
    CHECK(solve(y * y == -1) == complex<double>(1i));
    CHECK(solve(5 * y == 20i) == complex<double>(4i));
    CHECK(solve(10 * y == 0.1i) == complex<double>(0.01i));
}
//Count: 15
TEST_CASE("Test Power Operator") {
    RealVariable x;
    ComplexVariable y;

    CHECK(solve((x ^ 2) == 81) == double(9));
    CHECK(solve((x ^ 2) == 100) == double(10));
    CHECK(solve((x ^ 2) == 36) == double(6));
    CHECK(solve((x ^ 2) == 0.25) == double(0.5));
    CHECK(solve((x ^ 5) == 3125) == double(5));
    CHECK(solve((x ^ 5) == 3125) == double(5));
    CHECK(solve((x ^ 2) == 0.09) == double(0.3));
    CHECK(solve((x ^ 3) == 216) == double(6));
    CHECK(solve((x ^ 10) == 1024) == double(2));
    CHECK(solve((x ^ 14) == 16384) == double(2));

    CHECK_THROWS(solve((x ^ 2) == -13));
    CHECK_THROWS(solve((x ^ 2) == -7));
    CHECK_THROWS(solve((x ^ 2) == -2.5));
    CHECK_THROWS(solve((x ^ 2) == -1023));

    CHECK(solve((y ^ 2) == -1) == complex<double>(1i));
}
//Count: 5
TEST_CASE("Test Division Operator") {
    RealVariable x;
    ComplexVariable y;

    CHECK(solve(3 * x / 3 + 4 == 6) == double(2));
    CHECK(solve(4 + 4 * x / 4 == 6) == double(2));
    CHECK(solve(x / 2 + x / 2 == 5) == double(5));
    CHECK(solve(10 + 4 * x / 2 + 4 == 18) == double(2));
    CHECK(solve(3 * x / 3 + 2.5 + 4 == 8.5) == double(2));
}
//Count: 5
TEST_CASE("Test Mixing Operators") {
    RealVariable x;
    ComplexVariable y;
    CHECK(solve(2 * x - 4 == 10) == double(7));
    CHECK(solve((x ^ 2) + 2 * x + 4.0 == 20 + 6.0 * x / 2 - x) == double(4));
    CHECK(solve((x ^ 2) - 1 == 0) == double(1));
    CHECK(solve((x ^ 2) - 1 * x - 6 == 0) == double(3));
    CHECK(solve((y ^ 2) + 2 * y + 4 == 20 + 6 * y / 2 - y) == complex<double>(4));
    CHECK(solve(2 * x + 3 == 18) == double(7.5));
    CHECK(solve(2 * (x ^ 2) - 4 * x - 6 == 0) == double(1));

    CHECK_THROWS(solve((x ^ 2) + 3 * x + 20 == 0));
    CHECK_THROWS(solve((x ^ 2) + 2 * x + 63 == 0));
    CHECK_THROWS(solve((x ^ 2) + x == -1));
    CHECK_THROWS(solve((x ^ 2) + 3 * x == -5));
}
