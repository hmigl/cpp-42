/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 07:53:27 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/12 07:53:28 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "./A.hpp"
#include "./B.hpp"
#include "./C.hpp"

void identify(Base &p) {
  try {
    A &a = dynamic_cast<A &>(p);
    std::cout << "actual type: \'A\'\n";
    static_cast<void>(a);
    return;
  } catch (const std::exception &e) {
  }

  try {
    B &b = dynamic_cast<B &>(p);
    std::cout << "actual type: \'B\'\n";
    static_cast<void>(b);
    return;
  } catch (const std::exception &e) {
  }

  try {
    C &c = dynamic_cast<C &>(p);
    std::cout << "actual type: \'C\'\n";
    static_cast<void>(c);
    return;
  } catch (const std::exception &e) {
  }

  std::cout << "unknown type\n";
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p)) {
    std::cout << "actual type: \'A\'\n";
    return;
  }
  if (dynamic_cast<B *>(p)) {
    std::cout << "actual type: \'B\'\n";
    return;
  }
  if (dynamic_cast<C *>(p)) {
    std::cout << "actual type: \'C\'\n";
    return;
  }
  std::cout << "unknown type\n";
}

Base *generate() {
  srand(time(0));

  switch (rand() % 3) {
    case 0:
      std::cout << "generating type \'A\'\n";
      return new A;
    case 1:
      std::cout << "generating type \'B\'\n";
      return new B;
    default:
      std::cout << "generating type \'C\'\n";
      return new C;
  }
}

int main() {
  Base *b = generate();
  identify(b);
  identify(*b);
  delete b;
  return 0;
}
