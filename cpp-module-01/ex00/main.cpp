// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#include "./Zombie.hpp"

Zombie *newZombie(std::string name);

int main(void) {
  Zombie z("Foo");                // stack allocation
  Zombie *zz = newZombie("Bar");  // heap allocation

  z.announce();
  zz->announce();
  delete zz;  // deallocate the memory
  return 0;
}
