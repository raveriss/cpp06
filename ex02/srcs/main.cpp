#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "../incs/identify.hpp"
#include "../incs/generate.hpp"
#include <sstream> // Inclusion pour std::ostringstream
#include <typeinfo>

/* Definitions of ANSI color codes for console output */
#define GREY        "\033[0;30m"
#define RED         "\033[0;31m"
#define GREEN       "\033[0;32m"
#define YELLOW      "\033[0;33m"
#define BLUE        "\033[0;34m"
#define MAGENTA     "\033[0;35m"
#define CYAN        "\033[0;36m"
#define NC          "\033[0m"

// Macro pour vérifier les résultats de test et afficher les messages appropriés
#define ASSERT_TEST(expression, message) \
    if (expression) { std::cout << GREEN "[TEST PASSED] " NC << message; } \
    else { std::cout << RED "[TEST FAILED] " NC << message; }

/**
 * Fonction pour tester l'identification d'un pointeur Base*
 */
void testIdentifyPointer(Base* p, const std::string& expected) {
    std::ostringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    identify(p);

    std::cout.rdbuf(old);
    std::string output = buffer.str();
    ASSERT_TEST(output == expected, "Pointer identification: Expected: " + expected + "Got: " + output);
}


/**
 * Fonction pour tester l'identification d'une référence Base&
 */
void testIdentifyReference(Base& p, const std::string& expected) {
    std::ostringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    identify(p);

    std::cout.rdbuf(old);
    std::string output = buffer.str();
    ASSERT_TEST(output == expected, "Reference identification: Expected: " + expected + "Got: " + output);
}


/**
 * Fonction pour tester la génération et l'identification d'un objet
 */
void testGenerateAndIdentify(int iteration) {
    Base* p = generate();
    
    // Capture the expected output
    std::ostringstream expectedBuffer;
    expectedBuffer << "\nIteration " << iteration << " - Generated object: ";
    std::streambuf* old = std::cout.rdbuf(expectedBuffer.rdbuf());
    identify(p);
    std::string expectedOutput = expectedBuffer.str();
    std::cout.rdbuf(old);
    
    // Print the expected output for the current iteration
    std::cout << expectedOutput;

    // Capture and test identify(Base* p)
    std::ostringstream pointerBuffer;
    old = std::cout.rdbuf(pointerBuffer.rdbuf());
    identify(p);
    std::string pointerOutput = pointerBuffer.str();
    std::cout.rdbuf(old);
    ASSERT_TEST(pointerOutput == expectedOutput.substr(expectedOutput.find(':') + 2), 
                "Identify by pointer: Expected: " + expectedOutput.substr(expectedOutput.find(':') + 2) + "Got: " + pointerOutput);

    // Capture and test identify(Base& p)
    std::ostringstream referenceBuffer;
    old = std::cout.rdbuf(referenceBuffer.rdbuf());
    identify(*p);
    std::string referenceOutput = referenceBuffer.str();
    std::cout.rdbuf(old);
    ASSERT_TEST(referenceOutput == expectedOutput.substr(expectedOutput.find(':') + 2), 
                "Identify by reference: Expected: " + expectedOutput.substr(expectedOutput.find(':') + 2) + "Got: " + referenceOutput);

    delete p;
}


int main()
{
    // Test de génération et identification
    std::cout << CYAN << "RUNNING GENERATE AND IDENTIFY TESTS..." << NC << std::endl;
    for (int i = 0; i < 10; ++i) {
        testGenerateAndIdentify(i);
    }

    // Test de tous les cas possibles pour identifier(Base*)
    std::cout << CYAN << "\nTESTING IDENTIFY(Base*)..." << NC << std::endl;
    A a;
    B b;
    C c;
    testIdentifyPointer(&a, "A\n");
    testIdentifyPointer(&b, "B\n");
    testIdentifyPointer(&c, "C\n");

    // Test de tous les cas possibles pour identifier(Base&)
    std::cout << CYAN << "\nTESTING IDENTIFY(Base&)..." << NC << std::endl;
    testIdentifyReference(a, "A\n");
    testIdentifyReference(b, "B\n");
    testIdentifyReference(c, "C\n");

    // Test d'un pointeur nul
    std::cout << CYAN << "\nTESTING IDENTIFY(NULL)..." << NC << std::endl;
    Base* nullPtr = NULL;
    testIdentifyPointer(nullPtr, "");

    // Test de références invalides en utilisant des blocs try-catch pour éviter les crash
    std::cout << CYAN << "\n\nTESTING INVALID REFERENCE IDENTIFICATION..." << NC<< std::endl;
    try
    {
        identify(dynamic_cast<Base&>(*nullPtr));
        std::cout << GREEN "[TEST PASSED] " NC "Invalid reference identification: No exception caught\n";
    }
    catch (...)
    {
        std::cout << RED "[TEST FAILED] " NC "Invalid reference identification: Caught unknown exception\n";
    }

    return 0;
}

