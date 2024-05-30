/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:49:18 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/30 22:07:35 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclusion de la classe Serializer */
#include "../incs/Serializer.hpp"

/**
 * @brief Sérialise un pointeur de type Data en uintptr_t
 */
std::size_t Serializer::serialize(Data * ptr)
{
    return reinterpret_cast<std::size_t>(ptr);
}

/**
 * @brief Désérialise un uintptr_t en un pointeur de type Data
 */
Data* Serializer::deserialize(uintptr_t raw)
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
Serializer & Serializer::operator=(const Serializer & other)
{ 
    (void)other;
    return *this;
}

/**
 * @brief Destroy the Serializer:: Serializer object
 */
Serializer::~Serializer()
{}
