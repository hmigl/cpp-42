/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 11:59:28 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/09 12:09:18 by hmigl            ###   ########.fr       */
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

  char charRepr_;
  int intRepr_;
  float floatRepr_;
  double doubleRepr_;

  void toScalarTypes(const std::string &);
  bool isChar(const std::string &) const;
  bool isInt(const std::string &) const;
  bool isFloat(const std::string &) const;
  bool isDouble(const std::string &) const;
};
