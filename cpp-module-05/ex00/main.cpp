/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:13:52 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/02 09:13:04 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "./Bureaucrat.hpp"

const std::string &Name = "Beauro Crat";

void should_throw_grade_too_low_exception_test() {
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
}

int main() {
  should_throw_grade_too_low_exception_test();
  return 0;
}
