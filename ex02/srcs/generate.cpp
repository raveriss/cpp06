/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:40:38 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/29 16:51:15 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclusion de la classe base */
#include "../incs/Base.hpp"
#include "../incs/A.hpp"
#include "../incs/B.hpp"
#include "../incs/C.hpp"

/* Inclusion de la bibliothèque standard pour std::rand, std::srand */
#include <cstdlib>

/* Inclusion de la bibliothèque standard pour std::time */
#include <ctime>

/**
 * @brief Génère un objet de type A, B ou C
 */
Base* generate(void) {
    std::srand(static_cast<unsigned int>(std::time(0)));
    int random = std::rand() % 3;

    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}
