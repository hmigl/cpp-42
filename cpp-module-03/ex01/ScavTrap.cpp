/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:02:39 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/24 07:14:00 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScavTrap.hpp"

#include <iostream>
#include <string>

#include "./ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
  hitPoints_ = 100;
  energyPoints_ = 50;
  attackDamage_ = 20;
  std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
  std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
  hitPoints_ = 100;
  energyPoints_ = 50;
  attackDamage_ = 20;
  std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap destructor called\n"; }

void ScavTrap::attack(const std::string &target) {
  if (!hitPoints_ || !energyPoints_) {
    std::cout << "(ScavTrap) Cannot perform attack!\n";
    return;
  }
  --energyPoints_;
  std::cout << "(ScavTrap) " << name_ << " attacks " << target << ", causing "
            << attackDamage_ << " points of demage!\n";
}

void ScavTrap::guardGate() {
  std::cout << "(ScavTrap) " << name_ << " is now in Gate keeper mode!\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  if (this != &other) {
    ClapTrap::operator=(other);
  }
  return *this;
}
