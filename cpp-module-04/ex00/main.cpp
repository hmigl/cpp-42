/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:51:39 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/27 18:00:01 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>

#include "./Cat.hpp"
#include "./Dog.hpp"

int main(void) {
  {
    const Animal *animal = new Animal();

    assert(!animal->getType().compare("Undefined"));
    std::cout << animal->getType() << '\n';
    delete animal;
    std::cout << '\n';
  }
  {
    const Animal *dog = new Dog();

    assert(!dog->getType().compare("Dog"));
    std::cout << dog->getType() << '\n';
    delete dog;
    std::cout << '\n';
  }
  {
    const Animal *cat = new Cat();

    assert(!cat->getType().compare("Cat"));
    std::cout << cat->getType() << '\n';
    delete cat;
  }
  return 0;
}
