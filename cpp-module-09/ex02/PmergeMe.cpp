/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:13:24 by hmigl             #+#    #+#             */
/*   Updated: 2023/05/02 08:57:27 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMe.hpp"

PmergeMe::PmergeMe() : v_(), d_(), elapsed_time_v_(0), elapsed_time_d_(0) {}

PmergeMe::PmergeMe(std::vector<int> &v, std::deque<int> &d)
    : v_(v), d_(d), elapsed_time_v_(0), elapsed_time_d_(0) {}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  if (this != &other) {
    v_ = other.v_;
    d_ = other.d_;
  }
  return *this;
}

PmergeMe::~PmergeMe() {}

PmergeMe PmergeMe::from_sequence(const char **seq) {
  if (seq == NULL || (*seq) == NULL) {
    throw std::invalid_argument("yadayada");
  }

  std::vector<int> v;
  for (size_t i = 0; seq[i]; ++i) {
    const char *str = seq[i];
    while (*str) {
      if (!std::isdigit(*str)) {
        throw std::invalid_argument("yadayada2");
      }
      ++str;
    }
    int n = std::atol(seq[i]);
    if (n < 1 || n > std::numeric_limits<int>::max()) {
      throw std::invalid_argument("yadayada3");
    }
    v.push_back(n);
  }

  std::deque<int> d;
  PmergeMe::fill_cont(d, v.begin(), v.end());
  return PmergeMe(v, d);
}

void PmergeMe::print_before() const {
  print_before("std::deque", d_);
  print_before("std::vector", v_);
}

void PmergeMe::print_after() const {
  print_after("std::deque", d_);
  print_after("std::vector", v_);
}

void PmergeMe::print_stats() const {
  std::cout << "Time to process a range of " << d_.size()
            << " elements with std::deque => " << elapsed_time_d_
            << " seconds\n";
  std::cout << "Time to process a range of " << v_.size()
            << " elements with std::vector => " << elapsed_time_v_
            << " seconds\n";
}

void PmergeMe::sort() {
  std::clock_t start_time = std::clock();
  merge_insertion_sort<DequeIt, std::deque<int> >(d_.begin(), d_.end());
  std::clock_t end_time = std::clock();
  elapsed_time_d_ = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

  start_time = std::clock();
  merge_insertion_sort<VectorIt, std::vector<int> >(v_.begin(), v_.end());
  end_time = std::clock();
  elapsed_time_v_ = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
}
