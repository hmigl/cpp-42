/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:18:52 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/24 12:04:01 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP_
#define DIAMOND_TRAP_HPP_

#include <string>

#include "./FlagTrap.hpp"
#include "./ScavTrap.hpp"

class DiamondTrap : public FlagTrap, public ScavTrap {
 public:
  DiamondTrap();
  DiamondTrap(const DiamondTrap &);
  explicit DiamondTrap(const std::string &);
  ~DiamondTrap();

  void whoAmI();

  DiamondTrap &operator=(const DiamondTrap &);

 private:
  std::string name_;
};

#endif  // DIAMOND_TRAP_HPP_
