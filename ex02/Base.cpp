/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:24:09 by ryusupov          #+#    #+#             */
/*   Updated: 2025/02/21 20:57:00 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base::~Base() {
	std::cout << "Base class distructor has been called!" << std::endl;
	return ;
}

Base *generate() {
	int nb = std::rand() % 3;

	switch (nb)
	{
	case 0:
		std::cout << "Generated: A";
		return (new A);
	case 1:
		std::cout << "Generated: B";
		return (new B);
	case 2:
		std::cout << "Generated: C";
		return (new C);
	}
	return (NULL);
}

void	identify(Base *p){
	std::cout << "Pointer identification found: ";
	if (dynamic_cast<A *>(p))
		std::cout << "A";
	else if (dynamic_cast<B *>(p))
		std::cout << "B";
	else if (dynamic_cast<C *>(p))
		std::cout << "C";
	else
		std::cout << "Nothing identified!" << std::endl;
}

void	identify(Base &p){
	std::cout << "Reference identification found: ";
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "A";
	}
	catch (std::exception &e) {
		//
	}
	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "B";
	}
	catch (std::exception &e) {
		//
	}
	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "C";
	}
	catch (std::exception &e) {
		//
	}
}
