/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:45:00 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/30 14:59:10 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Directive pour éviter les inclusions multiples d'un fichier d'en-tête */
#pragma once

/* Inclusion de la classe Data */
#include "Data.hpp"

/* Inclusion de la bibliothèque stands  sard pour les types entiers */
#include <cstddef>

/* Inclusion de la bibliothèque standard pour les types entiers */
#include <stdint.h>

/**
 * @brief Serializer class
 */ 
class Serializer
{
    public:
        /* Sérialise un pointeur de type Data en uintptr_t */
        static std::size_t serialize(Data * ptr);

        /* Désérialise un uintptr_t en un pointeur de type Data */
        static Data * deserialize(uintptr_t raw);
        
    private:
        Serializer();
        Serializer(const Serializer & other);
        Serializer & operator = (const Serializer & other);
        ~Serializer();
};
