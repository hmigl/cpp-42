/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:35:08 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/27 17:17:52 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Animal.hpp"

Animal::Animal() : type_("Undefined") {
  std::cout << "(Animal) Default constructor called\n";
}

Animal::Animal(const std::string &type) : type_(type) {
  std::cout << "(Animal) String constructor called\n";
}

Animal::Animal(const Animal &other) {
  std::cout << "(Animal) Copy constructor called\n";
  *this = other;
}

Animal::~Animal() { std::cout << "(Animal) Destructor called\n"; }

void Animal::makeSound() const {
  std::cout << "(Animal) Making generic sound!\n";
}

const std::string &Animal::getType() const { return type_; }

Animal &Animal::operator=(const Animal &other) {
  if (this != &other) {
    type_ = other.type_;
  }
  return *this;
}
