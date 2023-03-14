// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#include "./Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

Contact::Contact(const std::string &firstName, const std::string &lastName,
                 const std::string &nickname, const std::string &phoneNo,
                 const std::string &darkestSecret)
    : firstName_(firstName), lastName_(lastName), nickname_(nickname),
      phoneNo_(phoneNo), darkestSecret_(darkestSecret) {}

const std::string &Contact::getFirstName() const { return firstName_; }
const std::string &Contact::getLastName() const { return lastName_; }
const std::string &Contact::getNickname() const { return nickname_; }
const std::string &Contact::getPhoneNo() const { return phoneNo_; }
const std::string &Contact::getDarkestSecret() const { return darkestSecret_; }

Contact Contact::fromStdin() {
  std::string firstName = "a", lastName = "b", nickname = "c", phoneNo = "d",
              darkestSecret = "e";

  return Contact(firstName, lastName, nickname, phoneNo, darkestSecret);
}

std::ostream &operator<<(std::ostream &os, const Contact &contact) {
  return (os << "Contact{ "
             << "firstName=" << contact.getFirstName() << ", lastName="
             << contact.getLastName() << ", nickname=" << contact.getNickname()
             << ", phoneNo=" << contact.getPhoneNo()
             << ", darkestSecret=" << contact.getDarkestSecret() << " }\n");
}

std::string Contact::toString(void) const {
  std::stringstream ss;
  ss << (*this);
  return ss.str();
}
