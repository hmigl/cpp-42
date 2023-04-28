/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:10:57 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/28 10:18:55 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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

  static std::stack<int> calculator_;
};
