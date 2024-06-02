/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:46:13 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/03 00:36:31 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclusion des classes Base, A, B et C */
#include "../incs/Base.hpp"
#include "../incs/A.hpp"
#include "../incs/B.hpp"
#include "../incs/C.hpp"
#include "../incs/identify.hpp"
#include "../incs/generate.hpp"
#include <ctime>
#include <cstdlib>

/* Inclusion de la bibliothèque standard pour std::cout */
#include <iostream>

/* Inclusion de la bibliothèque standard pour std::ostringstream */
#include <sstream>

/* Definitions of ANSI color codes for console output */
#define GREY        "\033[0;30m"
#define RED         "\033[0;31m"
#define GREEN       "\033[0;32m"
#define YELLOW      "\033[0;33m"
#define BLUE        "\033[0;34m"
#define MAGENTA     "\033[0;35m"
#define CYAN        "\033[0;36m"
#define NC          "\033[0m"

/* Macro pour vérifier les résultats de test et afficher les messages appropriés */
#define ASSERT_TEST(expression, message) \
    if (expression) { std::cout << GREEN "[TEST PASSED] " NC << message; } \
    else { std::cout << RED "[TEST FAILED] " NC << message; }

/**
 * Fonction pour tester l'identification d'un pointeur Base*
 */
void testIdentifyPointer(Base* p, const std::string& expected)
{
    /* Création d'un objet ostringstream pour capturer la sortie */
    std::ostringstream buffer;

    /* Creation d'un pointeur rootCoutStream de type std::streambuf pour sauvegarder le tampon de flux courant de std::cout */
    std::streambuf *rootCoutStream;

    /* Sauvegarde du tampon de flux courant de std::cout */
    rootCoutStream = std::cout.rdbuf();

    /* Redirection de std::cout vers le tampon de flux buffer */
    std::cout.rdbuf(buffer.rdbuf());

    identify(p);

    /* Restauration du tampon de flux d'origine de std::cout */
    std::cout.rdbuf(rootCoutStream);

    /* Capture the output in a string */
    std::string output = buffer.str();
    
    std::string message = "Pointer identification: Expected: " + (expected.empty() ? "NULL\n" : expected) + "Got: " + (output.empty() ? "NULL" : output);
    ASSERT_TEST(output == expected, message);
}

/**
 * Fonction pour tester l'identification d'une référence Base&
 */
void testIdentifyReference(Base& p, const std::string& expected)
{
    /* Création d'un objet ostringstream pour capturer la sortie */
    std::ostringstream buffer;

    /* Creation d'un pointeur rootCoutStream de type std::streambuf pour sauvegarder le tampon de flux courant de std::cout */
    std::streambuf *rootCoutStream;

    /* Sauvegarde du tampon de flux courant de std::cout */
    rootCoutStream = std::cout.rdbuf();

    /* Redirection de std::cout vers le tampon de flux buffer */
    std::cout.rdbuf(buffer.rdbuf());

    identify(p);

    /* Restauration du tampon de flux d'origine de std::cout */
    std::cout.rdbuf(rootCoutStream);

    /* Capture the output in a string */
    std::string output = buffer.str();
    
    /* Print the expected and actual output */
    ASSERT_TEST(output == expected, "Reference identification: Expected: " + expected + "Got: " + output);
}

/**
 * Fonction pour tester la génération et l'identification d'un objet
 */
void testGenerateAndIdentify(int iteration)
{
    Base* p = generate();
    
    /* Création d'un objet ostringstream pour capturer la sortie */
    std::ostringstream expectedBuffer;

    /* Affichage de l'itération actuelle */
    expectedBuffer << "\nIteration " << iteration << " - Generated object: ";
    
    /* Creation d'un pointeur rootCoutStream de type std::streambuf pour sauvegarder le tampon de flux courant de std::cout */
    std::streambuf* rootCoutStream;
    
    /* Sauvegarde du tampon de flux courant de std::cout */
    rootCoutStream = std::cout.rdbuf();
    
    /* Redirection de std::cout vers le tampon de flux expectedBuffer */
    std::cout.rdbuf(expectedBuffer.rdbuf());
    
    identify(p);

    /* Capture the output in a string */
    std::string expectedOutput = expectedBuffer.str();

    /* Restauration du tampon de flux d'origine de std::cout */
    std::cout.rdbuf(rootCoutStream);
    
    /* Print the expected output for the current iteration */
    std::cout << expectedOutput;

    /* Création d'un objet ostringstream pour capturer la sortie */
    std::ostringstream pointerBuffer;

    /* Sauvegarde du tampon de flux courant de std::cout */
    rootCoutStream = std::cout.rdbuf();

    /* Redirection de std::cout vers le tampon de flux pointerBuffer */
    std::cout.rdbuf(pointerBuffer.rdbuf());
    
    identify(p);

    /* Capture the output in a string */
    std::string pointerOutput = pointerBuffer.str();

    /* Restauration du tampon de flux d'origine de std::cout */
    std::cout.rdbuf(rootCoutStream);

    /* Print the expected and actual output */
    ASSERT_TEST(pointerOutput == expectedOutput.substr(expectedOutput.find(':') + 2), 
                "Identify by pointer: Expected: " + expectedOutput.substr(expectedOutput.find(':') + 2) + "Got: " + pointerOutput);

    /* Capture the output of identify(Base& p) */
    std::ostringstream referenceBuffer;

    /* Sauvegarde du tampon de flux courant de std::cout */
    rootCoutStream = std::cout.rdbuf();

    /* Redirection de std::cout vers le tampon de flux referenceBuffer */
    std::cout.rdbuf(referenceBuffer.rdbuf());
    
    identify(*p);

    /* Capture the output in a string */
    std::string referenceOutput = referenceBuffer.str();

    /* Restauration du tampon de flux d'origine de std::cout */
    std::cout.rdbuf(rootCoutStream);

    /* Print the expected and actual output */
    ASSERT_TEST(referenceOutput == expectedOutput.substr(expectedOutput.find(':') + 2), 
                "Identify by reference: Expected: " + expectedOutput.substr(expectedOutput.find(':') + 2) + "Got: " + referenceOutput);

    delete p;
}

int main()
{
    /* Initialisation du générateur de nombres aléatoires une seule fois */
    std::srand(static_cast<unsigned int>(std::time(0)));

    /* Test de génération et identification */
    std::cout << CYAN << "RUNNING GENERATE AND IDENTIFY TESTS..." << NC << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        testGenerateAndIdentify(i);
    }

    /* Test de tous les cas possibles pour identifier(Base*) */
    std::cout << CYAN << "\nTESTING IDENTIFY(Base*)..." << NC << std::endl;
    A a;
    B b;
    C c;
    testIdentifyPointer(&a, "A\n");
    testIdentifyPointer(&b, "B\n");
    testIdentifyPointer(&c, "C\n");

    /* Test de tous les cas possibles pour identifier(Base&) */
    std::cout << CYAN << "\nTESTING IDENTIFY(Base&)..." << NC << std::endl;
    testIdentifyReference(a, "A\n");
    testIdentifyReference(b, "B\n");
    testIdentifyReference(c, "C\n");

    /* Test d'un pointeur nul */
    std::cout << CYAN << "\nTESTING IDENTIFY(NULL)..." << NC << std::endl;
    Base* nullPtr = NULL;
    testIdentifyPointer(nullPtr, "");
    std::cout << std::endl;
    
    return 0;
}

/* main.cpp */