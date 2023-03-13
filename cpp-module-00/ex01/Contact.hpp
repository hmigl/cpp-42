// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#ifndef CONTACT_HPP_
#define CONTACT_HPP_

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
  Contact(const std::string &firstName_, const std::string &lastName_,
          const std::string &nickname_, const std::string &phoneNo_,
          const std::string &darkestSecret_);

  static Contact fromStdin(void);
};

#endif // CONTACT_HPP_
