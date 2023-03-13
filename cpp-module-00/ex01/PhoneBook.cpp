// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#include "./PhoneBook.hpp"

int PhoneBook::savedContacts_ = 0;

PhoneBook::PhoneBook() {}
PhoneBook::~PhoneBook() {}

bool PhoneBook::add(void) { return true; }

bool PhoneBook::search(void) const { return true; }

int PhoneBook::exit(void) const { return true; }

void PhoneBook::run(void) {
  for (;;) {
  }
}
