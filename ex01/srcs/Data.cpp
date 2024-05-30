/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:43:21 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/30 22:27:25 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Data.hpp"

/**
 * @brief Constructeur par défaut initialisant id à 0 et name à "default"
 */
Data::Data()
: id(0), name("default")
{}

/**
 * @brief Constructeur de copie initialisant avec les valeurs de l'autre instance
 */
Data::Data(const Data& other)
: id(other.id), name(other.name) 
{}

/**
 * @brief Opérateur d'affectation de la classe Data
 */
Data& Data::operator=(const Data& other)
{
    if (this != &other)
    {
        id = other.id;
        name = other.name;
    }
    return *this;
}

/**
 * @brief Destroy the Data:: Data object
 */
Data::~Data()
{}

/* Data.cpp */