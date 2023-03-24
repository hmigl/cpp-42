/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:36:24 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/24 08:12:40 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "./ClapTrap.hpp"
#include "./ScavTrap.hpp"

int main(void) {
  {
    std::cout << "[ClapTrap]\n";
    ClapTrap d("Porfiri");

    d.attack("Raskolnikov");
    d.takeDamage(5);
    d.takeDamage(1866);
    d.takeDamage(1872);
    d.attack("Raskolnikov");
    d.beRepaired(1880);
  }
  {
    std::cout << "\n[ScavTrap]\n";
    ScavTrap s("Raskolnikov");

    s.attack("Porfiri");
    s.takeDamage(15);
    s.takeDamage(1866);
    s.takeDamage(1872);
    s.attack("Porfiri");
    s.beRepaired(1880);
    s.guardGate();
  }
  return 0;
}
