/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:22:45 by hmigl             #+#    #+#             */
/*   Updated: 2023/05/02 08:55:32 by hmigl            ###   ########.fr       */
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

  typedef std::vector<int>::iterator VectorIt;
  typedef std::vector<int>::const_iterator VectorConstIt;

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

  template <typename ContIt, typename Cont>
  void merge_insertion_sort(ContIt begin, ContIt end) {
    if (end - begin > PmergeMe::GroupSize) {
      ContIt middle = begin;
      std::advance(middle, (end - begin) / 2);
      merge_insertion_sort<ContIt, Cont>(begin, middle);
      merge_insertion_sort<ContIt, Cont>(middle, end);
      merge<ContIt, Cont>(begin, middle, end);
    } else {
      insertion_sort<ContIt>(begin, end);
    }
  }

  template <typename ContIt, typename Cont>
  void merge(ContIt begin, ContIt middle, ContIt end) {
    Cont temp(end - begin);
    ContIt left = begin, right = middle, temp_it = temp.begin();

    while (left != middle && right != end) {
      if (*left <= *right) {
        *temp_it++ = *left++;
      } else {
        *temp_it++ = *right++;
      }
    }

    while (left != middle) {
      *temp_it++ = *left++;
    }
    while (right != end) {
      *temp_it++ = *right++;
    }
    std::copy(temp.begin(), temp.end(), begin);
  }

  template <typename ContIt>
  void insertion_sort(ContIt begin, ContIt end) {
    for (ContIt it = begin + 1; it != end; ++it) {
      int key = *it;
      ContIt prev_it = it - 1;
      while (prev_it >= begin && *prev_it > key) {
        *(prev_it + 1) = *prev_it;
        --prev_it;
      }
      *(prev_it + 1) = key;
    }
  }
};
