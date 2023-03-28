/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 09:06:20 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/28 09:39:41 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Brain.hpp"

Brain::Brain() : ideas_() {
  std::cout << "(Brain) Default constructor called\n";
}

Brain::Brain(const Brain &other) {
  std::cout << "(Brain) Copy constructor called\n";
  *this = other;
}

Brain::~Brain() { std::cout << "(Brain) Destructor called\n"; }

const std::string *Brain::getIdeas() const { return ideas_; }

Brain &Brain::operator=(const Brain &other) {
  if (this != &other) {
    for (int i = 0; i < NbIdeas; ++i) {
      ideas_[i] = other.ideas_[i];
    }
  }
  return *this;
}
