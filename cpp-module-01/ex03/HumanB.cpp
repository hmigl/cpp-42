// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#include "./HumanB.hpp"

HumanB::HumanB(const std::string &name) : name_(name) {}

HumanB::~HumanB() {}

void HumanB::attack() const {
  std::cout << name_ << "attacks with their " << weapon_->getType() << '\n';
}
