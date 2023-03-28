/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:51:39 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/28 16:37:29 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>

#include "./Cat.hpp"
#include "./Dog.hpp"
#include "./WrongCat.hpp"

const int NbAnimals = 4;

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
  std::cout << "------------------------------------\n";

  std::cout << "DELETING ARRAY OF ANIMAL OBJECTS:\n\n";
  for (int i = 0; i < NbAnimals; ++i) {
    delete animals[i];
    std::cout << std::endl;
  }
  return 0;
}
