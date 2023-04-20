/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:11:09 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/20 11:11:10 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "./Span.hpp"

void shouldNotAddNumber() {
  Span s(10000);

  for (int i = 0; i < 10000; ++i) {
    s.addNumber(i);
  }
  try {
    s.addNumber(42);
  } catch (const std::length_error &e) {
    std::cout << e.what() << std::endl;
  }
}

int main() {
  shouldNotAddNumber();
  return 0;
}
