/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:55:40 by ryusupov          #+#    #+#             */
/*   Updated: 2024/12/29 12:56:07 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#define NUMBER_OF_CONVERSIONS 4

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class ScalarConverter {
	private:
		typedef enum status {
			FAILED_CONVERTION,
			NOT_CONVERTED,
			NON_DISPLAYABLE,
			CONVERTED,
		} t_status;

		typedef enum data_types {
			IS_CHAR,
			IS_INT,
			IS_DOUBLE,
			IS_FLOAT,
			IS_NOT_TYPE,
		}	t_data_types;

		typedef struct s_converter
		{
			char c;
			int	i;
			double d;
			float f;
		}	t_converter;

		typedef struct converter_table {
			t_status stats;
			void (ScalarConverter::*converting)(const std::string&);
		}		t_converter_table;

		t_converter_table convertion_table[NUMBER_OF_CONVERSIONS + 1];
		t_converter convert;

		t_data_types	get_type(const std::string &type);
		int				is_char(const std::string &type);
		int				is_int(const std::string &type);
		int				is_double(const std::string &type);
		int				is_float(const std::string &type);

		t_status set_status_char(const char &c);
		std::string convertToString(int i);
		float set_float(const std::string &str);
		double set_double(const std::string &str);

		void	convert_to_char(const std::string &str);
		void	convert_to_int(const std::string &str);
		void	convert_to_double(const std::string &str);
		void	convert_to_float(const std::string &str);
		void	not_convertable(const std::string &str);

		int	print_error(int	status) const;

	public:
		ScalarConverter();
		ScalarConverter(std::string type);
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter& operator=(ScalarConverter const &s);

		void	print_message() const;

};

#endif
