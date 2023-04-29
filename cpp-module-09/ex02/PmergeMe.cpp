/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:13:24 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/29 10:15:28 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const char **seq) {
  if (seq == NULL || (*seq) == NULL) {
    throw std::invalid_argument("yadayada");
  }
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
  }
  std::cout << "42069\n";
}

PmergeMe::PmergeMe(const PmergeMe &) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &) {}

PmergeMe::~PmergeMe() {}
