/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:34:32 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/27 18:44:57 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP_
#define WRONG_ANIMAL_HPP_

#include <iostream>
#include <string>

class WrongAnimal {
 public:
  WrongAnimal();
  WrongAnimal(const WrongAnimal &);
  explicit WrongAnimal(const std::string &);
  virtual ~WrongAnimal();

  void makeSound() const;
  const std::string &getType() const;

  WrongAnimal &operator=(const WrongAnimal &);

 protected:
  std::string type_;
};

#endif  // WRONG_ANIMAL_HPP_
