/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:50:56 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/03 07:30:56 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>

#include "./PresidentialPardonForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./ShrubberyCreationForm.hpp"

void shouldExecuteForm() {
  std::cout << "shouldExecuteForm\n";

  Bureaucrat b("Beauro Crat", 1);
  std::cout << b << std::endl;
  RobotomyRequestForm form("ChatGPT");
  b.signForm(form);
  b.executeForm(form);
}

void shouldValidateShrubberyCreationForm() {
  std::cout << "shouldValidateShrubberyCreationForm\n";

  ShrubberyCreationForm form("home");
  std::cout << form << std::endl;
  assert(form.getName() == "ShrubberyCreationForm");
  assert(form.getRequiredGradeToSign() == 145);
  assert(form.getRequiredGradeToExecute() == 137);
  try {
    Bureaucrat b("Beauro Crat", 125);
    std::cout << b << std::endl;
    form.beSigned(b);
    form.execute(b);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
}

void shouldValidateRobotomyRequestForm() {
  std::cout << "shouldValidateRobotomyRequestForm\n";

  RobotomyRequestForm form("Jarvis");
  std::cout << form << std::endl;
  assert(form.getName() == "RobotomyRequestForm");
  assert(form.getRequiredGradeToSign() == 72);
  assert(form.getRequiredGradeToExecute() == 45);
  try {
    Bureaucrat b("Beauro Crat", 15);
    std::cout << b << std::endl;
    form.beSigned(b);
    form.execute(b);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
}

void shouldValidatePresidentialPardonForm() {
  std::cout << "shouldValidatePresidentialPardonForm\n";

  PresidentialPardonForm form("Rodion Raskolnikov");
  std::cout << form << std::endl;
  assert(form.getName() == "PresidentialPardonForm");
  assert(form.getRequiredGradeToSign() == 25);
  assert(form.getRequiredGradeToExecute() == 5);
  try {
    Bureaucrat b("Beauro Crat", 1);
    std::cout << b << std::endl;
    form.beSigned(b);
    form.execute(b);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
}

int main() {
  shouldValidatePresidentialPardonForm();
  shouldValidateRobotomyRequestForm();
  shouldValidateShrubberyCreationForm();
  shouldExecuteForm();
  return 0;
}
