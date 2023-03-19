// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#include "./Harl.hpp"

#include <cstring>
#include <iostream>

const int Harl::MessageLevels;
const char *const Harl::LoggingLevels[4] = {"DEBUG", "INFO", "WARNING",
                                            "ERROR"};

Harl::Harl() {}

Harl::~Harl() {}

int Harl::translateLevel(const std::string &level) const {
  int levelIndex = 0;

  while (levelIndex < MessageLevels &&
         std::strcmp(level.c_str(), LoggingLevels[levelIndex])) {
    levelIndex++;
  }
  return levelIndex;
}

void Harl::complain(std::string level) const {
  void (Harl::*levelsTable[MessageLevels])(void)
      const = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
  int levelIndex = translateLevel(level);

  for (int i = 0; i < MessageLevels; i++) {
    if (!std::strcmp(LoggingLevels[i], level.c_str())) {
      (this->*levelsTable[i])();
    }
  }
}

void Harl::debug(void) const {
  std::cout << "[DEBUG]\n";
  std::cout << "I love having extra bacon for my "
               "7XL-double-cheese-triple-pickle-special- ketchup burger. I "
               "really do!\n";
}

void Harl::info(void) const {
  std::cout << "[INFO]\n";
  std::cout << "I cannot believe adding extra bacon costs more money. You "
               "didn’t put enough bacon in my burger! If you did, I wouldn’t "
               "be asking for more!\n";
}

void Harl::warning(void) const {
  std::cout << "[WARNING]\n";
  std::cout << "I think I deserve to have some extra bacon for free. I’ve been "
               "coming for years whereas you started working here since last "
               "month.\n";
}

void Harl::error(void) const {
  std::cout << "[ERROR]\n";
  std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}
