/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:32:17 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/02 20:01:26 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", GradeToSign, GradeToExecute),
      target_("target") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", GradeToSign, GradeToExecute),
      target_(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(other), target_(other.target_) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(
    const PresidentialPardonForm &other) {
  AForm::operator=(other);
  return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &b) const {
  AForm::execute(b);
  std::cout << target_ << " has been pardoned by Zaphod Beeblebrox\n";
}
