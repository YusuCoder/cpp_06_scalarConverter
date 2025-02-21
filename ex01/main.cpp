/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:35:17 by ryusupov          #+#    #+#             */
/*   Updated: 2025/02/21 19:50:24 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data data = {.value = 12345, .string = "CPP06"};
	uintptr_t serializedPtrInt = serialize(&data);
	Data *deserializedPtr = deserialize(serializedPtrInt);

	if (deserializedPtr == &data)
		std::cout << "Successfully serialized!" << std::endl;
	else
		std::cout << "Failed to serialize!" << std::endl;
	std::cout << "Original " << data << std::endl;
	std::cout << "Pointer to data structure is: " << serializedPtrInt << std::endl;
	std::cout << "Deserialized " << *deserializedPtr << std::endl;
	return (0);
}
