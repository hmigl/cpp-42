/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:36:24 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/25 11:06:50 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>
#include <iostream>

#include "./DiamondTrap.hpp"

int main(void) {
  std::cout << "[DiamondTrap]\n";
  DiamondTrap nikolai("Nikolai Vsevolodovich Stavrogin");
  assert(nikolai.getHitPoints() == 100);    // FragTrap
  assert(nikolai.getEnergyPoints() == 50);  // ScavTrap
  assert(nikolai.getAttackDamage() == 30);  // FragTrap

  nikolai.attack("Lizaveta Nikolaevna Tushina");  // ScavTrap
  nikolai.whoAmI();                               // DiamondTrap
  nikolai.highFiveGuys();                         // FragTrap
  nikolai.guardGate();                            // ScavTrap

  return 0;
}
