/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:16:18 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/04 07:15:39 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) { *this = other; }

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &other) {
  if (this != &other) {
  }
  return *this;
}

AForm *Intern::makeForm(const std::string &formName,
                        const std::string &target) const {
  const std::string availableForms[3] = {
      "shrubbery creation", "robotomy request", "presidential pardon"};

  AForm *(Intern::*forms[3])(const std::string &target)
      const = {&Intern::makeShrubberyCreationFormForm,
               &Intern::makeRobotomyRequestFormForm,
               &Intern::makePresidentialPardonForm};
  for (int i = 0; i < 3; ++i) {
    if (!formName.compare(availableForms[i])) {
      std::cout << "Intern creates " << formName << std::endl;
      return (this->*forms[i])(target);
    }
  }
  throw std::logic_error("Intern says: No more forms! I quit!!!\n");
}

AForm *Intern::makeShrubberyCreationFormForm(const std::string &target) const {
  return new ShrubberyCreationForm(target);
}
AForm *Intern::makeRobotomyRequestFormForm(const std::string &target) const {
  return new RobotomyRequestForm(target);
}
AForm *Intern::makePresidentialPardonForm(const std::string &target) const {
  return new PresidentialPardonForm(target);
}
