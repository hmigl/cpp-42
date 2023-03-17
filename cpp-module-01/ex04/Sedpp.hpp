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
  bool replace(const std::string &searchStr, const std::string &replaceStr);
};

#endif  // SEDPP_HPP_
