#include "solver.hpp"

#include <math.h>

#include <complex>
#include <iostream>

#include "myException.hpp"

using namespace std;
using namespace solver;

//RealVariable Constructors
RealVariable::RealVariable() : itsA(0), itsB(1), itsC(0) {
}
RealVariable::RealVariable(double a, double b, double c) : itsA(a), itsB(b), itsC(c) {
}
//Print
void print(RealVariable obj) {
    cout << "A " << obj.getA() << endl;
    cout << "B " << obj.getB() << endl;
    cout << "C " << obj.getC() << endl;
}
//Overload Operator +
RealVariable solver::operator+(RealVariable obj, const double value) {
    return RealVariable(obj.itsA, obj.itsB, obj.itsC + value);
}
RealVariable solver::operator+(const double value, RealVariable obj) {
    return obj + value;
}
RealVariable solver::operator+(RealVariable objX, RealVariable objY) {
    return RealVariable(objX.itsA + objY.itsA, objX.itsB + objY.itsB, objX.itsC + objY.itsC);
}
//Overload Operator -
RealVariable solver::operator-(RealVariable obj, const double value) {
    return RealVariable(obj.itsA, obj.itsB, obj.itsC - value);
}
RealVariable solver::operator-(const double value, RealVariable obj) {
    return RealVariable(obj.itsA, -obj.itsB, value - obj.itsC);
}
RealVariable solver::operator-(RealVariable objX, RealVariable objY) {
    return RealVariable(objX.itsA - objY.itsA, objX.itsB - objY.itsB, objX.itsC - objY.itsC);
}
//Overload Operator *
RealVariable solver::operator*(RealVariable obj, const double value) {
    return RealVariable(obj.itsA * value, obj.itsB * value, obj.itsC * value);
}
RealVariable solver::operator*(const double value, RealVariable obj) {
    return obj * value;
}
//Overload Operator ^
RealVariable solver::operator^(RealVariable obj, const double value) {
    if (value != 2 || obj.itsA != 0)
        throw Exception("No third-degree or higher equation is supported!");
    else
        return RealVariable(1, obj.itsB - 1, obj.itsC);
}
//Overload Operator /
RealVariable solver::operator/(RealVariable obj, const double value) {
    if (value == 0)
        throw Exception("Error, divide by 0!");
    return RealVariable(obj.itsA / value, obj.itsB / value, obj.itsC / value);
}
//Overload Operator ==
RealVariable solver::operator==(RealVariable obj, const double value) {
    return RealVariable(obj.itsA, obj.itsB, obj.itsC - value);
}
RealVariable solver::operator==(const double value, RealVariable obj) {
    return RealVariable(obj.itsA, obj.itsB, obj.itsC - value);
}
RealVariable solver::operator==(RealVariable objX, RealVariable objY) {
    return RealVariable(objX.itsA - objY.itsA, objX.itsB - objY.itsB, objX.itsC - objY.itsC);
}
//calcLinear Function
double calcLinear(RealVariable obj) {
    if (obj.getB() == 0 && obj.getC() == 0)
        return 5;  //random number, all number is acceptable
    if (obj.getB() == 0 && obj.getC() != 0)
        throw Exception("Equation has no real solution!");
    else
        return obj.getC() / ((-1) * obj.getB());
}
//calcQuadratic Function
double calcQuadratic(RealVariable obj) {
    if (obj.getB() == 0) {
        if (((-1) * obj.getC()) < 0)
            throw Exception("Equation has no real solution!");
        else if (obj.getA() != 0)
            return sqrt(((-1) * obj.getC()) / obj.getA());
        else
            return sqrt(((-1) * obj.getC()));
    } else {
        double value = (pow(obj.getB(), 2) - 4 * obj.getA() * obj.getC());
        if (value < 0) throw Exception("Equation has no real solution!");
        double numerator = sqrt(value);
        double denominator = 2 * obj.getA();
        return ((-1) * obj.getB() + numerator) / denominator;
    }
}
//RealVariable solve function
double solver::solve(RealVariable obj) {
    if (obj.isLinear())
        return calcLinear(obj);
    else if (obj.isQuadratic())
        return calcQuadratic(obj);
    else
        throw Exception("Equation has no real solution!");
}

