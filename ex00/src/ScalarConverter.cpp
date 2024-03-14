#include "../includes/ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib> // For strtol, strtof, strtod
#include <limits>  // Add this header for numeric_limits

ScalarConverter::ScalarConverter(void)
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &that)
{
    *this = that;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &that)
{
    if (this != &that)
        return (*this);
    return (*this);
}

ScalarConverter::~ScalarConverter()
{

}

char ScalarConverter::convertChar(const std::string& str) {
    if (str.size() == 1) {
        return str[0];
    } else {
        std::cerr << "Error: Input string for char conversion should have length 1." << std::endl;
        return '\0'; // Return null character on error
    }
}

int ScalarConverter::convertInt(const std::string& str) {
    return std::strtol(str.c_str(), nullptr, 10);
}

float ScalarConverter::convertFloat(const std::string& str) {
    std::istringstream iss(str);
    float result;
    iss >> result;
    if (iss.fail()) {
        if (str == "-inff" || str == "-inf" || str == "+inff" || str == "+inf" || str == "nanf" || str == "nan") {
            return std::numeric_limits<float>::quiet_NaN(); // Handle special cases
        } else {
            std::cerr << "Error: Failed to convert string to float." << std::endl;
            return 0.0f; // Return 0.0 on error
        }
    }
    return result;
}

double ScalarConverter::convertDouble(const std::string& str) {
    std::istringstream iss(str);
    double result;
    iss >> result;
    if (iss.fail()) {
        if (str == "-inf" || str == "+inf" || str == "nan") {
            return std::numeric_limits<double>::quiet_NaN(); // Handle special cases
        } else {
            std::cerr << "Error: Failed to convert string to double." << std::endl;
            return 0.0; // Return 0.0 on error
        }
    }
    return result;
}
