/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:52:29 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/27 18:39:30 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

class BitcoinExchange {
 public:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &);
  BitcoinExchange &operator=(const BitcoinExchange &);
  ~BitcoinExchange();

  void eval_from_amount_history_file(const std::string &);

 private:
  static const std::string ExchangeRateCSV;

  std::map<std::string, float> exchange_rate_history_;
  std::map<std::string, float> amount_history_;

  void csv_to_exchange_rate_history();
  void check_file(std::ifstream &, const std::string &) const;
  bool read_date_and_amount(const std::string &, size_t);
};
