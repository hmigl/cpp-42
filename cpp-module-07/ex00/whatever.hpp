/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 07:33:49 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/13 07:37:31 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void swap(T &lhs, T &rhs) {
  T aux = lhs;
  lhs = rhs;
  rhs = aux;
}

template <typename T>
T min(T lhs, T rhs) {
  return lhs < rhs ? lhs : rhs;
}
