/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:55:04 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/30 21:58:36 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Directive pour éviter les inclusions multiples d'un fichier d'en-tête */
#pragma once

/* Inclusion de la classe Base */
#include "Base.hpp"

/**
 * @brief Identifie le type réel de l'objet pointé par p
 */
void identify(Base* p);

/**
 * @brief Identifie le type réel de l'objet référencé par p
 */
void identify(Base& p);

