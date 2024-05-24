/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:19:30 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/24 17:49:12 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* Inclusion de la bibliothèque standard pour l'utilisation de flux d'entrée/sortie standard */
#include <iostream>

/* Inclusion de la bibliothèque standard pour obtenir les limites des types numériques */
#include <limits>

/* Inclusion de la bibliothèque standard pour std::strtol, std::strtod */
#include <cstdlib>

/* Inclusion de la bibliothèque standard pour std::isprint, std::isdigit */
#include <cctype>

/* Inclusion de la bibliothèque standard pour std::fixed, std::setprecision */
#include <cerrno>

/* Inclusion de la bibliothèque standard pour les limites des types entiers et flottants */
#include <climits>

/* Inclusion de la bibliothèque standard pour les limites des types flottants */
#include <cfloat>

/* Inclusion de la bibliothèque standard pour les fonctions mathématiques */
#include <cmath>

/* Inclusion de la bibliothèque standard pour manipuler la sortie formatée */
#include <iomanip>

/**
 * @brief Construct a new Scalar Converter:: Scalar Converter object
 */
ScalarConverter::ScalarConverter()
{}

/**
 *  Constructeur de copie de la classe ScalarConverter
 */
ScalarConverter::ScalarConverter(const ScalarConverter & other)
{ 
	(void)other;
}

/**
 *  Opérateur d'affectation de la classe ScalarConverter
 */
ScalarConverter & ScalarConverter::operator = (const ScalarConverter & other)
{ 
	(void)other;
	return *this;
}

/**
 *  Destructeur de la classe ScalarConverter
 */
ScalarConverter::~ScalarConverter()
{}

/**
 * @brief Convertit une chaîne de caractères en types scalaires (char, int, float, double)
 */
void ScalarConverter::convert(const std::string& literal)
{
	char *end;
	errno = 0;

	/* Check for special nan or nanf values */ 
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
		return;
	}
	
	/* Check for special floating-point values */
	if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: +inff\n";
		std::cout << "double: +inf\n";
		return;
	}

	/*	Check for -inf or -inff values */	
	if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: -inff\n";
		std::cout << "double: -inf\n";
		return;
	}

	/* Check if it's a char */
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
	{
		char c = literal[0];
		std::cout << "char: \'" << c << "\'\n";
		std::cout << "int: " << static_cast<int>(c) << "\n";
		std::cout << "float: " << static_cast<float>(c) << "f\n";
		std::cout << "double: " << static_cast<double>(c) << "\n";
		return;
	}

	/* Check if it's an int */
	long int i = std::strtol(literal.c_str(), &end, 10);
	if (*end == '\0' && errno != ERANGE && i >= INT_MIN && i <= INT_MAX)
	{
		if (i < ' ' || i > '~' || i == '0')
			std::cout << "char: Non displayable\n";
		else
			std::cout << "char: \'" << static_cast<char>(i) << "\'\n";
		std::cout << "int: " << i << "\n";
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f\n";
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << "\n";
		return;
	}

	/* Check if it's a float */
	float f = std::strtof(literal.c_str(), &end);
	if (*end == 'f' && *(end + 1) == '\0' && errno != ERANGE) {
		std::cout << "char: ";
		if (f >= 0 && f <= 127 && std::isprint(static_cast<int>(f)))
			std::cout << "'" << static_cast<char>(f) << "'\n";
		else
			std::cout << "Non displayable\n";
		std::cout << "int: ";
		if (f >= static_cast<float>(INT_MIN) && f <= static_cast<float>(INT_MAX))
			std::cout << static_cast<int>(f) << "\n";
		else
			std::cout << "impossible\n";
		std::cout << "float: " << f << "f\n";
		std::cout << "double: " << static_cast<double>(f) << "\n";
		return;
	}

	/* Check if it's a double */
	double d = std::strtod(literal.c_str(), &end);
	if (*end == '\0' && errno != ERANGE) {
		if (d < 32.0 || d > 126.0 || std::isnan(d) || std::isinf(d))
			std::cout << "char: Non displayable\n";
		else
			std::cout << "char: \'" << static_cast<char>(d) << "\'\n";
		if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX) || std::isnan(d) || std::isinf(d))
			std::cout << "int: impossible\n";
		else
			std::cout << "int: " << std::fixed << std::setprecision(1) << static_cast<int>(d) << "\n";
		std::cout << "float: " << static_cast<float>(d) << "f\n";
		std::cout << "double: " << d << "\n";
		return;
	}

	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: impossible\n";
	std::cout << "double: impossible\n";
}
