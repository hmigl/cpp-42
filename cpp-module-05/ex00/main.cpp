/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:13:52 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/02 09:37:39 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>
#include <iostream>

#include "./Bureaucrat.hpp"

const std::string &Name = "Beauro Crat";

void shouldDecrementGrade() {
  std::cout << "shouldDecrementGrade\n";

  std::cout << "creating bureaucrat with grade == 42\n";
  Bureaucrat b(Name, 42);
  for (int i = 0; i < 10; ++i) {
    b.decrementGrade();
  }
  std::cout << "asserting that grade == 52\n";
  assert(b.getGrade() == 52);
}

void shouldIncrementGrade() {
  std::cout << "shouldIncrementGrade\n";

  std::cout << "creating default bureaucrat with grade == 150\n";
  Bureaucrat b;
  for (int i = 0; i < 10; ++i) {
    b.incrementGrade();
  }
  std::cout << "asserting that grade == 140\n";
  assert(b.getGrade() == 140);
  std::cout << std::endl;
}

void shouldThrowGradeTooHighException() {
  std::cout << "shouldThrowGradeTooHighException\n";

  try {
    std::cout << "creating default bureaucrat and trying to increment grade "
                 "untill 0\n";
    Bureaucrat b;
    while (b.getGrade() != 0) {
      b.incrementGrade();
    }
  } catch (Bureaucrat::GradeTooHighException &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::cout << "creating bureaucrat with grade higher than 1\n";
    Bureaucrat b(Name, 0);
  } catch (Bureaucrat::GradeTooHighException &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
}

void shouldThrowGradeTooLowException() {
  std::cout << "shouldThrowGradeTooLowException\n";

  try {
    std::cout << "creating default bureaucrat and trying to decrement grade\n";
    Bureaucrat b;
    b.decrementGrade();
  } catch (Bureaucrat::GradeTooLowException &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::cout << "creating bureaucrat with grade lower than 150\n";
    Bureaucrat b(Name, 151);
  } catch (Bureaucrat::GradeTooLowException &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
}

int main() {
  shouldThrowGradeTooLowException();
  shouldThrowGradeTooHighException();
  shouldIncrementGrade();
  shouldDecrementGrade();
  return 0;
}
