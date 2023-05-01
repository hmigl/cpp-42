/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:22:45 by hmigl             #+#    #+#             */
/*   Updated: 2023/05/01 10:36:22 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <limits>
#include <list>
#include <stdexcept>
#include <vector>

class PmergeMe {
 public:
  PmergeMe(std::list<int> &, std::deque<int> &);
  PmergeMe(const PmergeMe &);
  PmergeMe &operator=(const PmergeMe &);
  ~PmergeMe();

  static PmergeMe from_sequence(const char **);
  void print_before() const;
  void sort();
  void print_after() const;

 private:
  PmergeMe();

  std::list<int> l_;
  std::deque<int> d_;

  typedef std::deque<int>::iterator DequeIt;
  typedef std::deque<int>::const_iterator DequeConstIt;
  void merge_insert_sort(std::deque<int> &, DequeIt, DequeIt);
  void merge(DequeIt, DequeIt, DequeIt);

  template <typename Cont, typename ContIt>
  static void fill_cont(Cont &cont, ContIt first, ContIt last) {
    cont.insert(cont.end(), first, last);
  }
};
