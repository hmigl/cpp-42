// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#ifndef HUMAN_B_
#define HUMAN_B_

#include <iostream>
#include <string>

#include "./Weapon.hpp"

class HumanB {
 private:
  std::string name_;
  Weapon *weapon_;

 public:
  explicit HumanB(const std::string &name);
  ~HumanB();

  void attack() const;
};

#endif  // HUMAN_B_
