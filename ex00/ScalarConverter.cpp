/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:43:34 by ryusupov          #+#    #+#             */
/*   Updated: 2025/03/14 15:23:08 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <limits>

ScalarConverter::ScalarConverter() {

}

ScalarConverter::~ScalarConverter() {
	std::cout << "Destructor has been called!" << std::endl;
}

ScalarConverter::ScalarConverter(std::string type) {
	for(int i = 0; i < 4; i++) {
		convertion_table[i].stats = NOT_CONVERTED;
	}

	convertion_table[IS_CHAR].converting = &ScalarConverter::convert_to_char;
	convertion_table[IS_INT].converting = &ScalarConverter::convert_to_int;
	convertion_table[IS_DOUBLE].converting = &ScalarConverter::convert_to_double;
	convertion_table[IS_FLOAT].converting = &ScalarConverter::convert_to_float;
	(this->*(convertion_table[get_type(type)].converting))(type);
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	for (size_t i = 0; i < NUMBER_OF_CONVERSIONS; i++)
		convertion_table[i].stats = src.convertion_table[i].stats;
	convert = src.convert;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &s) {
	for (size_t i = 0; i < NUMBER_OF_CONVERSIONS; i++){
			convertion_table[i].stats = s.convertion_table[i].stats;
	}
	convert = s.convert;
	return (*this);
}

ScalarConverter::t_data_types ScalarConverter::get_type(const std::string &type) {
	if (is_char(type))
		return (IS_CHAR);
	else if (is_int(type))
		return (IS_INT);
	else if (is_double(type))
		return (IS_DOUBLE);
	else if (is_float(type))
		return (IS_FLOAT);
	else
	 	return(IS_NOT_TYPE);
}

int	ScalarConverter::is_char(const std::string &str) {
	if (str.length() == 1 && !std::isdigit(str[0]))
		return (1);
	else
		return (0);
}

int	ScalarConverter::is_int(const std::string &str) {
	int	len = str.length();
	int	i;

	if (str[0] == '-')
		i = 1;
	else
		i = 0;
	if (len == i)
		return (0);
	for (; i < len; i++) {
		if (!std::isdigit(str[i]))
			return (0);
	}
	return (1);
}

int ScalarConverter::is_float(const std::string &str) {
	size_t i = 0;

	if (str == "-inff" || str == "+inff" || str == "nanf")
		return (true);
	if (str[0] == '-')
		i++;
	while (std::isdigit(str[i]))
		i++;
	if (i + 1 == str.length() && str[i] == 'f')
		return (1);
	if (i + 1 != str.length() && str[i] != '.')
		return (0);
	else
		i++;
	while (std::isdigit(str[i]))
		i++;
	if (i + 1 != str.length() || str[i] != 'f')
		return (0);
	return (1);
}

int	ScalarConverter::is_double(const std::string &str) {
	size_t i = 0;

	if (str == "-inf" || str == "+inf" || str == "nan")
		return (1);
	if (str[0] == '-')
		i++;
	while (std::isdigit(str[i]))
		i++;
	if (str[i] != '.')
		return (0);
	i++;
	while (std::isdigit(str[i]))
		i++;
	if (i != str.length())
		return (0);
	return (1);
}

ScalarConverter::t_status	ScalarConverter::set_status_char(const char &c) {
	if (std::isprint(c))
		return (CONVERTED);
	else
		return (NON_DISPLAYABLE);
}

std::string ScalarConverter::convertToString(int i) {
	std::string converted_str;
	std::stringstream str_str;

	str_str << i;
	str_str >> converted_str;

	return (converted_str);
}

void	ScalarConverter::convert_to_char (const std::string &str) {
	std::stringstream str_str(str);
	str_str >> convert.c;
	convertion_table[IS_CHAR].stats = set_status_char(convert.c);

	convert.i = static_cast<int>(convert.c);
	convertion_table[IS_INT].stats = CONVERTED;
	convert.f = static_cast<float>(convert.c);
	convertion_table[IS_FLOAT].stats = CONVERTED;
	convert.d = static_cast<double>(convert.c);
	convertion_table[IS_DOUBLE].stats = CONVERTED;
}

void	ScalarConverter::convert_to_float(const std::string &str) {
	if (str == "+inff")
		convert.f = 1.0 / 0.0 ;
	else if (str == "-inff")
		convert.f = -1.0 / 0.0 ;
	else if (str == "nanf")
		convert.f = std::numeric_limits<float>::quiet_NaN();
	else
		convert.f = set_float(str);
	convertion_table[IS_FLOAT].stats = CONVERTED;

	convert.i = static_cast<int>(convert.f);
	if (convert.i != static_cast<long long>(convert.f)){
		convertion_table[IS_INT].stats = NOT_CONVERTED;
		convert.c = static_cast<char>(convert.f);
		convertion_table[IS_CHAR].stats = set_status_char(convert.c);
	}
	convert.d = static_cast<double>(convert.f);
	convertion_table[IS_DOUBLE].stats = CONVERTED;
}


float ScalarConverter::set_float(const std::string &type) {
	std::stringstream str_str(type);
	double	temp;

	str_str >> temp;
	if (temp > std::numeric_limits<float>::max()) {
		return (1.0 / 0.0);
	}
	else
		return ((float)temp);
}


double ScalarConverter::set_double(const std::string &type) {
	std::stringstream str_str(type);
	long double temp;

	str_str >> temp;
	if (temp > std::numeric_limits<double>::max()) {
		return (1.0 / 0.0);
	}
	else
		return ((double)temp);
}

void ScalarConverter::convert_to_int(const std::string &str) {
	std::stringstream str_str(str);
	str_str >> convert.i;

	if (str_str.fail()) {
		convertion_table[IS_INT].stats = FAILED_CONVERTION;
		return ;
	}

	convertion_table[IS_INT].stats = CONVERTED;

	convert.c = static_cast<char>(convert.i);
	convertion_table[IS_CHAR].stats = CONVERTED;

	convert.f = static_cast<float>(convert.i);
	convertion_table[IS_FLOAT].stats = CONVERTED;

	convert.d = static_cast<double>(convert.i);
	convertion_table[IS_DOUBLE].stats = CONVERTED;
}

void ScalarConverter::convert_to_double(const std::string &str) {
	if (str == "+inf" || str == "-inf" || str == "nan") {
		convert.d = std::stod(str);
	} else {
		convert.d = set_double(str);
	}

	convertion_table[IS_DOUBLE].stats = CONVERTED;

	convert.i = static_cast<int>(convert.d);
	if (convert.i != static_cast<long long>(convert.d)) {
		convertion_table[IS_INT].stats = NOT_CONVERTED;
	} else {
		convertion_table[IS_INT].stats = CONVERTED;
	}

	convert.c = static_cast<char>(convert.d);
	convertion_table[IS_CHAR].stats = set_status_char(convert.c);

	convert.f = static_cast<float>(convert.d);
	convertion_table[IS_FLOAT].stats = CONVERTED;
}

void ScalarConverter::not_convertable(const std::string &str) {
	(void)str;
	for (int i = 0; i < 4; i++) {
		convertion_table[i].stats = FAILED_CONVERTION;
	}
}

void ScalarConverter::print_message() const {
	std::cout << "Convertion : " << std::endl;

	std::cout << "char: ";
	if (convertion_table[IS_CHAR].stats == CONVERTED){
		std::cout << "'" << convert.c << "'" << std::endl;
	} else if (convertion_table[IS_CHAR].stats == NOT_CONVERTED) {
		std::cout << "Non dispayable" << std::endl;
	} else {
		std::cout << "Imposible!" << std::endl;
	}

	std::cout << "int: ";
	if (convertion_table[IS_INT].stats == CONVERTED) {
		std::cout << convert.i << std::endl;
	} else {
		std::cout << "Imposible!" << std::endl;
	}

	std::cout << "float: ";
	if (convertion_table[IS_FLOAT].stats == CONVERTED) {
		std::cout << std::fixed << std::setprecision(1) << convert.f << "f" << std::endl;
	} else {
		std::cout << "Imposible!" << std::endl;
	}

	std::cout << "double: ";
	if (convertion_table[IS_DOUBLE].stats == CONVERTED) {
		std::cout << std::fixed << std::setprecision(1) << convert.d << "d" << std::endl;
	} else {
		std::cout << "Imposible!" << std::endl;
	}
}
