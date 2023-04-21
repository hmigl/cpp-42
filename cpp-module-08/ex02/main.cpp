/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:38:19 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/21 10:58:04 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>

#include "./MutantStack.hpp"

void shouldWorkWithList() {
  std::cout << "std::list:\n";
  std::list<int> mlist;

  mlist.push_back(5);
  mlist.push_back(17);
  std::cout << mlist.back() << std::endl;
  mlist.pop_back();
  std::cout << mlist.size() << std::endl;
  mlist.push_back(3);
  mlist.push_back(5);
  mlist.push_back(737);
  mlist.push_back(0);

  std::list<int>::iterator it = mlist.begin();
  std::list<int>::iterator ite = mlist.end();
  ++it;
  --it;

  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
}

int main() {
  std::cout << "MutantStack:\n";
  MutantStack<int> mstack;

  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);

  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;

  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);
  std::cout << "------------------------\n";
  shouldWorkWithList();
  return 0;
}
