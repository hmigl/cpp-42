// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#include "./HumanA.hpp"

HumanA::HumanA(const std::string &name, const Weapon &weapon)
    : name_(name), weapon_(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack() const {
  std::cout << name_ << "attacks with their " << weapon_.getType() << '\n';
}
