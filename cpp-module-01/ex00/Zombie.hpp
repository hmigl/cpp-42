// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#ifndef ZOMBIE_HPP_
#define ZOMBIE_HPP_

#include <iostream>
#include <string>

class Zombie {
 private:
  std::string name;

 public:
  explicit Zombie(const std::string &name);
  ~Zombie();

  void announce(void) const;
};

#endif  // ZOMBIE_HPP_
