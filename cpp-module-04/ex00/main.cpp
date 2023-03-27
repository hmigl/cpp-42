/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:51:39 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/27 17:51:40 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>

#include "./Dog.hpp"

int main(void) {
  {
    const Animal *dog = new Dog();

    assert(!dog->getType().compare("Dog"));
    std::cout << dog->getType() << '\n';
    delete dog;
  }
  {
    const Animal *animal = new Animal();

    assert(!animal->getType().compare("Undefined"));
    std::cout << animal->getType() << '\n';
    delete animal;
  }
  return 0;
}
