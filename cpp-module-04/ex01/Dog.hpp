/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:36:55 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/28 16:52:53 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP_
#define DOG_HPP_

#include "./Animal.hpp"
#include "./Brain.hpp"

class Dog : public Animal {
 public:
  Dog();
  Dog(const Dog &);
  ~Dog();

  const Brain *getBrain() const;
  void makeSound() const;

  Dog &operator=(const Dog &);

 private:
  Brain *brain_;
};

#endif  // DOG_HPP_
