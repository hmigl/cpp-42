/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:36:59 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/28 16:53:29 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Dog.hpp"

Dog::Dog() : Animal("Dog") {
  std::cout << "(Dog) Default constructor called\n";
  brain_ = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other) {
  std::cout << "(Dog) Copy constructor called\n";
  *this = other;
}

Dog::~Dog() {
  std::cout << "(Dog) Destructor called\n";
  delete brain_;
}

const Brain *Dog::getBrain() const { return brain_; }

void Dog::makeSound() const { std::cout << "(Dog) Woof! Woof! Woof!\n"; }

Dog &Dog::operator=(const Dog &other) {
  Animal::operator=(other);
  brain_ = new Brain(*other.brain_);
  return *this;
}
