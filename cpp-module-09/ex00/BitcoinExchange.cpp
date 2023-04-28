/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:57:10 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/28 08:10:48 by hmigl            ###   ########.fr       */
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

void BitcoinExchange::check_file(std::ifstream &ifs,
                                 const std::string &file_name) const {
  if (!ifs.is_open()) {
    throw std::invalid_argument(file_name + ": invalid file");
  }
  if (ifs.peek() == std::ifstream::traits_type::eof()) {
    throw std::invalid_argument(file_name + ": empty file");
  }
}

void BitcoinExchange::csv_to_exchange_rate_history() {
  std::ifstream ifs(ExchangeRateCSV.c_str(), std::ios::in);
  check_file(ifs, ExchangeRateCSV);

  std::string line = "";
  while (std::getline(ifs, line)) {
    if (line.find_first_not_of("date,exchange_rate") == std::string::npos) {
      continue;
    }
    size_t pos = line.find(",");
    std::string date_str = line.substr(0, pos);
    std::string exchange_rate_str = line.substr(pos + 1);
    exchange_rate_history_.insert(std::pair<std::string, float>(
        date_str, std::strtod(exchange_rate_str.c_str(), NULL)));
  }
  ifs.close();
}

bool BitcoinExchange::read_date_and_amount(const std::string &line,
                                           size_t pos) {
  std::string date_str = line.substr(0, pos);
  date_str.erase(remove_if(date_str.begin(), date_str.end(), isspace),
                 date_str.end());
  if (date_str.find_first_not_of("0123456789-") != std::string::npos &&
      date_str != "date") {
    std::cout << "Error: bad date format => " << date_str << std::endl;
    return false;
  }

  std::string amount_str = line.substr(line.find_first_not_of("|", pos));
  amount_str.erase(remove_if(amount_str.begin(), amount_str.end(), isspace),
                   amount_str.end());
  if (amount_str.find_first_not_of("0123456789.-") != std::string::npos) {
    std::cout << amount_str << std::endl;
    std::cout << "Error: bad amount type => " << amount_str << std::endl;
    return false;
  }
  float amount = std::strtod(amount_str.c_str(), NULL);
  if (amount < 0 || amount > 1000) {
    std::cout << "Error: not positive or too large number.\n";
    return false;
  }
  amount_history_.insert(std::pair<std::string, float>(date_str, amount));
  return true;
}

void BitcoinExchange::eval_from_amount_history_file(
    const std::string &amount_history_file) {
  csv_to_exchange_rate_history();

  std::ifstream ifs(amount_history_file.c_str(), std::ios::in);
  check_file(ifs, amount_history_file);

  std::string line = "";
  while (std::getline(ifs, line)) {
    if (line.empty() ||
        line.find_first_not_of("date | value") == std::string::npos) {
      continue;
    }

    size_t pos = line.find("|");
    if (pos == std::string::npos) {
      std::cout << "Error: bad input => " << line << std::endl;
      continue;
    }

    if (read_date_and_amount(line, pos)) {
      eval_amount_from_exchange_rate();
    }
  }
  ifs.close();
}

void BitcoinExchange::eval_amount_from_exchange_rate() {
  // current [query_date,associated_amount] is the last one added
  std::map<std::string, float>::const_iterator ite = amount_history_.end();
  --ite;
  std::string query_date = ite->first;
  float associated_amount = ite->second;

  std::map<std::string, float>::const_iterator it =
      exchange_rate_history_.lower_bound(query_date);
  if (it != exchange_rate_history_.begin()) {
    --it;
  }
  float res = associated_amount * it->second;
  std::cout << query_date << " => " << associated_amount << " = " << res
            << '\n';
}
