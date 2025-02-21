/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:01:35 by ryusupov          #+#    #+#             */
/*   Updated: 2025/02/21 19:50:51 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t serialize(Data *str) {
	return (reinterpret_cast<uintptr_t>(str));
}

Data *deserialize(uintptr_t str) {
	return (reinterpret_cast<Data *>(str));
}

std::ostream &operator<<(std::ostream &str, const Data &obj){
	str << "The data is stored at the adress: { " << &obj << " }"
		<< "\n\t- value is: " << obj.value
		<< "\n\t- string is: " << obj.string << std::endl;
	return (str);
}
