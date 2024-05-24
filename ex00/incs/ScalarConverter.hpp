/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:45:14 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/24 17:49:50 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Directive pour éviter les inclusions multiples d'un fichier d'en-tête */
#pragma once

/* Inclusion de la bibliothèque standard pour std::string */
#include <string>

/**
 *  Classe représentant un formulaire de demande de robotomie, dérivée de AForm
 */
class ScalarConverter
{
    public:
        /* Méthode statique pour convertir une chaîne de caractères */
        static void convert(const std::string & literal);

    private:
        /* Constructeur par défaut */
        ScalarConverter();

        /* Constructeur de copie */
        ScalarConverter(const ScalarConverter & other);

        /* Opérateur d'affectation */
        ScalarConverter & operator = (const ScalarConverter & other);
        
        /* Destructeur */
        ~ScalarConverter();
};
