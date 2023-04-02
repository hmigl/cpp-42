/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:13:52 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/02 12:53:24 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>
#include <iostream>

#include "./Bureaucrat.hpp"
#include "./Form.hpp"

const std::string &BureaucratName = "Beauro Crat";
const std::string &FormName = "Generic form";

void shouldNotSignForm() {
  std::cout << "shouldNotSignForm\n";

  Bureaucrat b(BureaucratName, 42);
  std::cout << b << std::endl;
  Form f(FormName, 10, 10);
  std::cout << f << std::endl;
  try {
    b.signForm(f);
    std::cout << f << std::endl;
  } catch (const Form::GradeTooLowException &e) {
    std::cout << f << std::endl;
  }
}

void shouldSignForm() {
  std::cout << "shouldSignForm\n";

  Bureaucrat b(BureaucratName, 5);
  std::cout << b << std::endl;
  Form f(FormName, 10, 10);
  std::cout << f << std::endl;
  try {
    b.signForm(f);
    std::cout << f << std::endl;
  } catch (const Form::GradeTooLowException &e) {
    std::cout << "this line should be unreachable";
  }
  std::cout << std::endl;
}

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
  shouldSignForm();
  shouldNotSignForm();
  return 0;
}
