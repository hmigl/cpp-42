/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:20:31 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/02 19:35:27 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include <ios>
#include <string>

#include "./AForm.hpp"

class ShrubberyCreationForm : public AForm {
 public:
  explicit ShrubberyCreationForm(const std::string &);
  ShrubberyCreationForm(const ShrubberyCreationForm &);
  ~ShrubberyCreationForm();

  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);

  void execute(const Bureaucrat &);

 private:
  ShrubberyCreationForm();

  static const unsigned int GradeToSign = 145;
  static const unsigned int GradeToExecute = 137;
  static const char *AsciiTrees;

  const std::string target_;
};
