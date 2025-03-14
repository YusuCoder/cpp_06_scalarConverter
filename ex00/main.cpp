/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:15:09 by rustam            #+#    #+#             */
/*   Updated: 2025/03/14 19:00:43 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "ScalarConverter.hpp"

void test_conversion(const std::string &input) {
    std::cout << "Testing input: \"" << input << "\"\n";
    ScalarConverter converter(input);
    converter.print_message();
    std::cout << "----------------------------------------\n";
}

int main() {
    test_conversion("42");       // Integer
    test_conversion("3.14");     // Double
    test_conversion("42.0");    // Float
    test_conversion("a");        // Character
    test_conversion("-inff");    // Special float infinity case for overflow
    test_conversion("+inf");     // Special double infinity case for overflow
    test_conversion("nan");      // NaN case
    test_conversion("999999999999999999999999999999"); // Overflow case
    test_conversion("hello");    // Invalid input
    test_conversion("123abc");   // Mixed invalid input

    return 0;
}
