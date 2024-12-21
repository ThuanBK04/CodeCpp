#include "Account_Util.h"

// Utility helper functions

void display(const std::vector<Account *> &accounts)
{
    std::cout << "\n=== Accounts ===================================" << std::endl;
    // Because each of accounts is a pointer, so don't need &
    for (const auto acc : accounts)
    {
        // auto is a pointer, so need to de-reference the pointer, that's object
        std::cout << *acc << std::endl;
    }
}

void deposit(std::vector<Account *> &accounts, double amount)
{
    std::cout << "\n=== Deposit accounts ===================================" << std::endl;
    for (auto acc : accounts)
    {
        // need to change the operator to arrow operator because have pointer
        if (acc->deposit(amount))
        {
            std::cout << "Deposited " << amount << " to " << *acc << std::endl;
        }
        else
        {
            // Need to dereference pointer to get the account
            std::cout << "Falied Deposit of " << amount << " to " << *acc << std::endl;
        }
    }
}

void withdraw(std::vector<Account *> &accounts, double amount)
{
    std::cout << "\n=== Withdraw accounts ===================================" << std::endl;
    for (auto acc : accounts)
    {
        if (acc->withdraw(amount))
        {
            // Need to dereference pointer to get the account
            std::cout << "Withdraw " << amount << " from " << *acc << std::endl;
        }
        else
        {
            // Need to dereference pointer to get the account
            std::cout << "Failed withdrawal of " << amount << " from " << *acc << std::endl;
        }
    }
}
