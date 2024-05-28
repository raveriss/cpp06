/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:45:00 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/28 11:59:25 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* Inclusion de la classe Data */
#include "Data.hpp"

/* Inclusion de la bibliothèque standard pour les types entiers */
#include <cstddef>

/**
 * @brief Serializer class
 */ 
class Serializer
{
    public:
        /* Sérialise un pointeur de type Data en uintptr_t */
        static std::size_t serialize(Data* ptr);

        /* Désérialise un uintptr_t en un pointeur de type Data */
        static Data * deserialize(std::size_t raw);
        
    private:
        Serializer();
        Serializer(const Serializer & other);
        Serializer & operator = (const Serializer & other);
        ~Serializer();
};
