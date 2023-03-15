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

Account::~Account(void) {
  // _displayTimestamp();

  Account::_nbAccounts--;
  std::cout << "index:" << _accountIndex << ";amount:" << _amount
            << ";closed\n";
}

void Account::makeDeposit(int deposit) {
  _amount += deposit;
  Account::_totalAmount += deposit;

  _nbDeposits++;
  Account::_totalNbDeposits++;

  // _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit
            << ";deposit:" << deposit << ";amount:" << _amount
            << ";nb_deposits:" << _nbDeposits << '\n';
}

bool Account::makeWithdrawal(int withdrawal) {
  // _displayTimestamp();

  std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
            << ";withdrawal:";
  if (withdrawal > _amount) {
    std::cout << "refused\n";
    return false;
  }

  _amount -= withdrawal;
  _totalAmount -= withdrawal;

  _nbWithdrawals++;
  _totalNbWithdrawals++;

  std::cout << withdrawal << ";amount:" << _amount
            << ";nb_withdrawals:" << _nbWithdrawals << '\n';
  return true;
}

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
