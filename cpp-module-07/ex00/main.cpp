/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 08:01:25 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/13 08:01:26 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "./whatever.hpp"

int main() {
  {
    int x = 3, y = 5;
    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
    swap(x, y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;
  }
  std::cout << std::endl;
  {
    double a = 3.14, b = 2.71;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "Min value: " << min(a, b) << std::endl;
    std::cout << "Max value: " << max(a, b) << std::endl;
  }
  std::cout << std::endl;
  {
    std::string s1 = "hello", s2 = "world";
    std::cout << "Before swap: s1 = " << s1 << ", s2 = " << s2 << std::endl;
    swap(s1, s2);
    std::cout << "After swap: s1 = " << s1 << ", s2 = " << s2 << std::endl;
  }
  return 0;
}
