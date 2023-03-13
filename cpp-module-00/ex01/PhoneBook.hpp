// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#ifndef PHONE_BOOK_HPP_
#define PHONE_BOOK_HPP_

#include "./Contact.hpp"

#define MAX_CONTACTS_STORAGE 8

class PhoneBook {
 private:
  Contact contacts_[MAX_CONTACTS_STORAGE];
  static int savedContacts_;

 public:
  PhoneBook();
  ~PhoneBook();

  void run(void);

  bool add(void);
  bool search(void);
  bool exit(void);
};

#endif // PHONE_BOOK_HPP_
