/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:33:49 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/28 11:54:00 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./RPN.hpp"

std::stack<int> RPN::calculator_;

RPN::RPN() {}

RPN::RPN(const RPN &other) { *this = other; }

RPN &RPN::operator=(const RPN &other) {
  if (this != &other) {
    //
  }
  return *this;
}

RPN::~RPN() {}

int RPN::eval(const int &a, const char &o, const int &b) {
  if (o == '+') {
    return a + b;
  }
  if (o == '-') {
    return a - b;
  }
  if (o == '/') {
    if (b != 0) {
      return a / b;
    }
    throw std::logic_error("Cannot divide by 0");
  }
  return a * b;
}

bool RPN::is_operator(const char &c) {
  return c == '+' || c == '-' || c == '/' || c == '*';
}

int RPN::eval_RPN(const std::string &math_expr_rpn_form) {
  std::string rpn_expr = math_expr_rpn_form;

  if (rpn_expr.empty() ||
      rpn_expr.find_first_not_of("0123456789 +-/*") != std::string::npos) {
    throw std::invalid_argument("Must be a valid mathematical expression");
  }
  rpn_expr.erase(remove_if(rpn_expr.begin(), rpn_expr.end(), isspace),
                 rpn_expr.end());

  for (std::string::size_type i = 0; i < rpn_expr.size(); ++i) {
    if (!is_operator(rpn_expr.at(i))) {
      calculator_.push(rpn_expr.at(i) - '0');
      continue;
    }
    if (calculator_.size() < 2) {
      throw std::runtime_error("Cannot perform evaluation, review the input");
    }
    int b = calculator_.top();
    calculator_.pop();
    int a = calculator_.top();
    calculator_.pop();
    int res = eval(a, rpn_expr.at(i), b);
    calculator_.push(res);
  }
  return calculator_.top();
}
