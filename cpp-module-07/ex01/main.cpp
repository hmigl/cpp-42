/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 08:36:57 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/13 08:37:02 by hmigl            ###   ########.fr       */
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
  return 0;
}
