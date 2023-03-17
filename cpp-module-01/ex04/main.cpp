// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#include <iostream>

#include "./Sedpp.hpp"

int main(int argc, char *argv[]) {
  if (argc != 4) {
    std::cout << "usage: \'./sedpp filename word replacement\'\n";
    return 1;
  }
  Sedpp sedpp = Sedpp::fromFilename(argv[1]);
  // sedpp.replace(argv[1], argv[2]);
  return 0;
}
