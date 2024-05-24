/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:00:00 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/24 16:17:50 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <cstring>

/* Definitions of ANSI color codes for console output */
#define GREY        "\033[0;30m"
#define RED         "\033[0;31m"
#define GREEN       "\033[0;32m"
#define YELLOW      "\033[0;33m"
#define BLUE        "\033[0;34m"
#define MAGENTA     "\033[0;35m"
#define CYAN        "\033[0;36m"
#define NC          "\033[0m"

/**
 *  Macro for asserting test results and displaying appropriate messages
 */
#define ASSERT_TEST(expression, message) \
	if (expression) { std::cout << "\033[32m[TEST PASSED]\033[0m " << message << std::endl; } \
	else { std::cout << "\033[31m[TEST FAILED]\033[0m " << message << std::endl; }


void testConversion(const std::string& input, const std::string& expectedOutput) {
    std::ostringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    
    ScalarConverter::convert(input);
    
    std::cout.rdbuf(old);
    std::string output = buffer.str();
    ASSERT_TEST(output == expectedOutput, "Input: " + input + "\nExpected:\n" + expectedOutput + "\nGot:\n" + output);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <literal>\n";
        return 1;
    }
    
    ScalarConverter::convert(argv[1]);
    
    if (strcmp(argv[1], "tester") == 0)
    {
        std::cout << std::endl << CYAN << "MANDATORY TESTS:" << NC << std::endl;

        testConversion("0", "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0\n");
        testConversion("nan", "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n");
        testConversion("42.0f", "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n");

        std::cout << CYAN << "\nADDITIONAL TESTS:" << NC << std::endl;

        // Test cases for char conversions
        testConversion("a", "char: 'a'\nint: 97\nfloat: 97.0f\ndouble: 97.0\n");
        testConversion("z", "char: 'z'\nint: 122\nfloat: 122.0f\ndouble: 122.0\n");

        // Test cases for int conversions
        testConversion("42", "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n");
        testConversion("-42", "char: Non displayable\nint: -42\nfloat: -42.0f\ndouble: -42.0\n");

        // Test cases for float conversions
        testConversion("-42.0f", "char: Non displayable\nint: -42\nfloat: -42.0f\ndouble: -42.0\n");
        testConversion("nanf", "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n");
        testConversion("+inff", "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n");
        testConversion("-inff", "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n");

        // Test cases for double conversions
        testConversion("42.0", "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n");
        testConversion("-42.0", "char: Non displayable\nint: -42\nfloat: -42.0f\ndouble: -42.0\n");
        testConversion("+inf", "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n");
        testConversion("-inf", "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n");

        // Test cases for invalid inputs
        testConversion("hello", "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n");
        testConversion("42.0a", "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n");
    }

    return 0;
}
