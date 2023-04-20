/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 08:44:14 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/20 09:09:22 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::const_iterator easyfind(const T &containerOfInts, int val) {
  typename T::const_iterator it =
      std::find(containerOfInts.begin(), containerOfInts.end(), val);

  if (it != containerOfInts.end()) {
    return it;
  }
  throw std::invalid_argument("value was not found");
}
