/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:13:24 by hmigl             #+#    #+#             */
/*   Updated: 2023/05/01 18:15:55 by hmigl            ###   ########.fr       */
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
  std::cout << "Before: ";
  if (v_.empty()) {
    std::cout << "empty";
    return;
  }
  // TODO: if (is_sorted()) std::cout << "sorted seq...";
  int i = 0;
  for (VectorConstIt it = v_.begin(); it != v_.end(); ++it, ++i) {
    if (i == 10) {
      std::cout << "[...]";
      break;
    }
    std::cout << (*it) << ' ';
  }
  std::cout << '\n';
}

void PmergeMe::print_after() const {
  std::cout << "After:  ";
  if (d_.empty()) {
    std::cout << "empty";
    return;
  }
  int i = 0;
  for (DequeConstIt it = d_.begin(); it != d_.end(); ++it, ++i) {
    if (i == 10) {
      std::cout << "[...]";
      break;
    }
    std::cout << (*it) << ' ';
  }
  std::cout << '\n';
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
  merge_insertion_sort(d_, d_.begin(), d_.end());
  std::clock_t end_time = std::clock();
  elapsed_time_d_ = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

  start_time = std::clock();
  merge_insertion_sort(v_.begin(), v_.end());
  end_time = std::clock();
  elapsed_time_v_ = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
}

/*
 * Implementation for std::deque<int>
 * */
void PmergeMe::merge_insertion_sort(std::deque<int> &d, DequeIt begin,
                                    DequeIt end) {
  if (end - begin > PmergeMe::GroupSize) {
    DequeIt middle = begin;
    std::advance(middle, (end - begin) / 2);
    merge_insertion_sort(d, begin, middle);
    merge_insertion_sort(d, middle, end);
    merge(begin, middle, end);
  } else {
    insertion_sort(begin, end);
  }
}

void PmergeMe::merge(DequeIt begin, DequeIt middle, DequeIt end) {
  std::deque<int> temp(end - begin);
  DequeIt left = begin, right = middle, temp_it = temp.begin();

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

void PmergeMe::insertion_sort(DequeIt begin, DequeIt end) {
  for (DequeIt it = begin + 1; it != end; ++it) {
    int key = *it;
    DequeIt prev_it = it - 1;
    while (prev_it != begin - 1 && *prev_it > key) {
      *(prev_it + 1) = *prev_it;
      --prev_it;
    }
    *(prev_it + 1) = key;
  }
}

/*
 * Implementation for std::vector<int>
 * */
void PmergeMe::merge_insertion_sort(VectorIt begin, VectorIt end) {}

void PmergeMe::merge(VectorIt begin, VectorIt middle, VectorIt end) {}
