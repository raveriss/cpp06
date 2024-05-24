/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:01:09 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/24 17:33:50 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclusion du fichier d'en-tête de la classe RobotomyRequestForm */
#include "../incs/RobotomyRequestForm.hpp"

/**
 *  Constructeur par défaut de la classe RobotomyRequestForm
 */
RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45), _target("")
{
	std::cout << "Error: Target must be specified '" << _target << "' is not recognized." << std::endl;
	throw std::invalid_argument("Target must be specified");
}

/**
 *  @brief Constructeur avec paramètre de la classe RobotomyRequestForm
 */
RobotomyRequestForm::RobotomyRequestForm(const std::string & target)
: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	if (_target.empty())
	{
		std::cout << "Error: Target must be specified '" << _target << "' is not recognized." << std::endl;
		throw std::invalid_argument("Target must be specified");
	}
}

/**
 *  Constructeur de copie de la classe RobotomyRequestForm
 */
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & other)
: AForm(other), _target(other._target)
{
	if (_target.empty())
	{
		std::cout << "Error: Target must be specified '" << _target << "' is not recognized." << std::endl;
		throw std::invalid_argument("Target must be specified");
	}
}

/**
 *  Opérateur d'affectation de la classe RobotomyRequestForm
 */
RobotomyRequestForm & RobotomyRequestForm::operator = (const RobotomyRequestForm & other)
{
	if (this != & other)
	{
		AForm::operator = (other);
		if (other._target.empty())
		{
			std::cout << "Error: Target must be specified '" << _target << " is not recognized." << std::endl;
			throw std::invalid_argument("Target must be specified");
		}
		_target = other._target;
	}
	return *this;
}

/**
 *  Destructeur de la classe RobotomyRequestForm
 */
RobotomyRequestForm::~RobotomyRequestForm()
{}

/**
 *  Exécute l'action spécifique de RobotomyRequestForm
 */
void RobotomyRequestForm::executeAction() const
{
	std::cout << "Drilling noises...\n";
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully.\n";
	else
		std::cout << "Robotomy of " << _target << " failed.\n";
}

/**
 *  Accesseur pour la cible
 */
std::string RobotomyRequestForm::getTarget() const
{
	return _target;
}

/* ROBOTOMYREQUESTFORM.CPP */