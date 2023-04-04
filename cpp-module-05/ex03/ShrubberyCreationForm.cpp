/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:22:16 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/02 20:02:44 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ShrubberyCreationForm.hpp"

const char *ShrubberyCreationForm::AsciiTrees =
    "               ,@@@@@@@,\n"
    "      ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
    "   ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
    "  ,%&%&&%&&%,@@@\\@@@/@@@88\\88888/88\n"
    "  %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888\n"
    "  %&&%/ %&%%&&@@\\V /@@' `88\\8 `/88\n"
    "  `&%\\ ` /%&'    |.|        \\ '|8\n"
    "      |o|        | |         | | \n"
    "      |.|        | |         | |\n "
    "gs \\/ ._\\//_/__/  ,\\_//__\\/. \\_//__/_\n";

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", GradeToSign, GradeToExecute),
      target_("target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", GradeToSign, GradeToExecute),
      target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target_(other.target_) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm &other) {
  AForm::operator=(other);
  return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &b) const {
  AForm::execute(b);
  const std::string filename = target_ + "_shrubbery";
  std::ofstream ofs(filename.c_str(), std::ios::out | std::ios::app);

  if (!ofs.is_open()) {
    throw std::runtime_error(filename + " is not open");
  }
  ofs << AsciiTrees;
  ofs.close();
}
