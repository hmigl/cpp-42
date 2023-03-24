/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:18:52 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/24 10:32:37 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAG_TRAP_HPP_
#define FLAG_TRAP_HPP_

#include <string>

#include "./ClapTrap.hpp"

class FlagTrap : public ClapTrap {
 public:
  FlagTrap();
  FlagTrap(const FlagTrap &);
  explicit FlagTrap(const std::string &);
  ~FlagTrap();

  void highFiveGuys(void) const;

  FlagTrap &operator=(const FlagTrap &);
};

#endif  // FLAG_TRAP_HPP_
