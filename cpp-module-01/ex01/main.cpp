// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#include "./Zombie.hpp"

Zombie *zombieHorde(int n, std::string name);

int main(void) {
  const int N = 10;
  Zombie *z = zombieHorde(N, "Foo");

  for (int i = 0; i < N; i++) {
    z[i].announce();
  }
  delete[] z;
  return 0;
}
