// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#include "./Zombie.hpp"

Zombie *zombieHorde(int n, std::string name) {
  Zombie *horde = new Zombie[n];

  for (int i = 0; i < n; i++) {
    new (&(horde[i])) Zombie(name);
  }
  return horde;
}
