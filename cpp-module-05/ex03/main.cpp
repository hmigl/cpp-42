/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:50:56 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/04 07:26:59 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>

#include "./Intern.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./ShrubberyCreationForm.hpp"

void shouldNotCreateForm() {
  try {
    Intern intern;
    AForm *form = intern.makeForm("vscode is better than vim (lol)", "js dev");
    std::cout << form << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what();
  }
}

void shouldValidateShrubberyCreationForm() {
  std::cout << "shouldValidateShrubberyCreationForm\n";

  Intern intern;
  AForm *form = intern.makeForm("shrubbery creation", "hoem");
  assert(form->getName() == "ShrubberyCreationForm");
  assert(form->getRequiredGradeToSign() == 145);
  assert(form->getRequiredGradeToExecute() == 137);
  try {
    Bureaucrat b("Beauro Crat", 125);
    std::cout << b << std::endl;
    form->beSigned(b);
    form->execute(b);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  delete form;
  std::cout << std::endl;
}

void shouldValidateRobotomyRequestForm() {
  std::cout << "shouldValidateRobotomyRequestForm\n";

  Intern intern;
  AForm *form = intern.makeForm("robotomy request", "Jarvis");
  assert(form->getName() == "RobotomyRequestForm");
  assert(form->getRequiredGradeToSign() == 72);
  assert(form->getRequiredGradeToExecute() == 45);
  try {
    Bureaucrat b("Beauro Crat", 15);
    std::cout << b << std::endl;
    form->beSigned(b);
    form->execute(b);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  delete form;
  std::cout << std::endl;
}

void shouldValidatePresidentialPardonForm() {
  std::cout << "shouldValidatePresidentialPardonForm\n";

  Intern intern;
  AForm *form = intern.makeForm("presidential pardon", "Rodion Raskolnikov");
  assert(form->getName() == "PresidentialPardonForm");
  assert(form->getRequiredGradeToSign() == 25);
  assert(form->getRequiredGradeToExecute() == 5);
  try {
    Bureaucrat b("Beauro Crat", 1);
    std::cout << b << std::endl;
    form->beSigned(b);
    form->execute(b);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  delete form;
  std::cout << std::endl;
}

int main() {
  shouldValidatePresidentialPardonForm();
  shouldValidateRobotomyRequestForm();
  shouldValidateShrubberyCreationForm();
  shouldNotCreateForm();
  return 0;
}
