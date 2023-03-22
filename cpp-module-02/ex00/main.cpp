/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:39:44 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/20 14:40:32 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "./Fixed.hpp"

int main(void) {
  Fixed a;
  Fixed b(a);
  Fixed c;

  c = b;
  std::cout << a.getRawBits() << '\n';
  std::cout << b.getRawBits() << '\n';
  std::cout << c.getRawBits() << '\n';
  return 0;
}
