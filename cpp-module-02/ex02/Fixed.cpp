/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:03:04 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/21 19:56:43 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed() : rawBits_(0) {}

Fixed::Fixed(const Fixed &other) { *this = other; }

Fixed::Fixed(const int num) : rawBits_(num << FractionalBits) {}

Fixed::Fixed(const float num) : rawBits_(roundf(num * (1 << FractionalBits))) {}

Fixed::~Fixed() {}

float Fixed::toFloat() const {
  return static_cast<float>(rawBits_) / (1 << FractionalBits);
}

int Fixed::toInt() const { return rawBits_ >> FractionalBits; }

int Fixed::getRawBits() const { return rawBits_; }

void Fixed::setRawBits(const int rawBits) { rawBits_ = rawBits; }

Fixed &Fixed::operator=(const Fixed &other) {
  if (this != &other) {
    rawBits_ = other.getRawBits();
  }
  return *this;
}

bool Fixed::operator>(const Fixed &rhs) const {
  return rawBits_ > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed &rhs) const {
  return rawBits_ < rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed &rhs) const {
  return rawBits_ >= rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed &rhs) const {
  return rawBits_ <= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed &rhs) const {
  return rawBits_ == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed &rhs) const {
  return rawBits_ != rhs.getRawBits();
}

Fixed Fixed::operator+(const Fixed &rhs) const {
  return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) const {
  return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) const {
  return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const {
  return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &Fixed::operator++() {
  rawBits_++;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed old(*this);
  ++(*this);
  return old;
}

Fixed &Fixed::operator--() {
  rawBits_--;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed old(*this);
  --(*this);
  return old;
}

std::ostream &operator<<(std::ostream &os, const Fixed &rhs) {
  os << rhs.toFloat();
  return os;
}
