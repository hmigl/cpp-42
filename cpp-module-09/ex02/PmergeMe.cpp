/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:13:24 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/29 13:41:53 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMe.hpp"

PmergeMe::PmergeMe() : l_(), d_() {}

PmergeMe::PmergeMe(std::list<int> &l, std::deque<int> &d) : l_(l), d_(d) {}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  if (this != &other) {
    l_ = other.l_;
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

  std::list<int> l;
  PmergeMe::fill_cont(l, v.begin(), v.end());
  std::deque<int> d;
  PmergeMe::fill_cont(d, v.begin(), v.end());
  std::cout << "42069\n";
  return PmergeMe(l, d);
}

void PmergeMe::print_before() const {
  std::cout << "Before: ";
  if (l_.empty()) {
    std::cout << "empty";
    return;
  }
  // TODO: if (is_sorted()) std::cout << "sorted seq...";
  int i = 0;
  for (std::list<int>::const_iterator it = l_.begin(); it != l_.end();
       ++it, ++i) {
    if (i == 10) {
      std::cout << "[...]";
      break;
    }
    std::cout << (*it) << ' ';
  }
  std::cout << '\n';
}
