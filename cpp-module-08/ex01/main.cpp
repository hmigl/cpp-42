/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:11:09 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/21 09:57:13 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>
#include <iostream>

#include "./Span.hpp"

void shouldGetLongestSpan() {
  Span s = Span(5);

  s.addNumber(6);
  s.addNumber(3);
  s.addNumber(17);
  s.addNumber(9);
  s.addNumber(11);
  assert(s.longestSpan() == 14);
  std::cout << "should get longest span [OK]\n";
}

void shouldGetShortestSpan() {
  Span s = Span(5);

  s.addNumber(6);
  s.addNumber(3);
  s.addNumber(17);
  s.addNumber(9);
  s.addNumber(11);
  assert(s.shortestSpan() == 2);
  std::cout << "should get shortest span [OK]\n";
}

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
  shouldGetShortestSpan();
  shouldGetLongestSpan();
  return 0;
}
