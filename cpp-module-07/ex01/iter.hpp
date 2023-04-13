/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 08:06:11 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/13 08:23:39 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <stdexcept>

template <typename T>
void iter(T *array, size_t length, void (*fn)(T &e)) {
  if (array == NULL) {
    throw std::invalid_argument("Null pointer passed as array argument");
  }
  if (length == 0) {
    throw std::invalid_argument("Zero length passed as length argument");
  }

  for (size_t i = 0; i < length; ++i) {
    fn(array[i]);
  }
}

template <typename T>
void iter(T *array, size_t length, void (*fn)(const T &e)) {
  if (array == NULL) {
    throw std::invalid_argument("Null pointer passed as array argument");
  }
  if (length == 0) {
    throw std::invalid_argument("Zero length passed as length argument");
  }

  for (size_t i = 0; i < length; ++i) {
    fn(array[i]);
  }
}
