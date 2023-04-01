/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:18:58 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/01 18:07:06 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ostream>
#include <string>

class Bureaucrat {
 public:
  Bureaucrat();
  Bureaucrat(const std::string &name, unsigned int grade);
  Bureaucrat(const Bureaucrat &);
  ~Bureaucrat();

  class GradeTooHighException : public std::exception {
   public:
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    const char *what() const throw();
  };

  void incrementGrade();
  void decrementGrade();

  const std::string &getName() const;
  unsigned int getGrade() const;

  Bureaucrat &operator=(const Bureaucrat &);

 private:
  static const unsigned int HighestPossibleGrade = 1;
  static const unsigned int LowestPossibleGrade = 150;

  const std::string name_;
  unsigned int grade_;
};

std::ostream &operator<<(std::ostream &, const Bureaucrat &);
