// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#include <iostream>
#include <string>

int main(void) {
  std::string str = "HI THIS IS BRAIN";
  std::string *stringPTR = &str;
  std::string &stringREF = str;

  std::cout << "Memory addresses:\n";
  std::cout << &str << '\n';
  std::cout << stringPTR << '\n';
  std::cout << &stringREF << '\n';

  std::cout << "\nValues:\n";
  std::cout << str << '\n';
  std::cout << *stringPTR << '\n';
  std::cout << stringREF << '\n';
  return 0;
}
