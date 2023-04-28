/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:33:49 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/28 10:33:57 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) { *this = other; }

RPN &RPN::operator=(const RPN &other) {
  if (this != &other) {
    //
  }
  return *this;
}

RPN::~RPN() {}

int RPN::eval_RPN(const std::string &math_expr_rpn_form) {
  if (math_expr_rpn_form.empty() ||
      math_expr_rpn_form.find_first_not_of("0123456789 +-/*") !=
          std::string::npos) {
    throw std::invalid_argument("Must be a valid mathematical expression");
  }
  return 0;
}
