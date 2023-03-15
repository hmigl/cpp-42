// Copyright (c) 2023 hmigl <hmigl@student.42sp.org.br>. All rights reserved.

#include "./Account.hpp"

int Account::_nbAccounts = 0, Account::_totalAmount = 0,
    Account::_totalNbDeposits = 0, Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
}

Account::Account(void) {}

Account::~Account(void) {}

void Account::makeDeposit(int deposit) {}

bool Account::makeWithdrawal(int withdrawal) { return true; }

int Account::checkAmount(void) const { return 0; }

void Account::displayStatus(void) const {}

int Account::getNbAccounts(void) { return 0; }

int Account::getTotalAmount(void) { return 0; }

int Account::getNbDeposits(void) { return 0; }

int Account::getNbWithdrawals(void) { return 0; }

void Account::displayAccountsInfos(void) {}

void Account::_displayTimestamp(void) {}
