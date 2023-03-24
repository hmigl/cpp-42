/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 09:23:26 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/24 19:09:58 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap()
    : name_(""),
      hitPoints_(HitPoints),
      energyPoints_(EnergyPoints),
      attackDamage_(AttackDamage) {
  std::cout << "Default constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &other) {
  std::cout << "Copy constructor called\n";
  *this = other;
}

ClapTrap::ClapTrap(const std::string &name)
    : name_(name),
      hitPoints_(HitPoints),
      energyPoints_(EnergyPoints),
      attackDamage_(AttackDamage) {
  std::cout << "String constructor called\n";
}

ClapTrap::~ClapTrap() { std::cout << "Destructor called\n"; }

void ClapTrap::attack(const std::string &target) {
  if (!hitPoints_ || !energyPoints_) {
    std::cout << "Cannot perform attack!\n";
    return;
  }
  --energyPoints_;
  std::cout << name_ << " attacks " << target << ", causing " << attackDamage_
            << " points of demage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (!hitPoints_ || !amount) {
    std::cout << "All demage has already been taken!\n";
    return;
  }
  if (amount > hitPoints_) {
    std::cout << name_ << " takes " << hitPoints_ << " points of demage!\n";
    hitPoints_ = 0;
    return;
  }
  hitPoints_ -= amount;
  std::cout << name_ << " takes " << amount << " points of demage!\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (!energyPoints_ || !amount) {
    std::cout << "No repair will be performed!\n";
    return;
  }
  std::cout << name_ << " repairs itself, " << amount
            << " hit points were restored!\n";
  --energyPoints_;
  hitPoints_ += amount;
}

const std::string &ClapTrap::getName() const { return name_; }

unsigned int ClapTrap::getHitPoints() const { return hitPoints_; }

unsigned int ClapTrap::getEnergyPoints() const { return energyPoints_; }

unsigned int ClapTrap::getAttackDamage() const { return attackDamage_; }

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  if (this != &other) {
    name_ = other.name_;
    hitPoints_ = other.hitPoints_;
    energyPoints_ = other.energyPoints_;
    attackDamage_ = other.attackDamage_;
  }
  return *this;
}
