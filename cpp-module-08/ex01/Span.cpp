/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:01:18 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/20 10:11:02 by hmigl            ###   ########.fr       */
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

void Span::addNumber(unsigned int) {}

template <typename InputIt>
void Span::insertRange(InputIt first, InputIt last) {}

unsigned int Span::shortestSpan() const { return 0; }

unsigned int Span::longestSpan() const { return 0; }

Span::~Span() {}
