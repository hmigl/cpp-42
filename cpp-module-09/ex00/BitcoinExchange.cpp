/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:57:10 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/28 09:04:07 by hmigl            ###   ########.fr       */
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

bool BitcoinExchange::is_valid_date(const std::string &date_str) const {
  if (date_str.size() != 10 || date_str[4] != '-' || date_str[7] != '-') {
    return false;
  }

  int year = std::atoi(date_str.substr(0, 4).c_str());
  int month = std::atoi(date_str.substr(5, 2).c_str());
  int day = std::atoi(date_str.substr(8, 2).c_str());
  if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
    return false;
  }

  int days_in_month = 31;
  if (month == 4 || month == 6 || month == 9 || month == 11) {
    days_in_month = 30;
  } else if (month == 2) {
    days_in_month =
        (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
  }
  if (day > days_in_month) {
    return false;
  }

  return true;
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
  if (!is_valid_date(date_str)) {
    std::cout << "Error: invalid date => " << date_str << std::endl;
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
  if (amount < 0) {
    std::cout << "Error: not a positive number.\n";
    return false;
  }
  if (amount > 1000) {
    std::cout << "Error: number too large.\n";
    return false;
  }
  amount_history_[date_str] = amount;
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
  if (it != exchange_rate_history_.begin() && query_date != it->first) {
    --it;
  }
  float res = associated_amount * it->second;
  std::cout << query_date << " => " << associated_amount << " = " << res
            << '\n';
}
