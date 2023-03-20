/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:03:04 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/20 19:49:56 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"

#include <iostream>

Fixed::Fixed() : rawBits_(0) { std::cout << "Default constructor called\n"; }

Fixed::Fixed(const Fixed &other) {
  std::cout << "Copy constructor called\n";
  *this = other;
}

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called\n";
  return rawBits_;
}

void Fixed::setRawBits(const int rawBits) { rawBits_ = rawBits; }

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called\n";
  if (this != &other) {
    rawBits_ = other.getRawBits();
  }
  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called\n"; }
