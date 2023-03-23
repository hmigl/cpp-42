/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:36:24 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/23 10:54:14 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

int main(void) {
  ClapTrap d("Dostoevsky");

  d.attack("Tolstoy");
  d.takeDamage(5);
  d.takeDamage(1866);
  d.takeDamage(1872);
  d.attack("Tolstoy");
  d.beRepaired(1880);
  return 0;
}
