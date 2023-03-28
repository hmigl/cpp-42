/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:51:39 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/28 17:34:59 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>

#include "./Cat.hpp"
#include "./Dog.hpp"
#include "./WrongCat.hpp"

const int NbAnimals = 4;

static void deepCopyTest() {
  std::cout << "____________________________________\n";
  std::cout << "DEEP COPY CHECK:\n\n";
  {
    Dog *dog = new Dog();
    Dog *dcDog = new Dog(*dog);

    std::cout << "dog: " << dog->getBrain() << std::endl;
    std::cout << "deep copy dog: " << dcDog->getBrain() << std::endl;
    delete dog;
    delete dcDog;
  }
  std::cout << "\n____________________________________\n";
  {
    Cat *cat = new Cat();
    Cat *dcCat = new Cat(*cat);

    std::cout << "cat: " << cat->getBrain() << std::endl;
    std::cout << "deep copy cat: " << dcCat->getBrain() << std::endl;
    delete cat;
    delete dcCat;
  }
  std::cout << "\n____________________________________\n";
  {
    Dog *dog = new Dog();
    {
      Dog *dcDog = new Dog(*dog);
      std::cout << "deep copy dog: " << dcDog->getBrain() << std::endl;
      delete dcDog;
    }
    std::cout << "dog: " << dog->getBrain()
              << std::endl;  // if it was a shallow copy, undefined behavior
                             // would've happen, since 'dcDog' is gone
  }
}

int main(void) {
  const Animal *animals[NbAnimals];

  std::cout << "CREATING ARRAY OF ANIMAL OBJECTS:\n\n";
  for (int i = 0; i < NbAnimals; ++i) {
    if (i < NbAnimals / 2) {
      animals[i] = new Dog();
    } else {
      animals[i] = new Cat();
    }
    animals[i]->makeSound();
    std::cout << std::endl;
  }
  std::cout << "____________________________________\n";

  std::cout << "DELETING ARRAY OF ANIMAL OBJECTS:\n\n";
  for (int i = 0; i < NbAnimals; ++i) {
    delete animals[i];
    std::cout << std::endl;
  }
  deepCopyTest();
  return 0;
}
