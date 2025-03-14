/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:35:17 by ryusupov          #+#    #+#             */
/*   Updated: 2025/03/14 18:43:51 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


int main() {
	Data myData = {.value = 42, .string = "Hello, World!"};

	std::cout << "Original Data: \n" << myData << std::endl;

	// Serializeing to convert pointer to integer
	uintptr_t raw = serialize(&myData);
	std::cout << "Serialized (uintptr_t): " << raw << std::endl;

	// Deserializing to convert integer back to pointer
	Data *restoredData = deserialize(raw);
	std::cout << "Deserialized Data: \n" << *restoredData << std::endl;

	return 0;
}

