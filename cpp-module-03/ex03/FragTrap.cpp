/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:29:43 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/24 12:38:37 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FragTrap.hpp"

#include <iostream>
#include <string>

FragTrap::FragTrap() : ClapTrap() {
  hitPoints_ = 100;
  energyPoints_ = 100;
  attackDamage_ = 30;
  std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
  std::cout << "FragTrap copy constructor called\n";
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
  hitPoints_ = 100;
  energyPoints_ = 100;
  attackDamage_ = 30;
  std::cout << "FragTrap string constructor called\n";
}

void FragTrap::highFiveGuys() const {
  if (!hitPoints_) {
    std::cout << name_ << ": No high five today!\n";
    return;
  }
  std::cout << name_ << ": positive high fives?!\n";
}

FragTrap::~FragTrap() { std::cout << "FragTrap destructor called\n"; }
