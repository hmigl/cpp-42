/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:10:57 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/03 15:43:25 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "./AForm.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./ShrubberyCreationForm.hpp"

class Intern {
 public:
  Intern();
  Intern(const Intern &);
  ~Intern();

  Intern &operator=(const Intern &);

  AForm *makeForm(const std::string &formName, const std::string &target) const;

 private:
  AForm *makeShrubberyCreationFormForm(const std::string &) const;
  AForm *makeRobotomyRequestFormForm(const std::string &) const;
  AForm *makePresidentialPardonForm(const std::string &) const;
};
