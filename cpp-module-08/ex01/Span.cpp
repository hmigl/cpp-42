/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:01:18 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/20 12:04:32 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Span.hpp"

Span::Span() : elements_(), maxCapacity_(0) {}

Span::Span(unsigned int maxCapacity) : elements_(), maxCapacity_(maxCapacity) {}

Span::Span(const Span &other) { *this = other; }

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    elements_ = other.elements_;
    maxCapacity_ = other.maxCapacity_;
  }
  return *this;
}

void Span::addNumber(int num) {
  if (elements_.size() + 1 <= maxCapacity_) {
    elements_.push_back(num);
  } else {
    throw std::length_error("Adding one more number exceeds max capacity");
  }
}

void Span::insertRange(std::vector<int>::iterator first,
                       std::vector<int>::iterator last) {
  if (elements_.size() + std::distance(first, last) > maxCapacity_) {
    throw std::length_error("Adding more numbers exceeds max capacity");
  }
  elements_.insert(elements_.end(), first, last);
}

unsigned int Span::shortestSpan() const { return 0; }

unsigned int Span::longestSpan() const { return 0; }

Span::~Span() {}
