/**
 * FILENAME: solver.hpp
 * 
 * AUTHOR: bmitay4
 * 
 * DATE: 2020-05
 * */

#ifndef _SOLVER_H
#define _SOLVER_H

#include <complex>
#include <iostream>

using namespace std;

namespace solver {
class RealVariable {
   private:
    //Class Variables
    double itsA, itsB, itsC;

   public:
    //Constructors
    RealVariable();
    RealVariable(double, double, double);

    //Getters
    double getA() {
        return itsA;
    }
    double getB() {
        return itsB;
    }
    double getC() {
        return itsC;
    }

    //Auxiliary Methods
    bool isLinear() {
        if (itsA == 0) return true;
        return false;
    }
    bool isQuadratic() {
        if (itsA != 0) return true;
        return false;
    }

    //Addition Operator (+)
    friend RealVariable operator+(RealVariable, const double);
    friend RealVariable operator+(const double, RealVariable);
    friend RealVariable operator+(RealVariable, RealVariable);

    //Subtraction Operator(-)
    friend RealVariable operator-(RealVariable, const double);
    friend RealVariable operator-(const double, RealVariable);
    friend RealVariable operator-(RealVariable, RealVariable);

    //Multiplication operator (*)
    friend RealVariable operator*(RealVariable, const double);
    friend RealVariable operator*(const double, RealVariable);

    //Power Operator(^)
    friend RealVariable operator^(RealVariable, const double);

    //Division Operator(/)
    friend RealVariable operator/(RealVariable, const double);

    //Comparison Operator(==)
    friend RealVariable operator==(RealVariable, const double);
    friend RealVariable operator==(const double, RealVariable);
    friend RealVariable operator==(RealVariable, RealVariable);
};
double solve(RealVariable);

class ComplexVariable {
   private:
    //Class Variables
    double itsA, itsB, itsC, itsImg;

   public:
    //Constructors
    ComplexVariable();
    ComplexVariable(double, double, double, double);

    //Getters
    double getA() {
        return itsA;
    }
    double getB() {
        return itsB;
    }
    double getC() {
        return itsC;
    }
    double getImg() {
        return itsImg;
    }

    //Auxiliary Methods
    bool isLinear() {
        if (itsA == 0) return true;
        return false;
    }
    bool isQuadratic() {
        if (itsA != 0) return true;
        return false;
    }

    //Addition Operator (+)
    friend ComplexVariable operator+(ComplexVariable, complex<double>);
    friend ComplexVariable operator+(complex<double>, ComplexVariable);
    friend ComplexVariable operator+(ComplexVariable, ComplexVariable);

    //Subtraction Operator(-)
    friend ComplexVariable operator-(ComplexVariable, complex<double>);
    friend ComplexVariable operator-(complex<double>, ComplexVariable);
    friend ComplexVariable operator-(ComplexVariable, ComplexVariable);

    //Multiplication operator (*)
    friend ComplexVariable operator*(ComplexVariable, double);
    friend ComplexVariable operator*(double, ComplexVariable);
    friend ComplexVariable operator*(ComplexVariable, complex<double>);
    friend ComplexVariable operator*(complex<double>, ComplexVariable);

    //Power Operator(^)
    friend ComplexVariable operator^(ComplexVariable, double);

    //Division Operator(/)
    friend ComplexVariable operator/(ComplexVariable, double);

    //Comparison Operator(==)
    friend ComplexVariable operator==(ComplexVariable, complex<double>);
    friend ComplexVariable operator==(ComplexVariable, ComplexVariable);
};
complex<double> solve(ComplexVariable);
}  // namespace solver

#endif