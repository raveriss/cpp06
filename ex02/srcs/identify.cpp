/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:42:24 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/29 16:49:41 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclusion de la bibliothèque std pour flux d'entrée/sortie standard */
#include <iostream>

/* Inclusion de la classe Base */
#include "Base.hpp"

/* Inclusion des classes A, B et C */
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/**
 * @brief Identifie le type réel de l'objet pointé par Base* ou Base* (A, B ou C)
 */
void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

/**
  @brief Identifie le type réel de l'objet référencé par Base& (A, B ou C)
 */
void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (...)
    {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (...)
    {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (...)
    {}
}

/* identifiy.cpp */
