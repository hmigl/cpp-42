/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 11:59:28 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/11 09:20:52 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

class ScalarConverter {
 public:
  ~ScalarConverter();

  static void convert(const std::string &);

 private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter &);
  ScalarConverter &operator=(const ScalarConverter &);

  static const int ScalarTypes = 4;

  static unsigned char charRepr_;
  static long intRepr_;
  static float floatRepr_;
  static double doubleRepr_;

  static void display();
  static bool isChar(const std::string &);
  static bool isInt(const std::string &);
  static bool isFloat(const std::string &);
  static bool isDouble(const std::string &);
  static void castChar(const std::string &);
  static void castInt(const std::string &);
  static void castFloat(const std::string &);
  static void castDouble(const std::string &);
};
