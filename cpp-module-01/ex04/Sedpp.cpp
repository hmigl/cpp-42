// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#include "./Sedpp.hpp"

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>
#include <sstream>

Sedpp::Sedpp(const std::string &filename, const std::string &contents)
    : filename_(filename), contents_(contents) {}

Sedpp::~Sedpp() {}

// void Sedpp::replace(const std::string &s1, const std::string &s2) {}

Sedpp Sedpp::fromFilename(const std::string &filename) {
  std::ifstream ifs(filename.c_str(), std::ios::in);
  std::ostringstream buf;

  if (!ifs.is_open()) {
    std::perror(filename.c_str());
    exit(1);
  }
  buf << ifs.rdbuf();
  ifs.close();
  return Sedpp(filename, buf.str());
}
