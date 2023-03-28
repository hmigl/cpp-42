/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:36:55 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/27 18:46:51 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP_
#define WRONG_CAT_HPP_

#include "./WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
 public:
  WrongCat();
  WrongCat(const WrongCat &);
  ~WrongCat();

  void makeSound() const;

  WrongCat &operator=(const WrongCat &);
};

#endif  // WRONG_CAT_HPP_
