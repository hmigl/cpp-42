/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:59:48 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/20 09:59:49 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>

class Span {
 public:
  explicit Span(unsigned int);
  Span(const Span &);
  Span &operator=(const Span &);
  ~Span();

  void addNumber();
  template <typename InputIt>
  void insertRange(InputIt first, InputIt last);
  unsigned int shortestSpan() const;
  unsigned int longestSpan() const;

 private:
  Span();

  std::vector<unsigned int> elements_;
  unsigned int maxCapacity_;
};
