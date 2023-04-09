/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 11:59:28 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/09 13:09:42 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cctype>
#include <string>

class ScalarConverter {
 public:
  ScalarConverter(const ScalarConverter &);
  ~ScalarConverter();
  ScalarConverter &operator=(const ScalarConverter &);

  static void convert(const std::string &);

 private:
  ScalarConverter();

  static const int ScalarTypes = 4;

  char charRepr_;
  long intRepr_;
  float floatRepr_;
  double doubleRepr_;

  void toScalarTypes(const std::string &);
  bool isChar(const std::string &) const;
  bool isInt(const std::string &) const;
  bool isFloat(const std::string &) const;
  bool isDouble(const std::string &) const;
  void castChar(const std::string &);
  void castInt(const std::string &);
  void castFloat(const std::string &);
  void castDouble(const std::string &);
};
