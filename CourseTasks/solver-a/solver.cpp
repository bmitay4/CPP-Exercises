/**
 * FILENAME: sovler.cpp
 * 
 * AUTHOR: bmitay4
 * 
 * DATE: 2020-04
 * */

#include "solver.hpp"

#include <math.h>

using namespace std;
using namespace solver;

//RealVariable Class
//RealVariable Constructors
RealVariable::RealVariable() {
    itsValue = 0;
}

//Overload Operatos
//Multiplication operator (*)
RealVariable& solver::operator*(RealVariable& objX, RealVariable& objY) {
    return objX;
}
RealVariable& solver::operator*(double, RealVariable& obj) {
    return obj;
}
RealVariable& solver::operator*(RealVariable& obj, double) {
    return obj;
}

//Addition Operator (+)
RealVariable& solver::operator+(RealVariable& obj, double value) {
    return obj;
}
RealVariable& solver::operator+(double value, RealVariable& obj) {
    return obj + value;
}
RealVariable& solver::operator+(RealVariable& objX, RealVariable& objY) {
    return objX + objY.itsValue;
}

//Subtraction Operator(-)
RealVariable& solver::operator-(RealVariable& objX, RealVariable& objY) {
    return objX;
}
RealVariable& solver::operator-(RealVariable& obj, double) {
    return obj;
}
RealVariable& solver::operator-(double, RealVariable& obj) {
    return obj;
}

//Power Operator(^)
RealVariable& solver::operator^(RealVariable& objX, RealVariable& objY) {
    return objX;
}
RealVariable& solver::operator^(RealVariable& obj, double) {
    return obj;
}
RealVariable& solver::operator^(double, RealVariable& obj) {
    return obj;
}

//Division Operator(/)
RealVariable& solver::operator/(RealVariable& objX, RealVariable& objY) {
    return objX;
}
RealVariable& solver::operator/(RealVariable& obj, double) {
    return obj;
}
RealVariable& solver::operator/(double, RealVariable& obj) {
    return obj;
}

//Comparison Operator(==)
RealVariable& solver::operator==(RealVariable& objX, RealVariable& objY) {
    return objX;
}
RealVariable& solver::operator==(RealVariable& obj, double value) {
    return obj;
}

//Solve Function for RealVariable Object
double solver::solve(RealVariable& obj) {
    return -1;
}

/************************/

//ComplexVariable Class
//ComplexVariable Constructors
ComplexVariable::ComplexVariable() {
    itsValue = 0;
}

//Overload Operatos
//Multiplication operator (*)
ComplexVariable& solver::operator*(ComplexVariable& objX, ComplexVariable& objY) {
    return objX;
}
ComplexVariable& solver::operator*(complex<double>, ComplexVariable& obj) {
    return obj;
}
ComplexVariable& solver::operator*(ComplexVariable& obj, complex<double>) {
    return obj;
}

//Addition Operator (+)
ComplexVariable& solver::operator+(ComplexVariable& objX, ComplexVariable& objY) {
    return objX;
}
ComplexVariable& solver::operator+(ComplexVariable& obj, complex<double>) {
    return obj;
}
ComplexVariable& solver::operator+(complex<double>, ComplexVariable& obj) {
    return obj;
}

//Subtraction Operator(-)
ComplexVariable& solver::operator-(ComplexVariable& objX, ComplexVariable& objY) {
    return objX;
}
ComplexVariable& solver::operator-(ComplexVariable& obj, complex<double>) {
    return obj;
}
ComplexVariable& solver::operator-(complex<double>, ComplexVariable& obj) {
    return obj;
}

//Power Operator(^)
ComplexVariable& solver::operator^(ComplexVariable& objX, ComplexVariable& objY) {
    return objX;
}
ComplexVariable& solver::operator^(ComplexVariable& obj, complex<double>) {
    return obj;
}
ComplexVariable& solver::operator^(complex<double>, ComplexVariable& obj) {
    return obj;
}

//Division Operator(/)
ComplexVariable& solver::operator/(ComplexVariable& objX, ComplexVariable& objY) {
    return objX;
}
ComplexVariable& solver::operator/(ComplexVariable& obj, complex<double>) {
    return obj;
}
ComplexVariable& solver::operator/(complex<double>, ComplexVariable& obj) {
    return obj;
}

//Comparison Operator(==)
ComplexVariable& solver::operator==(ComplexVariable& objX, ComplexVariable& objY) {
    return objX;
}
ComplexVariable& solver::operator==(ComplexVariable& obj, complex<double>) {
    return obj;
}
//Solve Function For RealVariable Object
complex<double> solver::solve(ComplexVariable& obj) {
    return 0.5;
}