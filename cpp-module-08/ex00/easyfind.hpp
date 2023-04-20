/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 08:44:14 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/20 08:44:15 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::const_iterator easyfind(const T &container, int val) {
  typename T::const_iterator it =
      std::find(container.begin(), container.end(), val);

  if (it != container.end()) {
    return it;
  }
  throw std::invalid_argument("value was not found");
}
