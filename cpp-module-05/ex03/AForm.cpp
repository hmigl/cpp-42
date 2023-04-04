/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 10:32:15 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/02 15:20:44 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AForm.hpp"

AForm::AForm()
    : name_("Generic form"),
      isSigned_(false),
      requiredGradeToSign_(LowestPossibleGrade),
      requiredGradeToExecute_(LowestPossibleGrade) {}

AForm::AForm(const AForm &other)
    : name_(other.name_),
      isSigned_(other.isSigned_),
      requiredGradeToSign_(other.requiredGradeToSign_),
      requiredGradeToExecute_(other.requiredGradeToExecute_) {}

AForm::AForm(const std::string &name, unsigned int requiredGradeToSign,
             unsigned int requiredGradeToExecute)
    : name_(name),
      isSigned_(false),
      requiredGradeToSign_(requiredGradeToSign),
      requiredGradeToExecute_(requiredGradeToExecute) {
  if (requiredGradeToSign < HighestPossibleGrade ||
      requiredGradeToExecute < HighestPossibleGrade) {
    throw AForm::GradeTooHighException();
  }
  if (requiredGradeToSign > LowestPossibleGrade ||
      requiredGradeToExecute > LowestPossibleGrade) {
    throw AForm::GradeTooLowException();
  }
}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &other) {
  if (this != &other) {
    isSigned_ = other.isSigned_;
  }
  return *this;
}

void AForm::beSigned(const Bureaucrat &b) {
  b.getGrade() <= requiredGradeToSign_ ? isSigned_ = true
                                       : throw AForm::GradeTooLowException();
}

void AForm::execute(const Bureaucrat &executor) const {
  if (!isSigned_) {
    throw AForm::UnsignedFormException();
  }
  if (executor.getGrade() > requiredGradeToExecute_) {
    throw AForm::GradeTooLowException();
  }
}

const std::string &AForm::getName() const { return name_; }

bool AForm::getIsSigned() const { return isSigned_; }

unsigned int AForm::getRequiredGradeToSign() const {
  return requiredGradeToSign_;
}

unsigned int AForm::getRequiredGradeToExecute() const {
  return requiredGradeToExecute_;
}

const char *AForm::GradeTooHighException::what() const throw() {
  return "(AForm) Grade Too High Exception";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "(AForm) Grade Too Low Exception";
}

const char *AForm::UnsignedFormException::what() const throw() {
  return "(AForm) Unsigned Form Exception";
}

std::ostream &operator<<(std::ostream &os, const AForm &obj) {
  os << "name: " << obj.getName() << " | isSigned: " << obj.getIsSigned()
     << " | requiredGradeToSign: " << obj.getRequiredGradeToSign()
     << " | requiredGradeToExecute: " << obj.getRequiredGradeToExecute();
  return os;
}
