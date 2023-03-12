// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#ifndef CONTACT_HPP_
#define CONTACT_HPP_

#include <string>

struct Contact {
  const std::string firstName;
  const std::string lastName;
  const std::string nickname;
  const std::string phoneNo;
  const std::string darkestSecret;

  Contact();
  ~Contact();
};

#endif // CONTACT_HPP_
