// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#include "./PhoneBook.hpp"

int PhoneBook::oldestIndex_ = 0;

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

void PhoneBook::displaySavedContacts_(void) const {
  int n = 10;

  std::cout << "Saved contacts: \n";
  for (int i = 0; i < MAX_PHONEBOOK_STORAGE; i++) {
    this->contacts_[i].display(n, i);
  }
}

bool PhoneBook::add_(void) {
  Contact contact = Contact::fromStdin();

  this->contacts_[PhoneBook::oldestIndex_++] = contact;
  if (PhoneBook::oldestIndex_ > MAX_PHONEBOOK_STORAGE - 1) {
    PhoneBook::oldestIndex_ = 0;
  }
  return true;
}

bool PhoneBook::search_(void) const {
  int contactIndex = -1;

  displaySavedContacts_();
  do {
    std::cout
        << "Enter the index of the contact you wish to see details (0-7): ";
    std::cin >> contactIndex;
  } while (!(contactIndex >= 0 && contactIndex <= 7));

  if (!this->contacts_[contactIndex].exists()) {
    std::cout << "Index does not match any contact\n";
    return false;
  }
  std::cout << this->contacts_[contactIndex].toString();
  return true;
}

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
    std::getline(std::cin >> std::ws, command);
    if (!command.compare("ADD")) {
      add_();
    } else if (!command.compare("SEARCH")) {
      search_();
    } else if (!command.compare("EXIT")) {
      done = exit_();
    }
  }
}
