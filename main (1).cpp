/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main (1).cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 03:38:13 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/24 17:50:22 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclusion de la bibliothèque standard pour les flux d'entrée/sortie */
#include <iostream>

/* Inclusion de la bibliothèque standard pour la gestion des fichiers */
#include <fstream>

/* Inclusion de la bibliothèque standard pour la gestion des informations de type */
#include <typeinfo>

/* Inclusion du fichier d'en-tête de la classe AForm */
#include "../incs/AForm.hpp"

/* Inclusion du fichier d'en-tête de la classe Intern */
#include "../incs/Intern.hpp"

/* Inclusion du fichier d'en-tête de la classe Bureaucrat */
#include "../incs/Bureaucrat.hpp"

/* Inclusion du fichier d'en-tête de la classe ShrubberyCreationForm */
#include "../incs/ShrubberyCreationForm.hpp"

/* Inclusion du fichier d'en-tête de la classe RobotomyRequestForm */
#include "../incs/RobotomyRequestForm.hpp"

/* Inclusion du fichier d'en-tête de la classe PresidentialPardonForm */
#include "../incs/PresidentialPardonForm.hpp"

/**
 *  Macro pour vérifier une expression et afficher un message de test passé/échoué
 */
#define ASSERT_TEST(expression, message) \
	if (expression) { std::cout << "\033[32m[TEST PASSED]\033[0m " << message << std::endl; } \
	else { std::cout << "\033[31m[TEST FAILED]\033[0m " << message << std::endl; }

/* Définitions des codes de couleur ANSI pour la sortie console */
#define GREY        "\033[0;30m"
#define RED         "\033[0;31m"
#define GREEN       "\033[0;32m"
#define YELLOW      "\033[0;33m"
#define BLUE        "\033[0;34m"
#define MAGENTA     "\033[0;35m"
#define CYAN        "\033[0;36m"
#define NC          "\033[0m"

/**
 *  @brief Point d'entrée principal du programme
 */
