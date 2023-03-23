/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:59:04 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/23 14:57:51 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP_
#define CLAP_TRAP_HPP_

#include <string>

class ClapTrap {
 public:
  ClapTrap();
  ClapTrap(const ClapTrap &);
  explicit ClapTrap(const std::string &);
  ~ClapTrap();

  void attack(const std::string &);
  void takeDamage(unsigned int);
  void beRepaired(unsigned int);

  ClapTrap &operator=(const ClapTrap &);

 protected:
  std::string name_;
  unsigned int hitPoints_;
  unsigned int energyPoints_;
  unsigned int attackDamage_;
};

#endif  // CLAP_TRAP_HPP_
