/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 08:54:51 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/28 09:07:11 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP_
#define BRAIN_HPP_

#include <iostream>
#include <string>

class Brain {
 public:
  Brain();
  Brain(const Brain &);
  ~Brain();

  const std::string *getIdeas() const;

  Brain &operator=(const Brain &);

 private:
  static const int NbIdeas = 100;
  std::string ideas_[NbIdeas];
};

#endif  // BRAIN_HPP_
