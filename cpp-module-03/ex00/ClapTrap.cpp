/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 09:23:26 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/23 09:23:27 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

ClapTrap::ClapTrap()
    : name_(""), hitPoints_(10), energyPoints_(10), attackDamage_(0) {}

ClapTrap::ClapTrap(const ClapTrap &other) { *this = other; }

ClapTrap::ClapTrap(const std::string &name)
    : name_(name), hitPoints_(10), energyPoints_(10), attackDamage_(0) {}

ClapTrap::~ClapTrap() {}

void ClapTrap::attack(const std::string &target) {}

void ClapTrap::takeDamage(unsigned int amount) {}

void ClapTrap::beRepaired(unsigned int amount) {}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  if (this != &other) {
    name_ = other.name_;
    hitPoints_ = other.hitPoints_;
    energyPoints_ = other.energyPoints_;
    attackDamage_ = other.attackDamage_;
  }
  return *this;
}
