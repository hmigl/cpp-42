// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#include "./Zombie.hpp"

Zombie::Zombie(const std::string &name) : name(name) {}

Zombie::~Zombie() {
  std::cout << name << ": No Moar BraiiiiiiinnnzzzZ... :(\n";
}

void Zombie::announce() const {
  std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
