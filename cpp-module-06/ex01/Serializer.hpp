/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:56:12 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/11 10:56:13 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>

#include "./Data.hpp"

class Serializer {
 public:
  ~Serializer();

  static uintptr_t serialize(Data *);
  static Data *deserialize(uintptr_t);

 private:
  Serializer();
  Serializer(const Serializer &);
  Serializer &operator=(const Serializer &);
};
