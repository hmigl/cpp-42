// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#include <cstring>
#include <iostream>

class Megaphone {
 private:
  int argc_;
  char **argv_;

  Megaphone() {}
  Megaphone(int argc, char **argv) : argc_(argc), argv_(argv) {}

  void MakeFeedbackNoise() const {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
  }

  void MakeLoudNoise() const {
    for (int i = 1; i < this->argc_; i++)
      for (const char *p = this->argv_[i]; *p; p++)
        std::cout << char(toupper(*p));
    std::cout << '\n';
  }

 public:
  static Megaphone FromArgs(int argc, char *argv[]) {
    return Megaphone(argc, argv);
  }

  void MakeNoise() const {
    if (this->argc_ == 1) {
      MakeFeedbackNoise();
    } else {
      MakeLoudNoise();
    }
  }
};

int main(int argc, char *argv[]) {
  Megaphone megaphone = Megaphone::FromArgs(argc, argv);

  megaphone.MakeNoise();
  return 0;
}
