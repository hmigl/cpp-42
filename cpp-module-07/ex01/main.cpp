/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 08:36:57 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/14 08:04:42 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

#include "./iter.hpp"

void multiply(int &n) { n *= 10; }

template <typename T>
void print(const T &val) {
  std::cout << val << " ";
}

int main() {
  {
    std::cout << "should print all elements:\n";
    int arr[] = {1, 2, 3, 4, 5};
    iter(arr, 5, &print<int>);
    std::cout << std::endl;
  }
  std::cout << std::endl;
  {
    std::cout << "should throw invalid_argument exception due to nullptr:\n";
    try {
      int *arr = NULL;
      iter(arr, 5, &print<int>);
    } catch (const std::invalid_argument &e) {
      std::cout << e.what() << std::endl;
    }
  }
  std::cout << std::endl;
  {
    std::cout << "should throw invalid_argument exception due to zero passed "
                 "as length:\n";
    try {
      int arr[] = {1, 2, 3, 4, 5};
      iter(arr, 0, &print<int>);
    } catch (const std::invalid_argument &e) {
      std::cout << e.what() << std::endl;
    }
  }
  std::cout << std::endl;
  {
    std::cout << "should print all elements multiplied by 10:\n";
    int arr[] = {1, 2, 3, 4, 5};
    iter<int>(arr, 5, &multiply);
    iter<int>(arr, 5, &print);
    std::cout << std::endl;
  }
  return 0;
}