//ComplexVariable Constructors
ComplexVariable::ComplexVariable() : itsA(0), itsB(1), itsC(0), itsImg(0) {
}
ComplexVariable::ComplexVariable(double a, double b, double c, double i) : itsA(a), itsB(b), itsC(c), itsImg(i) {
}
//Print
void print(ComplexVariable obj) {
    cout << "A " << obj.getA() << endl;
    cout << "B " << obj.getB() << endl;
    cout << "C " << obj.getC() << endl;
    cout << "Img " << obj.getImg() << endl;
}
//Overload Operator +
ComplexVariable solver::operator+(ComplexVariable obj, complex<double> value) {
    return ComplexVariable(obj.itsA, obj.itsB, obj.itsC + value.real(), obj.itsImg + value.imag());
}
ComplexVariable solver::operator+(complex<double> value, ComplexVariable obj) {
    return obj + value;
}
ComplexVariable solver::operator+(ComplexVariable objX, ComplexVariable objY) {
    return ComplexVariable(objX.itsA + objY.itsA, objX.itsB + objY.itsB, objX.itsC + objY.itsC, objX.itsImg + objY.itsImg);
}
//Overload Operator -
ComplexVariable solver::operator-(ComplexVariable obj, complex<double> value) {
    return ComplexVariable(obj.itsA, obj.itsB, obj.itsC - value.real(), obj.itsImg - value.imag());
}
ComplexVariable solver::operator-(complex<double> value, ComplexVariable obj) {
    return ComplexVariable(obj.itsA, obj.itsB, value.real() - obj.itsC, value.imag() - obj.itsImg);
}
ComplexVariable solver::operator-(ComplexVariable objX, ComplexVariable objY) {
    return ComplexVariable(objX.itsA - objY.itsA, objX.itsB - objY.itsB, objX.itsC - objY.itsC, objX.itsImg - objY.itsImg);
}

//Overload Operator *
ComplexVariable solver::operator*(ComplexVariable obj, double value) {
    return ComplexVariable(obj.itsA * value, obj.itsB * value, obj.itsC * value, obj.itsImg * value);
}
ComplexVariable solver::operator*(double value, ComplexVariable obj) {
    return obj * value;
}
ComplexVariable solver::operator*(ComplexVariable obj, complex<double> value) {
    return ComplexVariable(obj.itsA * value.real(), obj.itsB * value.real(), obj.itsC * value.real(), obj.itsImg * value.imag());
}
ComplexVariable solver::operator*(complex<double> value, ComplexVariable obj) {
    return obj * value;
}

//Overload Operator ^
ComplexVariable solver::operator^(ComplexVariable obj, double value) {
    if (value != 2 || obj.itsA != 0)
        throw Exception("No third-degree or higher equation is supported!");
    else
        return ComplexVariable(1, obj.itsB - 1, obj.itsC, obj.itsImg);
}

//Overload Operator /
ComplexVariable solver::operator/(ComplexVariable obj, double value) {
    if (value == 0)
        throw Exception("Error, divide by 0!");
    return ComplexVariable(obj.itsA / value, obj.itsB / value, obj.itsC / value, obj.itsImg / value);
}

//Comparison Operator(==)
ComplexVariable solver::operator==(ComplexVariable objX, ComplexVariable objY) {
    return ComplexVariable(objX.itsA - objY.itsA, objX.itsB - objY.itsB, objX.itsC - objY.itsC, objX.itsImg - objY.itsImg);
}
ComplexVariable solver::operator==(ComplexVariable obj, complex<double> value) {
    return ComplexVariable(obj.itsA, obj.itsB, obj.itsC - value.real(), obj.itsImg - value.imag());
}

//calcLinear Function
complex<double> calcLinear(ComplexVariable obj) {
    if (obj.getB() == 0 && (obj.getC() == 0 || obj.getImg() == 0))
        return true;  //random number, all number is acceptable
    if (obj.getB() == 0 && (obj.getC() != 0 || obj.getImg() != 0))
        throw Exception("Equation has no solution!");
    else if (obj.getB() != 0 && obj.getC() != 0) {
        complex<double> ans(obj.getC() / ((-1) * obj.getB()), 0);
        return ans;
    } else {
        complex<double> ans(0, obj.getImg() / ((-1) * obj.getB()));
        return ans;
    }
}
//calcQuadratic Function
complex<double> calcQuadratic(ComplexVariable obj) {
    if (obj.getB() == 0)
        if (((-1) * obj.getC()) < 0) {
            if (obj.getA() != 0) {
                double temp = (-1) * obj.getC() / obj.getA();
                return std::sqrt((std::complex<double>)(0, temp));
            } else
                return std::sqrt(std::complex<double>(((-1) * obj.getC()), 0));
        }
    double value = (pow(obj.getB(), 2) - 4 * obj.getA() * obj.getC());
    if (value < 0) {
        complex<double> numerator = std::sqrt(std::complex<double>(value, 0));
        double denominator = 2 * obj.getA();
        return ((-1) * obj.getB() + numerator) / denominator;
    } else {
        double numerator = sqrt(value);
        double denominator = 2 * obj.getA();
        return ((-1) * obj.getB() + numerator) / denominator;
    }
}
//ComplexVariable solve function
complex<double> solver::solve(ComplexVariable obj) {
    if (obj.isLinear())
        return calcLinear(obj);
    else if (obj.isQuadratic())
        return calcQuadratic(obj);
    else
        throw Exception("Equation has no solution!");
}