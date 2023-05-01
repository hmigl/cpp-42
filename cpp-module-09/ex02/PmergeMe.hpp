/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:22:45 by hmigl             #+#    #+#             */
/*   Updated: 2023/05/01 17:07:10 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <cstring>
#include <ctime>
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
  void print_stats() const;

 private:
  PmergeMe();

  static const int GroupSize = 25;

  std::list<int> l_;
  std::deque<int> d_;
  double elapsed_time_l_;
  double elapsed_time_d_;

  typedef std::deque<int>::iterator DequeIt;
  typedef std::deque<int>::const_iterator DequeConstIt;
  void merge_insertion_sort(std::deque<int> &, DequeIt, DequeIt);
  void merge(DequeIt, DequeIt, DequeIt);
  void insertion_sort(DequeIt, DequeIt);

  template <typename Cont, typename ContIt>
  static void fill_cont(Cont &cont, ContIt first, ContIt last) {
    cont.insert(cont.end(), first, last);
  }
};
