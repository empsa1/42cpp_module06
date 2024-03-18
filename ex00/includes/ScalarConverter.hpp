#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <limits>
#include "Utils.hpp"
#include <cmath>
#include <cfloat>
#include <climits>

class ImpossibleConversionException : public std::exception {
    public:
        virtual const char* what() const throw()
        {
            return RED IMPOSSIBLE_CONVERSION RESET;
        }
};

class ScalarConverter {
private:
    ScalarConverter(); // Private constructor to prevent instantiation
    ScalarConverter(const ScalarConverter& that); // Private copy constructor
    ScalarConverter& operator=(const ScalarConverter& that); // Private copy assignment operator
    ~ScalarConverter(); // Private destructor

    static float toFloat(std::string& string);
    static double toDouble(std::string& string);
    static int toInt(std::string& string);

public:
    static void convert(std::string string_literal);
};

#endif