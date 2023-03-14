// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#ifndef CONTACT_HPP_
#define CONTACT_HPP_

#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

class Contact {
 private:
  const std::string firstName_;
  const std::string lastName_;
  const std::string nickname_;
  const std::string phoneNo_;
  const std::string darkestSecret_;

 public:
  Contact();
  ~Contact();

  Contact(const std::string &firstName, const std::string &lastName,
          const std::string &nickname, const std::string &phoneNo,
          const std::string &darkestSecret);

  static Contact fromStdin(void);
  const std::string &getFirstName() const;
  const std::string &getLastName() const;
  const std::string &getNickname() const;
  const std::string &getPhoneNo() const;
  const std::string &getDarkestSecret() const;
  std::string toString(void) const;
};

#endif // CONTACT_HPP_
