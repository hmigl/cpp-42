/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:11:55 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/29 09:34:53 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMe.hpp"

int main(int argc, const char *argv[]) {
  if (argc < 2) {
    std::cerr << "usage: \'./PmergeMe <positive integer sequence>\'\n";
    return 1;
  }

  try {
    PmergeMe p(argv);
  } catch (const std::exception &e) {
  }
  return 0;
}
