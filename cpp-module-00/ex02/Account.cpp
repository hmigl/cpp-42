// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#include "./Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0, Account::_totalAmount = 0,
    Account::_totalNbDeposits = 0, Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
    : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
  _accountIndex = Account::_nbAccounts++;
  Account::_totalAmount += initial_deposit;

  // _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount
            << ";created\n";
}

Account::~Account(void) {}

void Account::makeDeposit(int deposit) {}

bool Account::makeWithdrawal(int withdrawal) { return true; }

int Account::checkAmount(void) const { return 0; }

void Account::displayStatus(void) const {
  // _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount
            << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
            << '\n';
}

int Account::getNbAccounts(void) { return _nbAccounts; }

int Account::getTotalAmount(void) { return _totalAmount; }

int Account::getNbDeposits(void) { return _totalNbDeposits; }

int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void Account::displayAccountsInfos(void) {
  // _displayTimestamp();
  std::cout << "accounts:" << Account::_nbAccounts << ";"
            << "total:" << Account::_totalAmount << ";"
            << "deposits:" << Account::_totalNbDeposits << ";"
            << "withdrawals:" << Account::_totalNbWithdrawals << '\n';
}

void Account::_displayTimestamp(void) {}
