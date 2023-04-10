/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:12:05 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/10 14:32:30 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "./ScalarConverter.hpp"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "usage: \'./ScalarConverter <value>\'\n";
    return 1;
  }

  try {
    ScalarConverter::convert(argv[1]);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
