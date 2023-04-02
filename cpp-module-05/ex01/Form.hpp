/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 10:01:56 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/02 11:31:54 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "./Bureaucrat.hpp"

class Bureaucrat;

class Form {
 public:
  Form();
  Form(const Form &);
  Form(const std::string &name, unsigned int requiredGradeToSign,
       unsigned int requiredGradeToExecute);
  ~Form();

  Form &operator=(const Form &);

  void beSigned(const Bureaucrat &);

  const std::string &getName() const;
  bool getIsSigned() const;
  unsigned int getRequiredGradeToSign() const;
  unsigned int getRequiredGradeToExecute() const;

  class GradeTooHighException : public std::exception {
   public:
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    const char *what() const throw();
  };

 private:
  static const unsigned int HighestPossibleGrade = 1;
  static const unsigned int LowestPossibleGrade = 150;

  const std::string name_;
  bool isSigned_;
  const unsigned int requiredGradeToSign_;
  const unsigned int requiredGradeToExecute_;
};

std::ostream &operator<<(std::ostream &, const Form &);
