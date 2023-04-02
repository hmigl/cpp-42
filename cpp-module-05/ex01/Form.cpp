/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 10:32:15 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/02 12:47:35 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Form.hpp"

Form::Form()
    : name_("Generic form"),
      isSigned_(false),
      requiredGradeToSign_(LowestPossibleGrade),
      requiredGradeToExecute_(LowestPossibleGrade) {}

Form::Form(const Form &other)
    : name_(other.name_),
      isSigned_(other.isSigned_),
      requiredGradeToSign_(other.requiredGradeToSign_),
      requiredGradeToExecute_(other.requiredGradeToExecute_) {}

Form::Form(const std::string &name, unsigned int requiredGradeToSign,
           unsigned int requiredGradeToExecute)
    : name_(name),
      isSigned_(false),
      requiredGradeToSign_(requiredGradeToSign),
      requiredGradeToExecute_(requiredGradeToExecute) {
  if (requiredGradeToSign < HighestPossibleGrade ||
      requiredGradeToExecute < HighestPossibleGrade) {
    throw Form::GradeTooHighException();
  }
  if (requiredGradeToSign > LowestPossibleGrade ||
      requiredGradeToExecute > LowestPossibleGrade) {
    throw Form::GradeTooLowException();
  }
}

Form::~Form() {}

Form &Form::operator=(const Form &other) {
  if (this != &other) {
    isSigned_ = other.isSigned_;
  }
  return *this;
}

void Form::beSigned(const Bureaucrat &b) {
  b.getGrade() <= requiredGradeToSign_ ? isSigned_ = true
                                       : throw Form::GradeTooLowException();
}

const std::string &Form::getName() const { return name_; }

bool Form::getIsSigned() const { return isSigned_; }

unsigned int Form::getRequiredGradeToSign() const {
  return requiredGradeToSign_;
}

unsigned int Form::getRequiredGradeToExecute() const {
  return requiredGradeToExecute_;
}

const char *Form::GradeTooHighException::what() const throw() {
  return "(Form) Grade Too High Exception";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "(Form) Grade Too Low Exception";
}

std::ostream &operator<<(std::ostream &os, const Form &obj) {
  os << "name: " << obj.getName() << " | isSigned: " << obj.getIsSigned()
     << " | requiredGradeToSign: " << obj.getRequiredGradeToSign()
     << " | requiredGradeToExecute: " << obj.getRequiredGradeToExecute();
  return os;
}
