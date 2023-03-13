// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#ifndef PHONE_BOOK_HPP_
#define PHONE_BOOK_HPP_

#include "./Contact.hpp"
#include <iostream>
#include <string>

#define MAX_CONTACTS_STORAGE 8
#define COMMANDS "[ ADD, SEARCH, EXIT ]"

class PhoneBook {
 private:
  Contact contacts_[MAX_CONTACTS_STORAGE];
  static int savedContacts_;

  bool isCommand_(const std::string &command) const;

 public:
  PhoneBook();
  ~PhoneBook();

  void run(void);

  bool add(void);
  bool search(void) const;
  int exit(void) const;
};

#endif // PHONE_BOOK_HPP_
