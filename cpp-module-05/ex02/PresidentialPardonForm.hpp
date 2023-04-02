/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:23:43 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/02 20:01:17 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "./AForm.hpp"

class PresidentialPardonForm : public AForm {
 public:
  explicit PresidentialPardonForm(const std::string &);
  PresidentialPardonForm(const PresidentialPardonForm &);
  ~PresidentialPardonForm();

  PresidentialPardonForm &operator=(const PresidentialPardonForm &);

  void execute(const Bureaucrat &) const;

 private:
  PresidentialPardonForm();

  static const unsigned int GradeToSign = 25;
  static const unsigned int GradeToExecute = 5;

  const std::string target_;
};
