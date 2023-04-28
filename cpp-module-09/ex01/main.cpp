/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:08:09 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/28 10:18:14 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "./RPN.hpp"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "usage: \'./RPN <expression>\'\n";
    return 1;
  }
  try {
    int res = RPN::eval_RPN(argv[1]);
    std::cout << res << '\n';
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  return 0;
}
