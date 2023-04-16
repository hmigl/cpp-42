/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:57:27 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/16 12:11:16 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>
#include <iostream>
#include <limits>

#include "./Array.hpp"

void shouldHandleException() {
  std::cout << "should handle exception\n";
  Array<int> arr(2);
  for (unsigned int i = 0; i < arr.size(); ++i) {
    arr[i] = i + 1;
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl << std::endl;
  try {
    const int &i = arr[std::numeric_limits<int>::max()];
    std::cout << "index= " << i << std::endl;
  } catch (const std::out_of_range &e) {
    std::cout << e.what() << std::endl;
  }
}

void shouldNotAffectOtherObject() {
  std::cout << "should not affect other object\n";
  Array<std::string> arr3(15);
  assert(arr3.size() == 15);
  for (unsigned int i = 0; i < arr3.size(); ++i) {
    arr3[i] = "bom dia";
    std::cout << arr3[i] << " ";
  }
  std::cout << std::endl << std::endl;

  Array<std::string> arr4(arr3);
  assert(arr4.size() == 15);
  arr4[0] = "boa tarde";
  for (unsigned int i = 0; i < arr3.size(); ++i) {
    std::cout << arr3[i] << " ";
  }
  std::cout << std::endl << std::endl;
  for (unsigned int i = 0; i < arr4.size(); ++i) {
    std::cout << arr4[i] << " ";
  }
  std::cout << std::endl << std::endl;
}

void shouldUseCopyAssignmentOperator() {
  std::cout << "should use copy assignment operator\n";
  Array<int> arr(10);
  Array<int> arr2(5);

  assert(arr.size() == 10);
  for (unsigned int i = 0; i < arr.size(); ++i) {
    arr[i] = i;
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl << std::endl;

  assert(arr2.size() == 5);
  for (unsigned int i = 0; i < arr2.size(); ++i) {
    arr2[i] = i + 42;
    std::cout << arr2[i] << " ";
  }
  std::cout << std::endl << std::endl;

  arr = arr2;
  assert(arr.size() == 5);
  for (unsigned int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl << std::endl;
}

int main() {
  shouldUseCopyAssignmentOperator();
  shouldNotAffectOtherObject();
  shouldHandleException();
  return 0;
}
