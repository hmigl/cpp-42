/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:10:57 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/28 12:46:00 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <cstdlib>
#include <stack>
#include <stdexcept>
#include <string>

class RPN {
 public:
  RPN(const RPN &);
  RPN &operator=(const RPN &);
  ~RPN();

  static int eval_RPN(const std::string &);

 private:
  RPN();

  static std::stack<int> Expr;

  static bool is_operator(const char &);
  static int eval(const int &, const char &, const int &);
  static void eval_expr_and_push(const char &);
};
