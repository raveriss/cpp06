/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:42:06 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/30 14:59:03 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Directive pour éviter les inclusions multiples d'un fichier d'en-tête */
#pragma once

/* Inclusion des bibliothèques standard pour std::string */
#include <string>

/**
 * @brief Classe Data contenant un id et un nom
 */
struct Data
{
    int id;
    std::string name;

    Data();
    Data(const Data & other);
    Data & operator = (const Data & other);
    ~Data();
};

