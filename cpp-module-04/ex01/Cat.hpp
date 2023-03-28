/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:36:55 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/28 12:02:57 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP_
#define CAT_HPP_

#include "./Animal.hpp"
#include "./Brain.hpp"

class Cat : public Animal {
 public:
  Cat();
  Cat(const Cat &);
  ~Cat();

  void makeSound() const;

  Cat &operator=(const Cat &);

 private:
  Brain *brain_;
};

#endif  // CAT_HPP_
