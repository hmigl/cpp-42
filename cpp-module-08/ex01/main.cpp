/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:11:09 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/20 13:16:47 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "./Span.hpp"

void shouldAddSequenceOfElements() {
  std::vector<int> v;
  for (int i = 0; i < 10000; ++i) {
    v.push_back(i);
  }
  std::vector<int>::iterator first = v.begin();
  std::vector<int>::iterator last = v.end();

  Span s(10000);
  s.insertRange(first, last);
  std::cout << "should add sequence of elements [OK]\n";
}

void shouldNotAddNumber() {
  Span s(10000);

  for (int i = 0; i < 10000; ++i) {
    s.addNumber(i);
  }
  try {
    s.addNumber(42);
  } catch (const std::length_error &e) {
  }
  std::cout << "should not add number [OK]\n";
}

int main() {
  shouldNotAddNumber();
  shouldAddSequenceOfElements();
  return 0;
}
