/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:42:24 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/31 17:23:38 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclusion de la bibliothèque std pour flux d'entrée/sortie standard */
#include <iostream>

/* Inclusion de la classe Base */
#include "../incs/Base.hpp"

/* Inclusion des classes A, B et C */
#include "../incs/A.hpp"
#include "../incs/B.hpp"
#include "../incs/C.hpp"

/**
 * @brief Identifie le type réel de l'objet pointé par Base* ou Base* (A, B ou C)
 */
void identify(Base* p)
{
    if (p == NULL) {
        std::cerr << "Null pointer provided to identify function" << std::endl;
        return;
    }

    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cerr << "Error: Unknown type" << std::endl;
}

void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch (std::exception &e) {}
    try
    {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
    }
    catch (std::exception &e) {}
    try
    {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
    }
    catch (std::exception &e) {}
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
    {
        std::cout << "Unknown type" << std::endl;
    }
}

/* identifiy.cpp */