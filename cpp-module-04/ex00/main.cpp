/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:51:39 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/27 18:53:54 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>

#include "./Cat.hpp"
#include "./Dog.hpp"
#include "./WrongCat.hpp"

int main(void) {
  {
    const Animal *animal = new Animal();

    assert(!animal->getType().compare("Undefined"));
    std::cout << animal->getType() << '\n';
    animal->makeSound();
    delete animal;
    std::cout << '\n';
  }
  {
    const Animal *dog = new Dog();

    assert(!dog->getType().compare("Dog"));
    std::cout << dog->getType() << '\n';
    dog->makeSound();
    delete dog;
    std::cout << '\n';
  }
  {
    const Animal *cat = new Cat();

    assert(!cat->getType().compare("Cat"));
    std::cout << cat->getType() << '\n';
    cat->makeSound();
    delete cat;
    std::cout << '\n';
  }
  {
    const WrongAnimal *wrongAnimal = new WrongAnimal();

    assert(!wrongAnimal->getType().compare("Undefined"));
    std::cout << wrongAnimal->getType() << '\n';
    wrongAnimal->makeSound();
    delete wrongAnimal;
    std::cout << '\n';
  }
  {
    const WrongAnimal *wrongCat = new WrongCat();

    assert(!wrongCat->getType().compare("Wrong Cat"));
    std::cout << wrongCat->getType() << '\n';  // early binding, no polymorphism
    wrongCat->makeSound();
    delete wrongCat;
  }
  return 0;
}
