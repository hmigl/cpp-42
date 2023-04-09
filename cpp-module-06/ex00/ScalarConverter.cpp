/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:17:05 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/09 13:41:05 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
  *this = other;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
  if (this != &other) {
    charRepr_ = other.charRepr_;
    intRepr_ = other.intRepr_;
    floatRepr_ = other.floatRepr_;
    doubleRepr_ = other.doubleRepr_;
  }
  return *this;
}

void ScalarConverter::convert(const std::string &literal) {
  ScalarConverter sc;
  sc.toScalarTypes(literal);
}

void ScalarConverter::toScalarTypes(const std::string &literal) {
  bool (ScalarConverter::*isScalarType[ScalarTypes])(const std::string &)
      const = {&ScalarConverter::isChar, &ScalarConverter::isInt,
               &ScalarConverter::isFloat, &ScalarConverter::isDouble};

  void (ScalarConverter::*castScalarType[ScalarTypes])(const std::string &) = {
      &ScalarConverter::castChar, &ScalarConverter::castInt,
      &ScalarConverter::castFloat, &ScalarConverter::castDouble};

  for (int i = 0; i < ScalarTypes; ++i) {
    if ((this->*isScalarType[i])(literal)) {
      (this->*castScalarType[i])(literal);
      return;
    }
  }
}

bool ScalarConverter::isChar(const std::string &literal) const {
  return literal.length() == 1 && isdigit(literal[0]);
}

bool ScalarConverter::isInt(const std::string &) const {}

bool ScalarConverter::isFloat(const std::string &) const {}

bool ScalarConverter::isDouble(const std::string &) const {}

void ScalarConverter::castChar(const std::string &literal) {
  charRepr_ = literal[0];
  intRepr_ = static_cast<long>(charRepr_);
  floatRepr_ = static_cast<float>(charRepr_);
  doubleRepr_ = static_cast<double>(charRepr_);
}

void ScalarConverter::castInt(const std::string &literal) {
  intRepr_ = std::atol(literal.c_str());
  if (intRepr_ < std::numeric_limits<int>::min()) {
    throw std::underflow_error("underflow error");
  }
  if (intRepr_ > std::numeric_limits<int>::max()) {
    throw std::overflow_error("overflow error");
  }
  charRepr_ = static_cast<unsigned char>(intRepr_);
  floatRepr_ = static_cast<float>(intRepr_);
  doubleRepr_ = static_cast<double>(intRepr_);
}

void ScalarConverter::castFloat(const std::string &literal) {}

void ScalarConverter::castDouble(const std::string &literal) {}
