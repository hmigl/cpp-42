// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#include "./HumanB.hpp"

HumanB::HumanB(const std::string &name) : name_(name) {}

HumanB::~HumanB() {}

void HumanB::attack() const {
  if (weapon_) {
    std::cout << name_ << " attacks with their " << weapon_->getType() << '\n';
  } else {
    std::cout << name_ << " has no weapon\n";
  }
}

void HumanB::setWeapon(Weapon &weapon) { weapon_ = &weapon; }
