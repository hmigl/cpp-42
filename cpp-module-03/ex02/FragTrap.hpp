/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:18:52 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/24 12:17:20 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP_
#define FRAG_TRAP_HPP_

#include <string>

#include "./ClapTrap.hpp"

class FragTrap : public ClapTrap {
 public:
  FragTrap();
  FragTrap(const FragTrap &);
  explicit FragTrap(const std::string &);
  ~FragTrap();

  void highFiveGuys(void) const;

  FragTrap &operator=(const FragTrap &);
};

#endif  // FRAG_TRAP_HPP_
