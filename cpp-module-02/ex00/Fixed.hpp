/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:57:34 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/20 15:40:54 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP_
#define FIXED_HPP_

class Fixed {
 public:
  Fixed();
  Fixed(const Fixed &);
  Fixed &operator=(const Fixed &);
  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(const int raw);

 private:
  int rawBits_;
  static const int FractionalBits = 8;
};

#endif  // FIXED_HPP_
