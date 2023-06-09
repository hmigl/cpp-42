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

std::string Contact::truncateField_(const std::string &field) const {
  if (field.length() <= 10) {
    return field;
  }
  std::string truncated = field.substr(0, 10);
  truncated[9] = '.';
  return truncated;
}

void Contact::display(int n, int i) const {
  if (firstName_.empty())
    return;
  std::cout << std::setw(n) << std::right << i << "|";
  std::cout << std::setw(n) << std::right << truncateField_(firstName_) << "|";
  std::cout << std::setw(n) << std::right << truncateField_(lastName_) << "|";
  std::cout << std::setw(n) << std::right << truncateField_(nickname_) << "|\n";
}

Contact Contact::fromStdin() {
  std::string firstName, lastName, nickname, phoneNo, darkestSecret, buff = "";
  const std::string properties[] = {"First name", "Last name", "Nickname",
                                    "Phone number", "Darkest secret"};

  for (int i = 0;
       i < static_cast<int>(sizeof(properties) / sizeof(properties[0])); i++) {
    do {
      std::cout << "Insert the contact's " << properties[i] << ": ";
      std::getline(std::cin, buff);
    } while (buff.empty());

    switch (i) {
      case 0: firstName = buff; break;
      case 1: lastName = buff; break;
      case 2: nickname = buff; break;
      case 3: phoneNo = buff; break;
      case 4: darkestSecret = buff; break;
    }
  }
  return Contact(firstName, lastName, nickname, phoneNo, darkestSecret);
}

bool Contact::exists(void) const { return !this->firstName_.empty(); }

std::ostream &operator<<(std::ostream &os, const Contact &contact) {
  return (os << "First name: " << contact.getFirstName() << '\n'
             << "Last name: " << contact.getLastName() << '\n'
             << "Nickname: " << contact.getNickname() << '\n'
             << "Phone number: " << contact.getPhoneNo() << '\n'
             << "Darkest secret: " << contact.getDarkestSecret() << "\n");
}

std::string Contact::toString(void) const {
  std::stringstream ss;
  ss << (*this);
  return ss.str();
}
