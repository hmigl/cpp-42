// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#include "./Weapon.hpp"

Weapon::Weapon(const std::string &type) : type_(type) {}

Weapon::~Weapon() {}

const std::string &Weapon::getType() const { return type_; }

void Weapon::setType(const std::string &type) { type_ = type; }
