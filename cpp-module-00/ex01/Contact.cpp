// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#include "./Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

Contact::Contact(const std::string &firstName, const std::string &lastName,
                 const std::string &nickname, const std::string &phoneNo,
                 const std::string &darkestSecret)
    : firstName_(firstName), lastName_(lastName), nickname_(nickname),
      phoneNo_(phoneNo), darkestSecret_(darkestSecret) {}
