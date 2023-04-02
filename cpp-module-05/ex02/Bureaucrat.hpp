/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:18:58 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/02 14:19:27 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ostream>
#include <string>

#include "./AForm.hpp"

class AForm;

class Bureaucrat {
 public:
  Bureaucrat();
  Bureaucrat(const std::string &name, unsigned int grade);
  Bureaucrat(const Bureaucrat &);
  ~Bureaucrat();

  Bureaucrat &operator=(const Bureaucrat &);

  void incrementGrade();
  void decrementGrade();
  void signForm(AForm &);

  const std::string &getName() const;
  unsigned int getGrade() const;

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
  unsigned int grade_;
};

std::ostream &operator<<(std::ostream &, const Bureaucrat &);
