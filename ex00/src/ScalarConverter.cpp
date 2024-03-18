#include "../includes/ScalarConverter.hpp"
#include "../includes/Utils.hpp"

float ScalarConverter::toFloat(std::string &string) {
    std::istringstream iss(string);
    float result;
    if (!(iss >> result)) {
        throw (ImpossibleConversionException());
    }
    if (std::abs(result) == __FLT_MAX__)
        throw (std::out_of_range(OUT_OF_BOUNDS));
    return result;
}

double ScalarConverter::toDouble(std::string &string) {
    std::istringstream iss(string);
    double result;
    if (!(iss >> result)) {
        throw (ImpossibleConversionException());
    }
    if (std::abs(result) == __DBL_MAX__)
        throw (std::out_of_range(OUT_OF_BOUNDS));
    return result;
}

int ScalarConverter::toInt(std::string &string) {
    std::istringstream iss(string);
    int result;
    if (!(iss >> result)) {
        throw (ImpossibleConversionException());
    }
    if (std::abs(result) == __INT_MAX__)
        throw (std::out_of_range(OUT_OF_BOUNDS));
    return result;
}

bool isDouble(const std::string &str)
{
    return (str.find_first_not_of(DOUBLE_ARRAY) == std::string::npos && str.find(".") != std::string::npos
		&& (str.find("-") == 0 || str.find("-") == std::string::npos))
		|| ( str == NEG_INF || str == POS_INF || str == _NAN);
}

bool isFloat(const std::string &str)
{
    return (str.find_first_not_of(FLOAT_ARRAY) == std::string::npos && str.find(".") != std::string::npos
		&& str.find("f", str.length() - 1)!= std::string::npos && (str.find("-") == 0 || str.find("-") == std::string::npos))
		|| ( str == NEG_INFF || str == POS_INFF || str == NANF) ;
}

bool isInt(const std::string &str)
{
    return str.find_first_not_of(INT_ARRAY) == std::string::npos && ((str.find("-") == 0 && str.length() > 1 ) || str.find("-") == std::string::npos);
}

void ScalarConverter::convert(std::string string_literal) {
    int integer_value;
    float float_value;
    double double_value;
    char char_value;
    int i = -1;
    std::string array[] = {"-inf", "-inff", "+inf", "+inff", "nan"};

    while (++i < 5)
    {
        if (array[i] == string_literal)
        {
            std::cout << P_CHAR IMPOSSIBLE << P_INTEGER IMPOSSIBLE;
            if (string_literal == "-inff" || string_literal == "-inf")
            {
                std::cout << P_FLOAT NEG_INFF << P_DOUBLE NEG_INF;
            }
            else if (string_literal == "nan" || string_literal == "nanf")
            {
                std::cout << P_FLOAT NANF << P_DOUBLE _NAN;
            }
            else if (string_literal == "+inff" || string_literal == "+inf")
            {
                std::cout << P_FLOAT POS_INFF << P_DOUBLE POS_INF;
            }
            return ;
        }
    }
    try
    {
        if (isDouble(string_literal))
        {
            double_value = toDouble(string_literal);
            char_value = static_cast<char>(double_value);
            integer_value = static_cast<int>(double_value);
            float_value = static_cast<float>(double_value);
        }
        else if (isFloat(string_literal))
        {
            float_value = toFloat(string_literal);
            char_value = static_cast<char>(float_value);
            integer_value = static_cast<int>(float_value);
            double_value = static_cast<double>(float_value);
        }
        else if (isInt(string_literal))
        {
            integer_value = toInt(string_literal);
            char_value = static_cast<char>(integer_value);
            float_value = static_cast<float>(integer_value);
            double_value = static_cast<double>(integer_value);
        }
    }
    catch (std::out_of_range& e)
    {
        std::cerr << e.what() << std::endl;
        return ;
    }
     if (integer_value < 0 || integer_value > 256 || !isprint(integer_value))
        std::cout << P_CHAR NON_DISPLAYABLE;
    else
        std::cout << P_CHAR << "'" << char_value << "'\n";
    std::cout << P_INTEGER << integer_value << "\n";
    if (double_value == integer_value && double_value > -1000000 && double_value < 1000000)
    {
        std::cout << P_FLOAT << float_value << ".0f\n";
        std::cout << P_DOUBLE << double_value << ".0\n";
        return;
    }
    std::cout << P_FLOAT << float_value << "f\n";
    std::cout << P_DOUBLE << double_value << "\n";
    return;
}

