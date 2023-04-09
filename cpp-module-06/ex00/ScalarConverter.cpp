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

void ScalarConverter::castChar(const std::string &literal) {}

void ScalarConverter::castInt(const std::string &literal) {}

void ScalarConverter::castFloat(const std::string &literal) {}

void ScalarConverter::castDouble(const std::string &literal) {}
