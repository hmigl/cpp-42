// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#include <iostream>

#include "./Harl.hpp"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "\'usage: ./harlFilter <LOG LEVEL>\'\n";
    return 1;
  }
  Harl harl;

  harl.complain(argv[1]);
  return 0;
}
