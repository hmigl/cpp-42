/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:35:08 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/27 18:48:28 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type_("Undefined") {
  std::cout << "(Wrong Animal) Default constructor called\n";
}

WrongAnimal::WrongAnimal(const std::string &type) : type_(type) {
  std::cout << "(Wrong Animal) String constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
  std::cout << "(Wrong Animal) Copy constructor called\n";
  *this = other;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "(Wrong Animal) Destructor called\n";
}

void WrongAnimal::makeSound() const {
  std::cout << "(Wrong Animal) Making generic sound!\n";
}

const std::string &WrongAnimal::getType() const { return type_; }

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
  if (this != &other) {
    type_ = other.type_;
  }
  return *this;
}
