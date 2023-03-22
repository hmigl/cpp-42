// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#include "./Zombie.hpp"

void randomChump(std::string name) {
  Zombie z(name);
  z.announce();
}
