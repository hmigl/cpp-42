// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#ifndef SEDPP_HPP_
#define SEDPP_HPP_

#include <string>

class Sedpp {
 private:
  std::string filename_;
  std::string contents_;

  Sedpp(const std::string &filename, const std::string &contents);

 public:
  ~Sedpp();

  static Sedpp fromFilename(const std::string &filename);
  void replace(const std::string &s1, const std::string &s2);
};

#endif  // SEDPP_HPP_
