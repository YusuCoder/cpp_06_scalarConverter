/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:29:35 by ryusupov          #+#    #+#             */
/*   Updated: 2025/02/21 20:55:45 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

int main(){
	Base *p;
	std::srand(std::time(NULL));

	for (int i = 0; i < 25; i++) {
		std::cout << "Test number {" << i << "}:\t";
		p = generate();
		std::cout << ", ";
		identify(p);
		std::cout << ", ";
		delete (p);
		std::cout << std::endl;
	}
	return (0);
}

