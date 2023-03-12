// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#include <cstring>
#include <iostream>

class Megaphone {
 private:
  int argc_;
  char **argv_;

  Megaphone() {}
  Megaphone(int argc, char **argv) : argc_(argc), argv_(argv) {}

 public:
  static Megaphone FromArgs(int argc, char *argv[]) {
    return Megaphone(argc, argv);
  }

  void MakeNoise() const {
    int len = 0;

    if (this->argc_ == 1) {
      std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    } else {
      for (int i = 1; i < this->argc_; i++) {
        len = strlen(this->argv_[i]);

        for (int j = 0; j < len; j++) {
          char c = toupper(this->argv_[i][j]);
          std::cout << c;
        }
      }
      std::cout << '\n';
    }
  }
};

int main(int argc, char *argv[]) {
  Megaphone megaphone = Megaphone::FromArgs(argc, argv);

  megaphone.MakeNoise();
  return 0;
}
