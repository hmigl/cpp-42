/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 08:47:42 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/20 09:03:37 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>

#include "./easyfind.hpp"

void shouldWorkWithList() {
  std::list<int> l;

  for (int i = 10; i < 20; ++i) {
    l.push_back(i);
  }
  std::cout << *easyfind(l, 11) << std::endl;
  try {
    std::cout << *easyfind(l, 42) << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

void shouldWorkWithVector() {
  std::vector<int> v;

  for (int i = 0; i < 10; ++i) {
    v.push_back(i);
  }
  std::cout << *easyfind(v, 7) << std::endl;
  try {
    std::cout << *easyfind(v, 42) << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

int main() {
  shouldWorkWithVector();
  shouldWorkWithList();
}
