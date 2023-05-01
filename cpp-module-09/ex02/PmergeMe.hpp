/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:22:45 by hmigl             #+#    #+#             */
/*   Updated: 2023/05/01 18:41:27 by hmigl            ###   ########.fr       */
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
  PmergeMe(std::vector<int> &, std::deque<int> &);
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

  std::vector<int> v_;
  std::deque<int> d_;
  double elapsed_time_v_;
  double elapsed_time_d_;

  typedef std::deque<int>::iterator DequeIt;
  typedef std::deque<int>::const_iterator DequeConstIt;
  void merge_insertion_sort(std::deque<int> &, DequeIt, DequeIt);
  void merge(DequeIt, DequeIt, DequeIt);
  void insertion_sort(DequeIt, DequeIt);

  typedef std::vector<int>::iterator VectorIt;
  typedef std::vector<int>::const_iterator VectorConstIt;
  void merge_insertion_sort(VectorIt, VectorIt);
  void merge(VectorIt, VectorIt, VectorIt);
  void insertion_sort(VectorIt, VectorIt);

  template <typename Cont, typename ContIt>
  static void fill_cont(Cont &cont, ContIt first, ContIt last) {
    cont.insert(cont.end(), first, last);
  }

  template <typename ContIt>
  static bool is_sorted(ContIt begin, ContIt end) {
    for (ContIt it = begin + 1; it != end; ++it) {
      if (*it < *(it - 1)) {
        return false;
      }
    }
    return true;
  }
};
