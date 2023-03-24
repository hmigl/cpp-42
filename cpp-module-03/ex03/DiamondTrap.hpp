/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:18:52 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/24 13:42:05 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP_
#define DIAMOND_TRAP_HPP_

#include <string>

#include "./FragTrap.hpp"
#include "./ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
 public:
  DiamondTrap();
  DiamondTrap(const DiamondTrap &);
  explicit DiamondTrap(const std::string &);
  ~DiamondTrap();

  void attack(const std::string &);
  void whoAmI() const;

  DiamondTrap &operator=(const DiamondTrap &);

 private:
  std::string name_;
};

#endif  // DIAMOND_TRAP_HPP_
