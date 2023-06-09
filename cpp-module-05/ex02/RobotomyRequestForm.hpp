/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:20:54 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/02 20:11:02 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <ctime>
#include <string>

#include "./AForm.hpp"

class RobotomyRequestForm : public AForm {
 public:
  explicit RobotomyRequestForm(const std::string &);
  RobotomyRequestForm(const RobotomyRequestForm &);
  ~RobotomyRequestForm();

  RobotomyRequestForm &operator=(const RobotomyRequestForm &);

  void execute(const Bureaucrat &) const;

 private:
  RobotomyRequestForm();

  static const unsigned int GradeToSign = 72;
  static const unsigned int GradeToExecute = 45;

  const std::string target_;
};
