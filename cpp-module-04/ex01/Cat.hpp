/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:36:55 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/27 17:57:09 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP_
#define CAT_HPP_

#include "./Animal.hpp"

class Cat : public Animal {
 public:
  Cat();
  Cat(const Cat &);
  ~Cat();

  void makeSound() const;

  Cat &operator=(const Cat &);
};

#endif  // CAT_HPP_
