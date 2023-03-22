/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:39:44 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/22 07:54:20 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "./Fixed.hpp"

int main(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));

  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;

  // Test arithmetic operators
  std::cout << "\n[ arithmetic operators ]\n";
  Fixed c = a + b;
  std::cout << "a + b = " << c << std::endl;
  c = a - b;
  std::cout << "a - b = " << c << std::endl;
  c = a * b;
  std::cout << "a * b = " << c << std::endl;
  c = a / b;
  std::cout << "a / b = " << c << std::endl;

  // Test compound assignment operators
  std::cout << "\n[ compound assignment operators ]\n";
  a += b;
  std::cout << "a += b = " << a << std::endl;
  a -= b;
  std::cout << "a -= b = " << a << std::endl;
  a *= b;
  std::cout << "a *= b = " << a << std::endl;
  a /= b;
  std::cout << "a /= b = " << a << std::endl;

  // Test increment and decrement operators
  std::cout << "\n[ increment/decrement operators ]\n";
  std::cout << "++a = " << ++a << std::endl;
  std::cout << "a++ = " << a++ << std::endl;
  std::cout << "a = " << a << std::endl;
  std::cout << "--a = " << --a << std::endl;
  std::cout << "a-- = " << a-- << std::endl;
  std::cout << "a = " << a << std::endl;

  // Test comparison operators
  std::cout << "\n[ comparison operators ]\n";
  std::cout << "a == b: " << (a == b) << std::endl;
  std::cout << "a != b: " << (a != b) << std::endl;
  std::cout << "a > b: " << (a > b) << std::endl;
  std::cout << "a < b: " << (a < b) << std::endl;
  std::cout << "a >= b: " << (a >= b) << std::endl;
  std::cout << "a <= b: " << (a <= b) << std::endl;

  // Test static min and max functions
  std::cout << "\n[ static min and max ]\n";
  std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
  std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;
}
