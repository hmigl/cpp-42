/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:17:05 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/11 09:20:06 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScalarConverter.hpp"

unsigned char ScalarConverter::charRepr_ = 0;
long ScalarConverter::intRepr_ = 0;
float ScalarConverter::floatRepr_ = 0;
double ScalarConverter::doubleRepr_ = 0;

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
  if (literal.empty()) {
    return;
  }

  bool (*isScalarType[ScalarTypes])(const std::string &) = {
      &isChar, &isInt, &isFloat, &isDouble};

  void (*castScalarType[ScalarTypes])(const std::string &) = {
      &castChar, &castInt, &castFloat, &castDouble};

  for (int i = 0; i < ScalarTypes; ++i) {
    if ((*isScalarType[i])(literal)) {
      (*castScalarType[i])(literal);
      ScalarConverter::display();
      return;
    }
  }
  throw std::runtime_error("Cannot convert literal. Enter a valid scalar type");
}

bool ScalarConverter::isChar(const std::string &literal) {
  return literal.length() == 1 && isascii(literal.at(0)) &&
         !isdigit(literal.at(0));
}

bool ScalarConverter::isInt(const std::string &literal) {
  size_t i = 0;
  if (literal[i] == '-' || literal[i] == '+') {
    ++i;
  }
  for (; i < literal.length(); ++i) {
    if (!isdigit(literal[i])) {
      return false;
    }
  }
  return true;
}

bool ScalarConverter::isFloat(const std::string &literal) {
  if (literal == "inff" || literal == "-inff" || literal == "nanf") {
    return true;
  }
  size_t pos = literal.find_first_of(".");
  if (pos == std::string::npos) {
    return false;
  }
  if (literal[literal.length() - 1] != 'f') {
    return false;
  }
  if ((literal.at(0) == '-' || literal.at(0) == '+') &&
      literal.find_first_of("+-", 1) != std::string::npos) {
    return false;
  }
  pos = literal.find_first_not_of("-+", 1);
  if (pos == std::string::npos) {
    return false;
  }
  pos = literal.find_first_not_of("0123456789.f", pos + 1);
  return pos == std::string::npos;
}

bool ScalarConverter::isDouble(const std::string &literal) {
  if (literal == "inf" || literal == "-inf" || literal == "nan") {
    return true;
  }
  size_t pos = literal.find_first_of(".");
  if (pos == std::string::npos) {
    return false;
  }
  if ((literal.at(0) == '-' || literal.at(0) == '+') &&
      literal.find_first_of("+-", 1) != std::string::npos) {
    return false;
  }
  pos = literal.find_first_not_of("-+", 1);
  if (pos == std::string::npos) {
    return false;
  }
  pos = literal.find_first_not_of("0123456789.", pos + 1);
  return pos == std::string::npos;
}

void ScalarConverter::castChar(const std::string &literal) {
  charRepr_ = literal.at(0);
  intRepr_ = static_cast<int>(charRepr_);
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

void ScalarConverter::castFloat(const std::string &literal) {
  floatRepr_ = std::atof(literal.c_str());
  charRepr_ = static_cast<unsigned char>(floatRepr_);
  intRepr_ = static_cast<int>(floatRepr_);
  doubleRepr_ = static_cast<double>(floatRepr_);
}

void ScalarConverter::castDouble(const std::string &literal) {
  doubleRepr_ = std::strtod(literal.c_str(), NULL);
  charRepr_ = static_cast<unsigned char>(doubleRepr_);
  intRepr_ = static_cast<int>(doubleRepr_);
  floatRepr_ = static_cast<float>(doubleRepr_);
}

void ScalarConverter::display() {
  if (std::isinf(doubleRepr_) || std::isnan(doubleRepr_)) {
    std::cout << "char:\timpossible\n";
    std::cout << "int:\timpossible\n";
  } else {
    if (isprint(charRepr_)) {
      std::cout << "char:\t" << charRepr_ << std::endl;
    } else {
      std::cout << "char:\tnon displayable\n";
    }
    std::cout << "int:\t" << intRepr_ << std::endl;
  }
  std::cout << "float:\t" << std::fixed << std::setprecision(1) << floatRepr_
            << "f" << std::endl;
  std::cout << "double:\t" << std::fixed << std::setprecision(1) << doubleRepr_
            << std::endl;
}
