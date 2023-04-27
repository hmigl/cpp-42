/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:57:10 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/27 11:52:28 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange.hpp"

const std::string BitcoinExchange::ExchangeRateCSV = "data.csv";

BitcoinExchange::BitcoinExchange()
    : exchange_rate_history_(), amount_history_() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
  *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  if (this != &other) {
    exchange_rate_history_ = other.exchange_rate_history_;
    amount_history_ = other.amount_history_;
  }
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::eval_from_amount_history_file(
    const std::string &amount_history_file) {
  std::ifstream ifs(amount_history_file.c_str(), std::ios::in);
  if (!ifs.is_open()) {
    throw std::invalid_argument(amount_history_file + ": invalid file");
  }

  if (ifs.peek() == std::ifstream::traits_type::eof()) {
    throw std::invalid_argument(amount_history_file + ": empty file");
  }
}
