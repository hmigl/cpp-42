/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:03:04 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/21 17:10:39 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed() : rawBits_(0) { std::cout << "Default constructor called\n"; }

Fixed::Fixed(const Fixed &other) {
  std::cout << "Copy constructor called\n";
  *this = other;
}

Fixed::Fixed(const int num) : rawBits_(num << FractionalBits) {
  std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float num) : rawBits_(roundf(num * (1 << FractionalBits))) {
  std::cout << "Float constructor called\n";
}

Fixed::~Fixed() { std::cout << "Destructor called\n"; }

float Fixed::toFloat() const {
  return static_cast<float>(rawBits_) / (1 << FractionalBits);
}

int Fixed::toInt() const { return rawBits_ >> FractionalBits; }

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

std::ostream &operator<<(std::ostream &os, const Fixed &obj) {
  os << obj.toFloat();
  return os;
}
