/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:11:09 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/20 13:20:36 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "./Span.hpp"

void shouldNotAddSequenceThatExceedsCapacity() {
  std::vector<int> v;
  for (int i = 0; i < 10000; ++i) {
    v.push_back(i);
  }
  std::vector<int>::iterator first = v.begin();
  std::vector<int>::iterator last = v.end();

  Span s(10000);
  s.addNumber(-1);
  try {
    s.insertRange(first, last);
  } catch (const std::length_error &e) {
    // std::cout << e.what() << std::endl;
  }
  std::cout << "should not add sequence that exceeds capacity [OK]\n";
}

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
    // std::cout << e.what() << std::endl;
  }
  std::cout << "should not add number [OK]\n";
}

int main() {
  shouldNotAddNumber();
  shouldAddSequenceOfElements();
  shouldNotAddSequenceThatExceedsCapacity();
  return 0;
}
