/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:36:59 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/27 17:47:18 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Dog.hpp"

Dog::Dog() : Animal("Dog") {
  std::cout << "(Dog) Default constructor called\n";
}

Dog::Dog(const Dog &other) : Animal(other) {
  std::cout << "(Dog) Copy constructor called\n";
  *this = other;
}

Dog::~Dog() { std::cout << "(Dog) Destructor called\n"; }

void Dog::makeSound() const { std::cout << "(Dog) Woof! Woof! Woof!\n"; }

Dog &Dog::operator=(const Dog &other) {
  Animal::operator=(other);
  return *this;
}
