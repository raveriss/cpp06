/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:00:00 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/28 14:58:35 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Serializer.hpp"
#include <iostream>
#include <string>
#include <sstream> // Pour std::ostringstream
#include <cstring>
#include <climits>

/**
 * @brief Macro test expression, affiche succès/échec, message personnalisé
 */
#define ASSERT_TEST(expression, message) \
    if (expression) { std::cout << "\033[32m[TEST PASSED]\033[0m " << message << std::endl; } \
    else { std::cout << "\033[31m[TEST FAILED]\033[0m " << message << std::endl; }

/** 
 * Convertit std::size_t en std::string
 */
std::string toString(std::size_t value)
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

/** 
 * Convertit int en std::string
 */
std::string toString(int value)
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

/** 
 * Teste la sérialisation et désérialisation des pointeurs Data
 */
void testPointerSerialization()
{
    std::cout << "\033[36mPOINTER TESTS:\033[0m" << std::endl;

    Data data1;
    data1.id = 123;
    data1.name = "PointerTest";

    Data* dataPtr1 = &data1;
    std::size_t raw = Serializer::serialize(dataPtr1);
    Data* deserialized = Serializer::deserialize(raw);

    ASSERT_TEST(deserialized == dataPtr1, "Pointer equality test");

    Data data2;
    data2.id = 456;
    data2.name = "PointerTest2";

    Data* dataPtr2 = &data2;
    raw = Serializer::serialize(dataPtr2);
    deserialized = Serializer::deserialize(raw);

    ASSERT_TEST(deserialized == dataPtr2, "Pointer equality test with another instance");
}

/** 
 * Teste la sérialisation et désérialisation des données
 */
void testSerialization(const Data& original)
{
    std::size_t raw = Serializer::serialize(const_cast<Data*>(&original));
    Data* deserialized = Serializer::deserialize(raw);

    bool testPassed = (deserialized == &original) &&
                      (deserialized->id == original.id) &&
                      (deserialized->name == original.name);

    ASSERT_TEST(testPassed, "\nOriginal: " + toString(reinterpret_cast<std::size_t>(&original)) +
                "\nDeserialized: " + toString(reinterpret_cast<std::size_t>(deserialized)) +
                "\nID: " + toString(deserialized->id) +
                "\nName: " + deserialized->name + "\n");
}

/** 
 * Point d'entrée principal du programme
 */
int main()
{
    std::cout << "\033[36mMANDATORY TESTS:\033[0m" << std::endl;

    Data original;
    original.id = 42;
    original.name = "Test";

    std::size_t raw = Serializer::serialize(&original);
    Data* deserialized = Serializer::deserialize(raw);

    std::cout << "Original: " << &original << ", ID: " << original.id << ", Name: " << original.name << std::endl;
    std::cout << "Deserialized: " << deserialized << ", ID: " << deserialized->id << ", Name: " << deserialized->name << std::endl;


    std::cout << "\033[36m\nADDITIONAL TESTS:\033[0m" << std::endl;

    Data data2;
    data2.id = 0;
    data2.name = "Zero";
    testSerialization(data2);

    Data data3;
    data3.id = -1;
    data3.name = "Negative";
    testSerialization(data3);

    Data data4;
    data4.id = INT_MAX;
    data4.name = "MaxInt";
    testSerialization(data4);

    Data data5;
    data5.id = INT_MIN;
    data5.name = "MinInt";
    testSerialization(data5);

    Data data6;
    data6.id = 123456;
    data6.name = "LargeNumber";
    testSerialization(data6);

    testPointerSerialization();

    return 0;
}