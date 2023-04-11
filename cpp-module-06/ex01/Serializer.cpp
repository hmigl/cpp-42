/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:53:21 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/11 11:05:10 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &other) { *this = other; }

Serializer &Serializer::operator=(const Serializer &other) {
  (void)other;
  return *this;
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data *data) {
  return reinterpret_cast<uintptr_t>(data);
}

Data *Serializer::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data *>(raw);
}
