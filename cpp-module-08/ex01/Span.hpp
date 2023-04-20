/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:59:48 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/20 13:40:08 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <limits>
#include <stdexcept>
#include <vector>

class Span {
 public:
  explicit Span(unsigned int);
  Span(const Span &);
  Span &operator=(const Span &);
  ~Span();

  void addNumber(int);
  void insertRange(std::vector<int>::iterator, std::vector<int>::iterator);
  unsigned int shortestSpan() const;
  unsigned int longestSpan() const;

 private:
  Span();

  std::vector<int> elements_;
  unsigned int maxCapacity_;
};