int main()
{

	Intern intern;
	Bureaucrat ceo("CEO", 1);
	AForm* form;
	Bureaucrat *bureaucrat = NULL;
	Bureaucrat *copyBureaucrat = NULL;

	/**
	 * TEST MANDATORY
	*/
    std::cout << CYAN << "MANDATORY:" << NC << std::endl;
    {
        Intern someRandomIntern;
        AForm* rrf;

        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf) {
            Bureaucrat bob("Bob", 1);
            
            try {
                bob.signForm(*rrf);
                ASSERT_TEST(rrf->getIsSigned(), "RobotomyRequestForm signed.");
                bob.executeForm(*rrf);
                ASSERT_TEST(rrf->getIsSigned() && rrf->getGradeRequiredToExecute() >= bob.getGrade(), "RobotomyRequestForm executed.");
            } catch (std::exception &e) {
                std::cerr << "Exception: " << e.what() << std::endl;
                ASSERT_TEST(false, "Exception should not be thrown.");
            }

            delete rrf;
        } else {
            std::cerr << "Form creation failed!" << std::endl;
            ASSERT_TEST(false, "Form creation should not fail.");
        }
    }
	
	/**
	 * TEST CREATION OF BUREAUCRAT WITH VALID GRADE
	*/
	std::cout << std::endl << CYAN << "TEST CREATION OF BUREAUCRAT WITH VALID GRADE:" << NC  << std::endl;
	try
	{
		bureaucrat = new Bureaucrat("John Doe", 75);
		std::cout << *bureaucrat;
		ASSERT_TEST(bureaucrat->getGrade() == 75, "Grade 75.");
		delete bureaucrat;
		bureaucrat = NULL;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		ASSERT_TEST(false, "Should not throw an exception here.");
	}

	/**
	 * TEST CREATION OF BUREAUCRAT WITH TOO HIGH GRADE
	*/
	std::cout << CYAN << "\nTEST CREATION OF BUREAUCRAT WITH TOO HIGH GRADE:" << NC << std::endl;
	try
	{
		bureaucrat = new Bureaucrat("Jane Doe", 0);
		std::cout << *bureaucrat;
		delete bureaucrat;
		bureaucrat = NULL;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		ASSERT_TEST(true, "Correctly threw GradeTooHighException.");
	}
	catch (...)
	{
		ASSERT_TEST(false, "Wrong exception type caught.");
	}

	/**
	 * TEST CREATION OF BUREAUCRAT WITH TOO LOW GRADE:
	*/
	std::cout << CYAN << "\nTEST CREATION OF BUREAUCRAT WITH TOO LOW GRADE:" << NC << std::endl;
	try
	{
		bureaucrat = new Bureaucrat("Jim Doe", 151);
		std::cout << *bureaucrat;
		delete bureaucrat;
		bureaucrat = NULL;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		ASSERT_TEST(true, "Correctly threw GradeTooLowException.");
	}
	catch (...)
	{
		ASSERT_TEST(false, "Wrong exception type caught.");
	}

	/**
	 * TEST INCREMENTING AND DECREMENTING BUREAUCRAT'S GRADE
	*/
	std::cout << CYAN << "\nTEST INCREMENTING AND DECREMENTING BUREAUCRAT'S GRADE:" << NC << std::endl;
	try
	{
		bureaucrat = new Bureaucrat("Julia Doe", 10);
		std::cout << *bureaucrat;
		bureaucrat->incrementGrade();
		std::cout << BLUE << "\nAfter incrementing bureaucrat :" << NC << std::endl;
		std::cout << *bureaucrat;
		ASSERT_TEST(bureaucrat->getGrade() == 9, "Grade incremented to 9.");

		bureaucrat->decrementGrade();
		std::cout << BLUE << "\nAfter decrementing bureaucrat :" << NC << std::endl;

		std::cout << *bureaucrat;
		ASSERT_TEST(bureaucrat->getGrade() == 10, "Grade decremented to 10.");

		delete bureaucrat;
		bureaucrat = NULL;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		ASSERT_TEST(false, "No exception should be thrown here.");
	}

	/**
	 * TEST FOR COPY CONSTRUCTOR
	*/
	std::cout << CYAN << "\nTEST COPY CONSTRUCTOR:" << NC << std::endl;
	try
	{
		bureaucrat = new Bureaucrat("Original Bureaucrat", 50);
		std::cout << "Original Bureaucrat: " << *bureaucrat;

		copyBureaucrat = new Bureaucrat(*bureaucrat);
		std::cout << "Copy Bureaucrat: " << *copyBureaucrat;

		ASSERT_TEST(copyBureaucrat->getName() == bureaucrat->getName(), "Copy have the same name.");
		ASSERT_TEST(copyBureaucrat->getGrade() == bureaucrat->getGrade(), "Copy have the same grade.");

		copyBureaucrat->incrementGrade();
		std::cout << BLUE << "\nAfter incrementing copy:\n" << NC;
		std::cout << *copyBureaucrat;
		std::cout << *bureaucrat;
		ASSERT_TEST(copyBureaucrat->getGrade() == 49, "Grade of copy incremented.");
		ASSERT_TEST(bureaucrat->getGrade() == 50, "Grade of original unchanged.");

		delete bureaucrat;
		delete copyBureaucrat;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		ASSERT_TEST(false, "No exception should be thrown here.");
	}

	/**
	 * TEST FOR ASSIGNMENT OPERATOR
	*/
	std::cout << CYAN << "\nTEST ASSIGNMENT OPERATOR:" << NC << std::endl;
	try
	{
		bureaucrat = new Bureaucrat("First Bureaucrat", 75);
		copyBureaucrat = new Bureaucrat("Second Bureaucrat", 100);
		std::cout <<  BLUE << "Before assignment:" << NC << "\nOriginal: " << *bureaucrat << "Copy: " << *copyBureaucrat << std::endl;

		*copyBureaucrat = *bureaucrat;  // Using assignment operator
		std::cout << BLUE << "After assignment:" << NC << std::endl;
		std::cout << *bureaucrat;
		std::cout << *copyBureaucrat;

		ASSERT_TEST(copyBureaucrat->getName() == "Second Bureaucrat", "Name of copy unchanged.");
		ASSERT_TEST(copyBureaucrat->getGrade() == 75, "Grade of copy updated to 75.");

		copyBureaucrat->incrementGrade();
		std::cout << BLUE << "\nAfter incrementing Second Bureaucrat :" << NC << std::endl;

		std::cout << *copyBureaucrat;
		std::cout << *bureaucrat;

		ASSERT_TEST(copyBureaucrat->getGrade() == 74, "Grade of copy incremented.");
		ASSERT_TEST(bureaucrat->getGrade() == 75, "Grade of original unchanged.");

		delete bureaucrat;
		delete copyBureaucrat;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		ASSERT_TEST(false, "No exception should be thrown here.");
	}

	/*
	* TEST BUREAUCRAT CREATION AND FORM EXECUTION
	*/
	std::cout << std::endl << CYAN << "TEST BUREAUCRAT CREATION AND FORM EXECUTION:" << NC << std::endl;
	try
	{
		Bureaucrat bob("Bob", 1);
		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robot("Alice");
		PresidentialPardonForm pardon("Charlie");

		bob.signForm(shrub);
		bob.executeForm(shrub);
		ASSERT_TEST(shrub.getIsSigned(), "ShrubberyCreationForm signed.");
		ASSERT_TEST(shrub.getIsSigned() && shrub.getGradeRequiredToExecute() >= bob.getGrade(), "ShrubberyCreationForm executed.");

		bob.signForm(robot);
		bob.executeForm(robot);
		ASSERT_TEST(robot.getIsSigned(), "RobotomyRequestForm signed.");
		ASSERT_TEST(robot.getIsSigned() && robot.getGradeRequiredToExecute() >= bob.getGrade(), "RobotomyRequestForm executed.");

		bob.signForm(pardon);
		bob.executeForm(pardon);
		ASSERT_TEST(pardon.getIsSigned(), "PresidentialPardonForm signed.");
		ASSERT_TEST(pardon.getIsSigned() && pardon.getGradeRequiredToExecute() >= bob.getGrade(), "PresidentialPardonForm executed.");
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		ASSERT_TEST(false, "Exception should not be thrown.");
	}

	/*
	* TEST GETTERS IN AForm
	*/
	std::cout << CYAN << "\nTEST GETTERS IN AForm:" << NC << std::endl;
	try
	{
		ShrubberyCreationForm shrub("test");
		ASSERT_TEST(shrub.getName() == "ShrubberyCreationForm", "getName() works correctly.");
		ASSERT_TEST(!shrub.getIsSigned(), "getIsSigned() works correctly.");
		ASSERT_TEST(shrub.getGradeRequiredToSign() == 145, "getGradeRequiredToSign() works correctly.");
		ASSERT_TEST(shrub.getGradeRequiredToExecute() == 137, "getGradeRequiredToExecute() works correctly.");
	}
	catch (std::exception &e)
	{
		ASSERT_TEST(false, "Exception should not be thrown during getters tests.");
	}

	/**
	* TEST AForm CLASS NAME
	*/
	std::cout << CYAN << "\nTEST AForm CLASS NAME:" << NC << std::endl;
	ASSERT_TEST(std::string(typeid(AForm).name()) == "5AForm", "AForm class name is correct.");

	/*
	* TEST ShrubberyCreationForm REQUIREMENTS
	*/
	std::cout << CYAN << "\nTEST ShrubberyCreationForm REQUIREMENTS:" << NC << std::endl;
	try
	{
		ShrubberyCreationForm shrub("home");
		ASSERT_TEST(shrub.getGradeRequiredToSign() == 145, "ShrubberyCreationForm sign grade is 145.");
		ASSERT_TEST(shrub.getGradeRequiredToExecute() == 137, "ShrubberyCreationForm execute grade is 137.");
	}
	catch (std::exception &e)
	{
		ASSERT_TEST(false, "ShrubberyCreationForm constructor threw an exception.");
	}

	/*
	* TEST ShrubberyCreationForm FILE CREATION
	*/
	std::cout << CYAN << "\nTEST ShrubberyCreationForm:" << NC << std::endl;
	try
	{
		Bureaucrat bob("Bob", 1);
		ShrubberyCreationForm shrub("test_target");
		bob.signForm(shrub);

		/**
		 * EXÉCUTER LE FORMULAIRE AVEC EXECUTEFORM
		*/
		bob.executeForm(shrub);
		std::ifstream infile("test_target_shrubbery");
		ASSERT_TEST(infile.good(), "Shrubbery file created using executeForm.");
		infile.close();
		std::remove("test_target_shrubbery");

		/**
		 * EXÉCUTER LE FORMULAIRE AVEC EXECUTE
		*/
		shrub.execute(bob);
		infile.open("test_target_shrubbery");
		ASSERT_TEST(infile.good(), "Shrubbery file created using execute.");
		infile.close();
		std::remove("test_target_shrubbery");
	}
	catch (std::exception &e)
	{
		ASSERT_TEST(false, "Exception should not be thrown during Shrubbery creation/execution.");
	}

	/*
	* TEST RobotomyRequestForm REQUIREMENTS
	*/
	std::cout << CYAN << "\nTEST RobotomyRequestForm REQUIREMENTS:" << NC << std::endl;
	try
	{
		RobotomyRequestForm robot("Alice");
		ASSERT_TEST(robot.getGradeRequiredToSign() == 72, "RobotomyRequestForm sign grade is 72.");
		ASSERT_TEST(robot.getGradeRequiredToExecute() == 45, "RobotomyRequestForm execute grade is 45.");
	}
	catch (std::exception &e)
	{
		ASSERT_TEST(false, "RobotomyRequestForm constructor threw an exception.");
	}

	/*
	* TEST PresidentialPardonForm REQUIREMENTS
	*/
	std::cout << CYAN << "\nTEST PresidentialPardonForm REQUIREMENTS:" << NC << std::endl;
	try
	{
		PresidentialPardonForm pardon("Charlie");
		ASSERT_TEST(pardon.getGradeRequiredToSign() == 25, "PresidentialPardonForm sign grade is 25.");
		ASSERT_TEST(pardon.getGradeRequiredToExecute() == 5, "PresidentialPardonForm execute grade is 5.");
	}
	catch (std::exception &e)
	{
		ASSERT_TEST(false, "PresidentialPardonForm constructor threw an exception.");
	}

	// Note: Le test suivant est là pour illustrer qu'AForm est abstraite.
	// Cette partie du code ne peut pas être exécutée car AForm ne peut pas être instanciée directement.
	// /*
	// std::cout << CYAN << "\nTEST AForm CANNOT BE INSTANTIATED:" << NC << std::endl;
	// try {
	//     // Cette ligne devrait échouer car AForm est une classe abstraite.
	//     AForm *form = new AForm("TestForm", 50, 25);
	//     ASSERT_TEST(false, "AForm should not be instantiable directly.");
	// } catch (std::exception& e) {
	//     ASSERT_TEST(true, "Correctly caught exception for AForm instantiation.");
	// }
	// */

	/**
	 * TESTING FORM CREATION BY INTERN
	*/
	std::cout << CYAN << "\nTESTING FORM CREATION BY INTERN" << NC << std::endl;

	const char* formTypes[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	const char* targets[] = {"garden", "employee", "criminal"};

	for (int i = 0; i < 3; ++i)
	{
		form = intern.makeForm(formTypes[i], targets[i]);
		if (form)
		{
			std::cout << "Created: " << form->getName() << " for " << targets[i] << std::endl;
			ceo.signForm(*form);
			ceo.executeForm(*form);
			ASSERT_TEST(form->getIsSigned(), "Form be signed");
			ASSERT_TEST(form->execute(ceo), "Form executed without error");
			delete form;
		}
		else
		{
			std::cout << "Failed to create form: " << formTypes[i] << std::endl;
		}
		std::cout << std::endl;
	}

	/**
	 * TEST ERROR HANDLING WITH AN UNKNOWN FORM
	*/
	std::cout << CYAN << "TESTING ERROR HANDLING WITH UNKNOWN FORM" << NC << std::endl;
	form = intern.makeForm("unknown form", "nowhere");
	ASSERT_TEST(!form, "Unknown form not created");

	/**
	 * TEST CHECK INTERN HANDLING OF INVALID FORM NAMES
	*/
	std::cout << std::endl << CYAN << "TESTING INVALID FORM NAME HANDLING" << NC << std::endl;
	const char* invalidNames[] = {"", "robomancy request", "presidental party"};

	for (int i = 0; i < 3; ++i)
	{
		form = intern.makeForm(invalidNames[i], "target");
		ASSERT_TEST(!form, "Invalid form name, does not create form");
	}

	/**
	 * TESTING EMPTY TARGET HANDLING
	*/
	std::cout << std::endl << CYAN << "TESTING EMPTY TARGET HANDLING" << NC << std::endl;
	try {
		form = intern.makeForm("shrubbery creation", "");
		ASSERT_TEST(false, "Empty target should throw an exception");
	} catch (const std::invalid_argument& e) {
		ASSERT_TEST(true, "Caught exception for empty target");
	}

	/**
	 * TEST CREATION OF PRESIDENTIALPARDONFORM WITH EMPTY TARGET
	 */
	std::cout << CYAN << "\nTEST CREATION OF PRESIDENTIALPARDONFORM WITH EMPTY TARGET:" << NC << std::endl;
	try
	{
		PresidentialPardonForm emptyTargetForm;
		ASSERT_TEST(false, "Should have thrown an exception for empty target.");
	}
	catch (const std::invalid_argument& e)
	{
		ASSERT_TEST(true, "Correctly threw an exception for empty target: " + std::string(e.what()));
	}
	catch (...)
	{
		ASSERT_TEST(false, "Wrong exception type caught for empty target.");
	}

	/**
	 * TEST OF PRESIDENTIALPARDONFORM WITH ASSIGNMENT OPERATOR WITH EMPTY TARGET
	 */
	std::cout << CYAN << "\nTEST OF PRESIDENTIALPARDONFORM WITH ASSIGNMENT OPERATOR WITH EMPTY TARGET:" << NC << std::endl;
	try
	{
		PresidentialPardonForm form1("");
		PresidentialPardonForm form2;
		form2 = form1;
		ASSERT_TEST(false, "Should have thrown an exception for empty target in assignment.");
	}
	catch (const std::invalid_argument& e)
	{
		ASSERT_TEST(true, "Correctly threw an exception for empty target in assignment: " + std::string(e.what()));
	}
	catch (...)
	{
		ASSERT_TEST(false, "Wrong exception type caught for empty target in assignment.");
	}

	/**
	 * TEST CREATION OF ROBOTOMYREQUESTFORM WITH EMPTY TARGET
	 */
	std::cout << CYAN << "\nTEST CREATION OF ROBOTOMYREQUESTFORM WITH EMPTY TARGET:" << NC << std::endl;
	try
	{
		RobotomyRequestForm emptyTargetForm;
		ASSERT_TEST(false, "Should have thrown an exception for empty target.");
	}
	catch (const std::invalid_argument& e)
	{
		ASSERT_TEST(true, "Correctly threw an exception for empty target: " + std::string(e.what()));
	}
	catch (...)
	{
		ASSERT_TEST(false, "Wrong exception type caught for empty target.");
	}

	/**
	 * TEST OF ROBOTOMYREQUESTFORM WITH ASSIGNMENT OPERATOR WITH EMPTY TARGET
	*/
	std::cout << CYAN << "\nTEST OF ROBOTOMYREQUESTFORM WITH ASSIGNMENT OPERATOR WITH EMPTY TARGET:" << NC << std::endl;
	try
	{
		RobotomyRequestForm form1("");
		RobotomyRequestForm form2;
		form2 = form1;
		ASSERT_TEST(false, "Should have thrown an exception for empty target in assignment.");
	}
	catch (const std::invalid_argument& e)
	{
		ASSERT_TEST(true, "Correctly threw an exception for empty target in assignment: " + std::string(e.what()));
	}
	catch (...)
	{
		ASSERT_TEST(false, "Wrong exception type caught for empty target in assignment.");
	}

	/**
	 * TEST CREATION OF SHRUBBERYCREATIONFORM WITH EMPTY TARGET
	 */
	std::cout << CYAN << "\nTEST CREATION OF SHRUBBERYCREATIONFORM WITH EMPTY TARGET:" << NC << std::endl;
	try
	{
		ShrubberyCreationForm emptyTargetForm;
		ASSERT_TEST(false, "Should have thrown an exception for empty target.");
	}
	catch (const std::invalid_argument& e)
	{
		ASSERT_TEST(true, "Correctly threw an exception for empty target: " + std::string(e.what()));
	}
	catch (...)
	{
		ASSERT_TEST(false, "Wrong exception type caught for empty target.");
	}

	/**
	 * TEST OF SHRUBBERYCREATIONFORM WITH ASSIGNMENT OPERATOR WITH EMPTY TARGET
	*/
	std::cout << CYAN << "\nTEST OF SHRUBBERYCREATIONFORM WITH ASSIGNMENT OPERATOR WITH EMPTY TARGET:" << NC << std::endl;
	try
	{
		ShrubberyCreationForm form1("");
		ShrubberyCreationForm form2;
		form2 = form1;
		ASSERT_TEST(false, "Should have thrown an exception for empty target in assignment.");
	}
	catch (const std::invalid_argument& e)
	{
		ASSERT_TEST(true, "Correctly threw an exception for empty target in assignment: " + std::string(e.what()));
	}
	catch (...)
	{
		ASSERT_TEST(false, "Wrong exception type caught for empty target in assignment.");
	}

		return 0;
	}

/* MAIN.CPP */