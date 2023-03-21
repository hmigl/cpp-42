/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:57:34 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/21 20:13:04 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP_
#define FIXED_HPP_

#include <string>

class Fixed {
 public:
  Fixed();
  Fixed(const Fixed &);
  explicit Fixed(const int);
  explicit Fixed(const float);
  ~Fixed();

  static Fixed &min(Fixed &, Fixed &);
  static const Fixed &min(const Fixed &, const Fixed &);
  static Fixed &max(Fixed &, Fixed &);
  static const Fixed &max(const Fixed &, const Fixed &);

  float toFloat(void) const;
  int toInt(void) const;

  int getRawBits(void) const;
  void setRawBits(const int);

  Fixed &operator=(const Fixed &);
  bool operator>(const Fixed &) const;
  bool operator<(const Fixed &) const;
  bool operator>=(const Fixed &) const;
  bool operator<=(const Fixed &) const;
  bool operator==(const Fixed &) const;
  bool operator!=(const Fixed &) const;

  Fixed operator+(const Fixed &) const;
  Fixed operator-(const Fixed &) const;
  Fixed operator*(const Fixed &) const;
  Fixed operator/(const Fixed &) const;

  Fixed &operator+=(const Fixed &);
  Fixed &operator-=(const Fixed &);
  Fixed &operator*=(const Fixed &);
  Fixed &operator/=(const Fixed &);

  Fixed &operator++();
  Fixed operator++(int);
  Fixed &operator--();
  Fixed operator--(int);

 private:
  int rawBits_;
  static const int FractionalBits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);

#endif  // FIXED_HPP_
