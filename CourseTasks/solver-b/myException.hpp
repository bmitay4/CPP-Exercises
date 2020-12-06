/**
 * FILENAME: myException.hpp
 * 
 * AUTHORS: bmitay4
 * 
 * DATE: 2020-04
 * */

#ifndef _Exception_H
#define _Exception_H
#include <exception>
#include <string>
using namespace std;

class Exception : public std::exception {
   private:
    string itsMsg;

   public:
    Exception(const string& value) {
        itsMsg = value;
    }

    virtual const char* what() const noexcept override {
        return itsMsg.c_str();
    }
};

#endif