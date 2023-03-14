// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#ifndef PHONE_BOOK_HPP_
#define PHONE_BOOK_HPP_

#include "./Contact.hpp"
#include <iostream>
#include <string>

#define MAX_PHONEBOOK_STORAGE 8
#define COMMANDS "[ ADD, SEARCH, EXIT ]"

class PhoneBook {
 private:
  Contact contacts_[MAX_PHONEBOOK_STORAGE];
  static int oldestIndex_;

  bool add(void);
  bool search(void) const;
  bool exit(void) const;

 public:
  PhoneBook();

  ~PhoneBook();

  void run(void);
};

#endif // PHONE_BOOK_HPP_
