/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:13:52 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/02 12:18:56 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>
#include <iostream>

#include "./Bureaucrat.hpp"
#include "./Form.hpp"

const std::string &Name = "Beauro Crat";
const std::string &FormName = "Generic form";

// void shouldDecrementGrade() {
//   std::cout << "shouldDecrementGrade\n";
//
//   std::cout << "creating bureaucrat with grade == 42\n";
//   Bureaucrat b(Name, 42);
//   std::cout << "( " << b << " )\n";
//   for (int i = 0; i < 10; ++i) {
//     b.decrementGrade();
//   }
//   std::cout << "asserting that grade == 52\n";
//   std::cout << "( " << b << " )\n";
//   assert(b.getGrade() == 52);
// }

// void shouldIncrementGrade() {
//   std::cout << "shouldIncrementGrade\n";
//
//   std::cout << "creating default bureaucrat with grade == 150\n";
//   Bureaucrat b;
//   std::cout << "( " << b << " )\n";
//   for (int i = 0; i < 10; ++i) {
//     b.incrementGrade();
//   }
//   std::cout << "asserting that grade == 140\n";
//   assert(b.getGrade() == 140);
//   std::cout << "( " << b << " )\n";
//   std::cout << std::endl;
// }

void shouldThrowGradeTooHighException() {
  std::cout << "shouldThrowGradeTooHighException\n";

  try {
    std::cout << "creating form with requiredGradeToExecute greater than 1\n";
    Form f(FormName, 149, 0);
  } catch (Form::GradeTooHighException &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::cout << "creating form with requiredGradeToSign greater than 1\n";
    Form f(FormName, 0, 42);
  } catch (Form::GradeTooHighException &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
}

void shouldThrowGradeTooLowException() {
  std::cout << "shouldThrowGradeTooLowException\n";

  try {
    std::cout << "creating form with requiredGradeToExecute lower than 150\n";
    Form f(FormName, 149, 151);
  } catch (Form::GradeTooLowException &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::cout << "creating form with requiredGradeToSign lower than 150\n";
    Form f(FormName, 151, 149);
  } catch (Form::GradeTooLowException &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
}

int main() {
  shouldThrowGradeTooLowException();
  shouldThrowGradeTooHighException();
  // shouldIncrementGrade();
  // shouldDecrementGrade();
  return 0;
}
