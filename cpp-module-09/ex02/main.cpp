/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:11:55 by hmigl             #+#    #+#             */
/*   Updated: 2023/05/01 11:35:21 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMe.hpp"

int main(int argc, const char *argv[]) {
  if (argc < 2) {
    std::cerr << "usage: \'./PmergeMe <positive integer sequence>\'\n";
    return 1;
  }

  try {
    PmergeMe p = PmergeMe::from_sequence(argv + 1);
    p.print_before();
    p.sort();
    p.print_after();
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  return 0;
}
