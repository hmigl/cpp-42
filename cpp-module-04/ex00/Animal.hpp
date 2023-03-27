/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:34:32 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/27 16:35:27 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP_
#define ANIMAL_HPP_

#include <iostream>
#include <string>

class Animal {
 public:
  Animal();
  Animal(const Animal &);
  ~Animal();

  virtual void makeSound() const;

  Animal &operator=(const Animal &);

 protected:
  std::string type_;
};

#endif  // ANIMAL_HPP_
