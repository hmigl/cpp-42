/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:18:52 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/24 12:06:20 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP_
#define SCAV_TRAP_HPP_

#include <string>

#include "./ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {
 public:
  ScavTrap();
  ScavTrap(const ScavTrap &);
  explicit ScavTrap(const std::string &);
  ~ScavTrap();

  void attack(const std::string &);
  void guardGate(void);

  ScavTrap &operator=(const ScavTrap &);
};

#endif  // SCAV_TRAP_HPP_
