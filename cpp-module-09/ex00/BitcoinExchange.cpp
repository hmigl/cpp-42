/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:57:10 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/27 16:18:18 by hmigl            ###   ########.fr       */
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

  std::string line;
  while (std::getline(ifs, line)) {
    if (line.empty()) {
      continue;
    }

    size_t pos = line.find("|");
    if (pos == std::string::npos) {
      std::cout << "Error: bad input => " << line << std::endl;
      continue;
    }

    std::string date_str = line.substr(0, pos);
    date_str.erase(remove_if(date_str.begin(), date_str.end(), isspace),
                   date_str.end());
    if (date_str.find_first_not_of("0123456789-") != std::string::npos &&
        date_str != "date") {
      std::cout << "Error: bad date format => " << date_str << std::endl;
    }

    std::string amount_str = line.substr(line.find_first_not_of("|", pos));
    amount_str.erase(remove_if(amount_str.begin(), amount_str.end(), isspace),
                     amount_str.end());
    float amount = std::strtod(amount_str.c_str(), NULL);
    if (amount < 0 || amount > 1000) {
      std::cout << "Error: not a positive or too large number.\n";
    }
  }
}
