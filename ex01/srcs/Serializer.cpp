/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:49:18 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/28 12:04:05 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclusion de la classe Serializer */
#include "Serializer.hpp"

std::size_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<std::size_t>(ptr);
}

Data* Serializer::deserialize(std::size_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

/**
 * @brief Construct a new Serializer:: Serializer object
 */
Serializer::Serializer()
{}

/**
 * @brief Construct a new Serializer:: Serializer object
 */
Serializer::Serializer(const Serializer & other)
{
    (void)other;
}

/**
 * @brief Opérateur d'affectation de la classe Serializer
 */
Serializer& Serializer::operator=(const Serializer& other)
{ 
    (void)other;
    return *this;
}

/**
 * @brief Destroy the Serializer:: Serializer object
 */
Serializer::~Serializer() {}
