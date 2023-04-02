/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:19:31 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/02 12:46:00 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("Beauro Crat"), grade_(LowestPossibleGrade) {}

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade)
    : name_(name), grade_(grade) {
  if (grade < HighestPossibleGrade) throw Bureaucrat::GradeTooHighException();
  if (grade > LowestPossibleGrade) throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) { *this = other; }

Bureaucrat::~Bureaucrat() {}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade Too High Exception";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade Too Low Exception";
}

void Bureaucrat::incrementGrade() {
  if (grade_ - 1 < HighestPossibleGrade) {
    throw Bureaucrat::GradeTooHighException();
  }
  --grade_;
}

void Bureaucrat::decrementGrade() {
  if (grade_ + 1 > LowestPossibleGrade) {
    throw Bureaucrat::GradeTooLowException();
  }
  ++grade_;
}

void Bureaucrat::signForm(Form &form) {
  try {
    form.beSigned(*this);
    std::cout << name_ << " signed " << form.getName() << std::endl;
  } catch (const Form::GradeTooLowException &e) {
    std::cout << name_ << " couldn't sign " << form.getName() << " because ";
    std::cout << e.what() << std::endl;
  }
}

const std::string &Bureaucrat::getName() const { return name_; }

unsigned int Bureaucrat::getGrade() const { return grade_; }

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  if (this != &other) {
    grade_ = other.grade_;
  }
  return *this;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj) {
  os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
  return os;
}
