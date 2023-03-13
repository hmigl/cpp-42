// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#include "./PhoneBook.hpp"

int PhoneBook::savedContacts_ = 0;

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

bool PhoneBook::isCommand_(const std::string &command) const {
  const std::string commands[] = {"ADD", "SEARCH", "EXIT"};

  for (int i = 0; i < static_cast<int>(commands->size()); i++) {
    if (!command.compare(commands[i])) {
      return true;
    }
  }
  return false;
}

bool PhoneBook::add(void) { return true; }

bool PhoneBook::search(void) const { return true; }

int PhoneBook::exit(void) const { return true; }

void PhoneBook::run(void) {
  std::string command = "";

  for (;;) {
    std::cout << "Please enter one of following commands: " << COMMANDS << "\n";
    std::getline(std::cin, command);
    if (isCommand_(command)) {
      std::cout << "uepa!\n";
    }
  }
}
