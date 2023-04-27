/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:09:22 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/27 11:51:48 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "./BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "usage: \'./btc <amount_history_file>\'\n";
    return 1;
  }

  try {
    BitcoinExchange be;
    be.eval_from_amount_history_file(argv[1]);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
