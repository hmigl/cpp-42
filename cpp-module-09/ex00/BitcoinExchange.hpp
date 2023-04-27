/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:52:29 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/27 10:40:54 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>

class BitcoinExchange {
 public:
  BitcoinExchange(const BitcoinExchange &);
  BitcoinExchange &operator=(const BitcoinExchange &);
  ~BitcoinExchange();

  static BitcoinExchange from_amount_history_file(const std::string &);

 private:
  BitcoinExchange();
  BitcoinExchange(const std::map<std::string, float> &exchange_rate_history,
                  const std::map<std::string, float> &amount_history);

  static const std::string ExchangeRateCSV;

  std::map<std::string, float> exchange_rate_history_;
  std::map<std::string, float> amount_history_;
};
