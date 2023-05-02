/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:22:45 by hmigl             #+#    #+#             */
/*   Updated: 2023/05/01 22:28:32 by hmigl            ###   ########.fr       */
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
#include <string>
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
  void merge_insertion_sort(DequeIt, DequeIt);
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

  template <typename Cont>
  void print_before(const std::string &cont_name, const Cont &cont) const {
    std::cout << "Before (" << cont_name << "): ";
    if (cont.empty()) {
      std::cout << "empty";
      return;
    }
    int i = 0;
    for (typename Cont::const_iterator it = cont.begin(); it != cont.end();
         ++it, ++i) {
      if (i == 10) {
        std::cout << "[...]";
        break;
      }
      std::cout << (*it) << ' ';
    }
    std::cout << '\n';
  }

  template <typename Cont>
  void print_after(const std::string &cont_name, const Cont &cont) const {
    std::cout << "After (" << cont_name << "): ";
    if (cont.empty()) {
      std::cout << "empty\n";
      return;
    }
    if (!is_sorted(cont.begin(), cont.end())) {
      std::cout << "unsorted container\n";
      return;
    }
    int i = 0;
    for (typename Cont::const_iterator it = cont.begin(); it != cont.end();
         ++it, ++i) {
      if (i == 10) {
        std::cout << "[...]";
        break;
      }
      std::cout << (*it) << ' ';
    }
    std::cout << '\n';
  }
};
