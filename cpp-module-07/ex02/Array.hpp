/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:24:50 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/14 17:00:07 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <stdexcept>

template <typename T>
class Array {
 public:
  Array() : arr_(NULL), size_(0) {}

  explicit Array(unsigned int n) : arr_(new T[n]), size_(n) {}

  Array(const Array &other) : arr_(new T[other.size_]), size_(other.size_) {
    for (unsigned int i = 0; i < other.size_; ++i) {
      arr_[i] = other.arr_[i];
    }
  }

  Array &operator=(const Array &other) {
    if (this != &other) {
      T *arr = new T[other.size_];
      for (unsigned int i = 0; i < other.size_; ++i) {
        arr[i] = other.arr_[i];
      }
      delete[] arr_;
      arr_ = arr;
      size_ = other.size_;
    }
    return *this;
  }

  const T &operator[](unsigned int index) const {
    if (index >= size_) {
      throw std::out_of_range("Index out of range");
    }
    return arr_[index];
  }

  T &operator[](unsigned int index) {
    return const_cast<T &>(static_cast<const Array<T> &>(*this)[index]);
  }

  ~Array() {
    if (arr_) {
      delete[] arr_;
    }
  }

  unsigned int size() const { return size_; }

 private:
  T *arr_;
  unsigned int size_;
};
