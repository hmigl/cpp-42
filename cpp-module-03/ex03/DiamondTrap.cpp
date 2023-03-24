/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:56:26 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/24 13:34:03 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./DiamondTrap.hpp"

#include <iostream>
#include <string>

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap() {
  std::cout << "DiamondTrap default constructor called\n";
  name_ = "";
  ClapTrap::name_ = name_ + "_clap_name";
  hitPoints_ = FragTrap::hitPoints_;
  energyPoints_ = ScavTrap::energyPoints_;
  attackDamage_ = FragTrap::attackDamage_;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other) {
  std::cout << "DiamondTrap copy constructor called\n";
  *this = other;
}

DiamondTrap::DiamondTrap(const std::string &name)
    : ScavTrap(name), FragTrap(name) {
  name_ = name;
  hitPoints_ = FragTrap::hitPoints_;
  energyPoints_ = ScavTrap::energyPoints_;
  attackDamage_ = FragTrap::attackDamage_;
  ClapTrap::name_ = name_ + "_clap_name";
  std::cout << "DiamondTrap string constructor called\n";
}

void DiamondTrap::attack(const std::string &target) {
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() const {
  std::cout << "I'm " << name_ << " and my ClapTrap's name is "
            << ClapTrap::name_ << '\n';
}

DiamondTrap::~DiamondTrap() { std::cout << "DiamondTrap destructor called\n"; }

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
  if (this != &other) {
    ClapTrap::operator=(other);
    name_ = other.name_;
  }
  return *this;
}
