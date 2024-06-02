# **CPP06 - École 42 | Paris**

## Introduction
CPP06 focuses on type conversion and casting in C++. The exercises are designed to provide practical experience with different casting operators, ensuring a solid understanding of type conversion mechanisms in compliance with the C++98 standard.

## Project Structure
This module consists of a series of exercises that explore various aspects of type conversion and serialization:

### Exercise 00: Conversion of Scalar Types
- **Directory:** `ex00/`
- **Files to submit:**
  - `incs/ScalarConverter.hpp`
  - `Makefile`
  - `srcs/main.cpp`
  - `srcs/ScalarConverter.cpp`


#### Functionality
Introduces the `ScalarConverter` class, which contains a static method `convert`. This method takes a string representation of a C++ literal and outputs its value as `char`, `int`, `float`, and `double`. The class is non-instantiable and handles edge cases like non-displayable characters and pseudo literals.

### Exercise 01: Serialization
- **Directory:** `ex01/`
- **Files to submit:**
  - `incs/Data.hpp`
  - `incs/Serializer.hpp`
  - `Makefile`
  - `srcs/Data.cpp`
  - `srcs/main.cpp`
  - `srcs/Serializer.cpp`


#### Functionality
Implements a `Serializer` class with static methods `serialize` and `deserialize`. The `serialize` method converts a pointer to an unsigned integer (`uintptr_t`), and the `deserialize` method converts it back to a pointer. The exercise includes creating a `Data` structure to test these methods.

### Exercise 02: Identify Real Type
- **Directory:** `ex02/`
- **Files to submit:**
  - `incs/A.hpp`
  - `incs/Base.hpp`
  - `incs/B.hpp`
  - `incs/C.hpp`
  - `incs/generate.hpp`
  - `incs/identify.hpp`
  - `Makefile`
  - `srcs/Base.cpp`
  - `srcs/generate.cpp`
  - `srcs/identify.cpp`
  - `srcs/main.cpp`


#### Functionality
Implements a `Base` class with a public virtual destructor and three derived classes (`A`, `B`, and `C`). The exercise includes functions to generate a random instance of `A`, `B`, or `C` and identify the real type of an object pointed to by a `Base` pointer or reference, without using the `typeinfo` header.

## Compilation and Execution
Navigate to the specific exercise directory and use the `make` command to compile the projects. Each executable can be run directly to demonstrate the functionalities implemented.

## Ressources Utilisées
- [Apprenez à programmer en C++ sur OpenClassrooms](https://openclassrooms.com/fr/courses/1894236-apprenez-a-programmer-en-c)
- [Programmez en orienté objet avec C++ sur OpenClassrooms](https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c)
- [Apprenez à programmer en C++ sur codecademy](https://www.codecademy.com/catalog/language/c-plus-plus)
- [Introduction à C++ sur Sololearn](https://www.sololearn.com/fr/learn/courses/c-plus-plus-introduction)
- [C++ Intermédiaire sur Sololearn](https://www.sololearn.com/fr/learn/courses/c-plus-plus-intermediate)
