/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:22:45 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/29 10:22:13 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <stdexcept>

class PmergeMe {
 public:
  PmergeMe(const PmergeMe &);
  PmergeMe &operator=(const PmergeMe &);
  ~PmergeMe();

  static PmergeMe from_sequence(const char **);

 private:
  PmergeMe();
};
