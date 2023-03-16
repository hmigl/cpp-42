// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#include <iostream>
#include <string>

class Zombie {
 private:
  std::string name;

 public:
  explicit Zombie(const std::string &name);
  Zombie();
  ~Zombie();

  void announce(void) const;
};
