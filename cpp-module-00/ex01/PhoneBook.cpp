// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#include "./PhoneBook.hpp"

int PhoneBook::savedContacts_ = 0;

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

bool PhoneBook::add(void) { return true; }

bool PhoneBook::search(void) const { return true; }

bool PhoneBook::exit(void) const {
  std::cout << "Erasing all phonebook data...\n";
  return true;
}

void PhoneBook::run(void) {
  bool done = false;
  std::string command = "";

  while (!done) {
    std::cout << "Please enter one of the following commands: " << COMMANDS
              << "\n";
    std::getline(std::cin, command);
    if (!command.compare("ADD")) {
      add();
    } else if (!command.compare("SEARCH")) {
      search();
    } else if (!command.compare("EXIT")) {
      done = exit();
    }
  }
}
