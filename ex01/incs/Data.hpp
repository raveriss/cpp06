/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:42:06 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/28 11:43:05 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

struct Data
{
    int id;
    std::string name;

    Data();
    Data(const Data& other);
    Data& operator=(const Data& other);
    ~Data();
};

