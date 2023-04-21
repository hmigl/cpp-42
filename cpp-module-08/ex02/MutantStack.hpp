/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:20:40 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/21 10:56:30 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <deque>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
 public:
  MutantStack() : std::stack<T>() {}
  MutantStack(const MutantStack &other) : std::stack<T>(other) {}
  MutantStack &operator=(const MutantStack &other) {
    if (this != &other) {
      std::stack<T>::operator=(other);
    }
    return *this;
  }

  typedef typename std::deque<T>::iterator iterator;

  // call underlying container:
  iterator begin() { return std::stack<T>::c.begin(); }
  iterator end() { return std::stack<T>::c.end(); }

  ~MutantStack() {
    while (!(this->empty())) {
      this->pop();
    }
  }
};
