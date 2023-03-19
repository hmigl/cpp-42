// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#ifndef HARL_HPP_
#define HARL_HPP_

#include <string>

class Harl {
 private:
  static const int MessageLevels = 4;
  static const char *const LoggingLevels[MessageLevels];

  void debug(void) const;
  void info(void) const;
  void warning(void) const;
  void error(void) const;

 public:
  Harl();
  ~Harl();

  void complain(std::string level) const;
};

#endif  // HARL_HPP_
