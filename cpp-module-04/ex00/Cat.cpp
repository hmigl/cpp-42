/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:36:59 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/27 17:57:39 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Cat.hpp"

Cat::Cat() : Animal("Cat") {
  std::cout << "(Cat) Default constructor called\n";
}

Cat::Cat(const Cat &other) : Animal(other) {
  std::cout << "(Cat) Copy constructor called\n";
  *this = other;
}

Cat::~Cat() { std::cout << "(Cat) Destructor called\n"; }

void Cat::makeSound() const { std::cout << "(Cat) Meow! Meow! Meow!\n"; }

Cat &Cat::operator=(const Cat &other) {
  Animal::operator=(other);
  return *this;
}
