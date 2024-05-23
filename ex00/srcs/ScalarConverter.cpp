#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <cerrno>
#include <climits>
#include <cfloat>
#include <cmath>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal) {
    char *end;
    errno = 0;

    // Check if it's a char
    if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
        char c = literal[0];
        std::cout << "char: '" << c << "'\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";
        std::cout << "float: " << static_cast<float>(c) << ".0f\n";
        std::cout << "double: " << static_cast<double>(c) << ".0\n";
        return;
    }

    // Check if it's an int
    long int l = std::strtol(literal.c_str(), &end, 10);
    if (*end == '\0' && errno != ERANGE && l <= INT_MAX && l >= INT_MIN) {
        int i = static_cast<int>(l);
        std::cout << "char: ";
        if (std::isprint(i))
            std::cout << "'" << static_cast<char>(i) << "'\n";
        else
            std::cout << "Non displayable\n";
        std::cout << "int: " << i << "\n";
        std::cout << "float: " << static_cast<float>(i) << ".0f\n";
        std::cout << "double: " << static_cast<double>(i) << ".0\n";
        return;
    }

    // Check if it's a float
    float f = std::strtof(literal.c_str(), &end);
    if (*end == 'f' && *(end + 1) == '\0' && errno != ERANGE) {
        std::cout << "char: ";
        if (f >= 0 && f <= 127 && std::isprint(static_cast<int>(f)))
            std::cout << "'" << static_cast<char>(f) << "'\n";
        else
            std::cout << "Non displayable\n";
        std::cout << "int: ";
        if (f >= INT_MIN && f <= INT_MAX)
            std::cout << static_cast<int>(f) << "\n";
        else
            std::cout << "impossible\n";
        std::cout << "float: " << f << "f\n";
        std::cout << "double: " << static_cast<double>(f) << "\n";
        return;
    }

    // Check if it's a double
    double d = std::strtod(literal.c_str(), &end);
    if (*end == '\0' && errno != ERANGE) {
        std::cout << "char: ";
        if (d >= 0 && d <= 127 && std::isprint(static_cast<int>(d)))
            std::cout << "'" << static_cast<char>(d) << "'\n";
        else
            std::cout << "Non displayable\n";
        std::cout << "int: ";
        if (d >= INT_MIN && d <= INT_MAX)
            std::cout << static_cast<int>(d) << "\n";
        else
            std::cout << "impossible\n";
        std::cout << "float: ";
        if (d >= -FLT_MAX && d <= FLT_MAX)
            std::cout << static_cast<float>(d) << "f\n";
        else
            std::cout << "impossible\n";
        std::cout << "double: " << d << "\n";
        return;
    }

    // Check special float values
    if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << literal << "\n";
        std::cout << "double: " << literal.substr(0, literal.size() - 1) << "\n";
        return;
    }

    // Check special double values
    if (literal == "nan" || literal == "+inf" || literal == "-inf") {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << literal << "f\n";
        std::cout << "double: " << literal << "\n";
        return;
    }

    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: impossible\n";
    std::cout << "double: impossible\n";
}
