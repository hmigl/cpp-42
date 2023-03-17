// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#include <iostream>
#include <string>

#include "./Weapon.hpp"

class HumanA {
 private:
  std::string name_;
  const Weapon &weapon_;

 public:
  HumanA(const std::string &name, const Weapon &weapon);
  ~HumanA();

  void attack() const;
};
