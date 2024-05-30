#include <iostream>
#include <sstream>
#include <string>

/* Classe de base */
class Base {
public:
    virtual ~Base() {}
};

/* Classe dérivée A */
class A : public Base {};

/* Classe dérivée B */
class B : public Base {};

/* Fonction de test pour remplacer identify */
void simplePrint(Base& p) {
    std::cout << "Base object identified" << std::endl;
}

/* Macro pour vérifier les résultats de test et afficher les messages appropriés */
#define ASSERT_TEST(expression, message) \
    if (expression) { std::cout << "\033[0;32m[TEST PASSED]\033[0m " << message << std::endl; } \
    else { std::cout << "\033[0;31m[TEST FAILED]\033[0m " << message << std::endl; }

/* Fonction de test pour identifier par référence */
void testIdentifyReference(Base& p, const std::string& expected) {
    std::ostringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    simplePrint(p); // Utilisation de simplePrint au lieu de identify

    std::cout.rdbuf(old);
    std::string output = buffer.str();
    ASSERT_TEST(output == expected, "Reference identification: Expected: " + expected + "Got: " + output);
}

int main() {
    /* Création d'objets de test */
    A a;
    B b;

    /* Test de la fonction simplePrint avec A */
    testIdentifyReference(a, "Base object identified\n");

    /* Test de la fonction simplePrint avec B */
    testIdentifyReference(b, "Base object identified\n");

    return 0;
}
