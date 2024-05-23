/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:45:14 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/23 22:37:09 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ScalarConverter
{
    public:
        static void convert(const std::string & literal);

    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter & other);
        ScalarConverter & operator = (const ScalarConverter & other);
        ~ScalarConverter();
};
