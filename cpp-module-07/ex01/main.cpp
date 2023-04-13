/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 08:36:57 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/13 08:45:59 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "./iter.hpp"

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
  return 0;
}
