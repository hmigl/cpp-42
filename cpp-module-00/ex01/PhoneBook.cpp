// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#include "./PhoneBook.hpp"

int PhoneBook::oldestIndex_ = 0;

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

bool PhoneBook::add_(void) {
  Contact contact = Contact::fromStdin();

  this->contacts_[PhoneBook::oldestIndex_++] = contact;
  if (PhoneBook::oldestIndex_ > MAX_PHONEBOOK_STORAGE - 1) {
    PhoneBook::oldestIndex_ = 0;
  }
  return true;
}

bool PhoneBook::search_(void) const { return true; }

bool PhoneBook::exit_(void) const {
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
      add_();
    } else if (!command.compare("SEARCH")) {
      search_();
    } else if (!command.compare("EXIT")) {
      done = exit_();
    }
  }
}
