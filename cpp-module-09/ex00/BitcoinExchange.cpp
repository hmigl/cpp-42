/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:57:10 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/27 10:57:29 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange.hpp"

const std::string BitcoinExchange::ExchangeRateCSV = "data.csv";

BitcoinExchange::BitcoinExchange()
    : exchange_rate_history_(), amount_history_() {}

BitcoinExchange::BitcoinExchange(
    const std::map<std::string, float> &exchange_rate_history,
    const std::map<std::string, float> &amount_history)
    : exchange_rate_history_(exchange_rate_history),
      amount_history_(amount_history) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
  *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  if (this != &other) {
    // ...
  }
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange BitcoinExchange::from_amount_history_file(
    const std::string &amount_history_file) {
  std::ifstream ifs(amount_history_file.c_str(), std::ios::in);
  if (!ifs.is_open()) {
    throw std::invalid_argument(amount_history_file + ": invalid file");
  }

  std::map<std::string, float> exchange_rate_history;
  std::map<std::string, float> amount_history;

  return BitcoinExchange(exchange_rate_history, amount_history);
}
