/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:29:43 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/24 10:53:20 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FlagTrap.hpp"

#include <iostream>
#include <string>

FlagTrap::FlagTrap() : ClapTrap() {
  hitPoints_ = 100;
  energyPoints_ = 100;
  attackDamage_ = 30;
  std::cout << "FlagTrap default constructor called\n";
}

FlagTrap::FlagTrap(const FlagTrap &other) : ClapTrap(other) {
  std::cout << "FlagTrap copy constructor called\n";
}

FlagTrap::FlagTrap(const std::string &name) : ClapTrap(name) {
  hitPoints_ = 100;
  energyPoints_ = 100;
  attackDamage_ = 30;
  std::cout << "FlagTrap string constructor called\n";
}

void FlagTrap::highFiveGuys() const {
  if (!hitPoints_) {
    std::cout << name_ << ": No high five today!\n";
    return;
  }
  std::cout << name_ << ": positive high fives?!\n";
}

FlagTrap::~FlagTrap() { std::cout << "FlagTrap destructor called\n"; }
