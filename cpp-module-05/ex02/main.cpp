/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:50:56 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/02 20:22:09 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>

#include "./PresidentialPardonForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./ShrubberyCreationForm.hpp"

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
  } catch (const AForm::GradeTooLowException &e) {
    std::cout << e.what() << std::endl;
  }
}

int main() {
  shouldValidatePresidentialPardonForm();
  return 0;
}
