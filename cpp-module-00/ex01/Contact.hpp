// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#ifndef CONTACT_HPP_
#define CONTACT_HPP_

#include <iomanip>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

class Contact {
 private:
  std::string firstName_;
  std::string lastName_;
  std::string nickname_;
  std::string phoneNo_;
  std::string darkestSecret_;

  std::string truncateField_(const std::string &field) const;

 public:
  Contact();
  ~Contact();

  Contact(const std::string &firstName, const std::string &lastName,
          const std::string &nickname, const std::string &phoneNo,
          const std::string &darkestSecret);

  static Contact fromStdin(void);

  void display(int n, int i) const;
  bool exists(void) const;

  const std::string &getFirstName() const;
  const std::string &getLastName() const;
  const std::string &getNickname() const;
  const std::string &getPhoneNo() const;
  const std::string &getDarkestSecret() const;

  std::string toString(void) const;
};

#endif // CONTACT_HPP_
