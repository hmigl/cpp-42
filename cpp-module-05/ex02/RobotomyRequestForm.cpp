/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:24:56 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/02 20:02:24 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", GradeToSign, GradeToExecute),
      target_("target") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", GradeToSign, GradeToExecute),
      target_(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target_(other.target_) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    const RobotomyRequestForm &other) {
  AForm::operator=(other);
  return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &b) const {
  AForm::execute(b);
  srand(time(0));    // Seed the random number generator with the current time
  if (rand() % 2) {  // Generate a random number between 0 and 1
    std::cout << target_ << " has been robotomized successfully\n";
  } else {
    std::cout << target_ << "'s robotomy failed\n";
  }
}
