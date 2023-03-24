/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:18:52 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/24 19:12:44 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP_
#define FRAG_TRAP_HPP_

#include <string>

#include "./ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {
 public:
  FragTrap();
  FragTrap(const FragTrap &);
  explicit FragTrap(const std::string &);
  ~FragTrap();

  void highFiveGuys(void) const;

  FragTrap &operator=(const FragTrap &);

 private:
  static const unsigned int HitPoints = 100;
  static const unsigned int EnergyPoints = 100;
  static const unsigned int AttackDamage = 30;
};

#endif  // FRAG_TRAP_HPP_
