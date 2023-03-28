/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:36:59 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/28 16:54:11 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Cat.hpp"

Cat::Cat() : Animal("Cat") {
  std::cout << "(Cat) Default constructor called\n";
  brain_ = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other) {
  std::cout << "(Cat) Copy constructor called\n";
  *this = other;
}

Cat::~Cat() {
  std::cout << "(Cat) Destructor called\n";
  delete brain_;
}

const Brain *Cat::getBrain() const { return brain_; }

void Cat::makeSound() const { std::cout << "(Cat) Meow! Meow! Meow!\n"; }

Cat &Cat::operator=(const Cat &other) {
  Animal::operator=(other);
  brain_ = new Brain(*other.brain_);
  return *this;
}
