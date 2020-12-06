/**
 * FILENAME: sovler.hpp
 * 
 * AUTHOR: bmitay4
 * 
 * DATE: 2020-04
 * */

#ifndef _SOLVER_H
#define _SOLVER_H

#include <complex>
#include <iostream>

using namespace std;

namespace solver {
class RealVariable {
   private:
    double itsValue;

   public:
    //Constructors
    RealVariable();

    //Auxiliary Methods
    static bool isCoefficientExist(RealVariable&);
    static bool isLinearEquation(RealVariable&);
    static bool isQuadraticEquation(RealVariable&);

    //Overload Operatos
    //Addition Operator (+)
    friend RealVariable& operator+(RealVariable&, RealVariable&);
    friend RealVariable& operator+(RealVariable&, double);
    friend RealVariable& operator+(double, RealVariable&);

    //Subtraction Operator(-)
    friend RealVariable& operator-(RealVariable&, RealVariable&);
    friend RealVariable& operator-(RealVariable&, double);
    friend RealVariable& operator-(double, RealVariable&);

    //Multiplication operator (*)
    friend RealVariable& operator*(RealVariable&, RealVariable&);
    friend RealVariable& operator*(RealVariable&, double);
    friend RealVariable& operator*(double, RealVariable&);

    //Power Operator(^)
    friend RealVariable& operator^(RealVariable&, RealVariable&);
    friend RealVariable& operator^(RealVariable&, double);
    friend RealVariable& operator^(double, RealVariable&);

    //Division Operator(/)
    friend RealVariable& operator/(RealVariable&, RealVariable&);
    friend RealVariable& operator/(RealVariable&, double);
    friend RealVariable& operator/(double, RealVariable&);

    //Comparison Operator(==)
    friend RealVariable& operator==(RealVariable&, RealVariable&);
    friend RealVariable& operator==(RealVariable&, double);
};
class ComplexVariable {
   private:
    complex<double> itsValue;

   public:
    ComplexVariable();

    friend ComplexVariable& operator+(ComplexVariable&, ComplexVariable&);
    friend ComplexVariable& operator+(ComplexVariable&, complex<double>);
    friend ComplexVariable& operator+(complex<double>, ComplexVariable&);

    friend ComplexVariable& operator-(ComplexVariable&, ComplexVariable&);
    friend ComplexVariable& operator-(ComplexVariable&, complex<double>);
    friend ComplexVariable& operator-(complex<double>, ComplexVariable&);

    friend ComplexVariable& operator*(ComplexVariable&, ComplexVariable&);
    friend ComplexVariable& operator*(ComplexVariable&, complex<double>);
    friend ComplexVariable& operator*(complex<double>, ComplexVariable&);

    friend ComplexVariable& operator^(ComplexVariable&, ComplexVariable&);
    friend ComplexVariable& operator^(ComplexVariable&, complex<double>);
    friend ComplexVariable& operator^(complex<double>, ComplexVariable&);

    friend ComplexVariable& operator/(ComplexVariable&, ComplexVariable&);
    friend ComplexVariable& operator/(ComplexVariable&, complex<double>);
    friend ComplexVariable& operator/(complex<double>, ComplexVariable&);

    friend ComplexVariable& operator==(ComplexVariable&, ComplexVariable&);
    friend ComplexVariable& operator==(ComplexVariable&, complex<double>);
};

double solve(RealVariable&);
complex<double> solve(ComplexVariable&);

}  // namespace solver

#endif