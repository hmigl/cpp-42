/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:36:59 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/27 18:49:44 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Wrong Cat") {
  std::cout << "(Wrong Cat) Default constructor called\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
  std::cout << "(Wrong Cat) Copy constructor called\n";
  *this = other;
}

WrongCat::~WrongCat() { std::cout << "(Wrong Cat) Destructor called\n"; }

void WrongCat::makeSound() const {
  std::cout << "(Wrong Cat) Meow! Meow! Meow!\n";
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
  WrongAnimal::operator=(other);
  return *this;
}
