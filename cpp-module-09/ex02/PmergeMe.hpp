/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:22:45 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/29 12:31:46 by hmigl            ###   ########.fr       */
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

 private:
  PmergeMe();

  std::list<int> l_;
  std::deque<int> d_;

  template <typename Cont, typename InputIt>
  static void fill_cont(Cont &cont, InputIt first, InputIt last) {
    cont.insert(cont.end(), first, last);
  }
};
