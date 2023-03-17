// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#include "./Sedpp.hpp"

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>

Sedpp::Sedpp(const std::string &filename, const std::string &contents)
    : filename_(filename), contents_(contents) {}

Sedpp::~Sedpp() {}

void Sedpp::writeToOutputFile() const {
  std::string outputFilename = filename_ + ".replace";
  std::ofstream outputFile(outputFilename.c_str(),
                           std::ios::out | std::ios::trunc);

  outputFile << contents_;
  outputFile.close();
}

bool Sedpp::replace(const std::string &searchStr,
                    const std::string &replaceStr) {
  if (contents_.find(searchStr) == std::string::npos) {
    return false;
  }
  const size_t searchStrLen = searchStr.length();
  const size_t replaceStrLen = replaceStr.length();
  size_t pos = 0;

  while ((pos = contents_.find(searchStr, pos)) != std::string::npos) {
    contents_ = contents_.substr(0, pos) + replaceStr +
                contents_.substr(pos + searchStrLen);
    pos += replaceStrLen;
  }
  return true;
}

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
