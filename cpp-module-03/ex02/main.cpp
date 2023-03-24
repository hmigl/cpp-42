/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:36:24 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/24 08:42:26 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>
#include <iostream>

#include "./ClapTrap.hpp"
#include "./ScavTrap.hpp"

int main(void) {
  {
    std::cout << "[ClapTrap]\n";
    ClapTrap porfiry("Porfiry Petrovitch");
    assert(porfiry.getHitPoints() == 10);
    assert(porfiry.getEnergyPoints() == 10);
    assert(porfiry.getAttackDamage() == 0);

    porfiry.attack("Rodion Raskolnikov");
    porfiry.takeDamage(5);
    porfiry.takeDamage(1866);
    porfiry.takeDamage(1872);
    porfiry.attack("Rodion Raskolnikov");
    porfiry.beRepaired(1880);
  }
  {
    std::cout << "\n[ScavTrap]\n";
    ScavTrap raskolnikov("Rodion Raskolnikov");
    assert(raskolnikov.getHitPoints() == 100);
    assert(raskolnikov.getEnergyPoints() == 50);
    assert(raskolnikov.getAttackDamage() == 20);

    raskolnikov.attack("Porfiry Petrovitch");
    raskolnikov.takeDamage(15);
    raskolnikov.takeDamage(1866);
    raskolnikov.takeDamage(1872);
    raskolnikov.attack("Porfiry Petrovitch");
    raskolnikov.beRepaired(1880);
    raskolnikov.guardGate();
  }
  {
    std::cout << "\n[ScavTrap]\n";
    ScavTrap parfyon("Parfyon Semyonovich Rogozhin");
    ScavTrap rogozhin(parfyon);

    rogozhin.attack("Myshkin");
    rogozhin.takeDamage(5);
    rogozhin.takeDamage(1866);
    assert(rogozhin.getHitPoints() == 0);

    rogozhin.takeDamage(1872);
    rogozhin.attack("Nastasya Filippovna");
    rogozhin.beRepaired(1880);
    assert(rogozhin.getHitPoints() == 1880);
  }
  return 0;
}
