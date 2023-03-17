// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#ifndef WEAPON_
#define WEAPON_

#include <string>

class Weapon {
 private:
  std::string type_;

 public:
  explicit Weapon(const std::string &type);
  ~Weapon();

  const std::string &getType(void) const;
  void setType(const std::string &type);
};

#endif  // WEAPON_
