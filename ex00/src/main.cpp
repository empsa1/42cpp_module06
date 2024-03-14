#include <iostream>
#include "ScalarConverter.cpp"

int main() {
    std::cout << "Char conversion: " << ScalarConverter::convertChar("A") << std::endl;
    std::cout << "Int conversion: " << ScalarConverter::convertInt("42") << std::endl;
    std::cout << "Float conversion: " << ScalarConverter::convertFloat("3.14") << std::endl;
    std::cout << "Double conversion: " << ScalarConverter::convertDouble("2.718") << std::endl;

    return 0;
}