/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:57:06 by ryusupov          #+#    #+#             */
/*   Updated: 2025/02/21 19:49:32 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <stdint.h>
#include <iostream>

struct Data
{
	unsigned int value;
	std::string string;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);
std::ostream &operator<<(std::ostream &str, const Data &obj);


#endif
