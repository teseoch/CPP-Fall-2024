#include <iostream>
#include <stdexcept>

class CreditCard
{
public:
    CreditCard() : unpaid_balance{0}, credit_limit{1000}
    {
    }
    CreditCard(double initial_credit_limit) : unpaid_balance{0}, credit_limit{initial_credit_limit}
    {
        if (credit_limit < 0)
        {
            throw std::invalid_argument{"Credit limit cannot be negative."};
        }
    }

    double get_unpaid_balance() const
    {
        return unpaid_balance;
    }

    double get_credit_limit() const
    {
        return credit_limit;
    }

    double get_remaining_credit() const
    {
        auto remaining = get_credit_limit() - get_unpaid_balance();
        if (remaining < 0)
        {
            //Possible in cases where the credit limit was
            //lowered to be below the current balance.
            return 0;
        }
        return remaining;
    }

    void charge(double amount)
    {
        if (amount < 0)
        {
            throw std::invalid_argument{"Cannot spend a negative amount."};
        }
        if (amount > get_remaining_credit())
        {
            throw std::invalid_argument{"Insufficient funds."};
        }
        unpaid_balance += amount;
    }

    void repay(double amount)
    {
        if (amount < 0)
        {
            throw std::invalid_argument{"Cannot repay a negative amount."};
        }
        if (amount > get_unpaid_balance())
        {
            throw std::invalid_argument{"Cannot repay more than the outstanding balance."};
        }
        unpaid_balance -= amount;
    }

private:
    // Note that currency values are not normally stored
    // in floating-point variables due to numerical precision
    // issues.
    double unpaid_balance{};
    double credit_limit{};
};

void print_card_details(const CreditCard &C)
{
    //Task: Modify the code so that C can be passed by constant reference.
    std::cout << "Credit Card - Balance = $" << C.get_unpaid_balance();
    std::cout << ", Remaining Credit = $" << C.get_remaining_credit() << std::endl;
}

int main()
{
    CreditCard C1{1000};
    CreditCard C2{5000};

    // C1.get_unpaid_balance() = 100;

    C1.charge(6);
    C1.charge(10);
    C1.charge(17);

    C2.charge(187);
    C2.repay(116);

    std::cout << "Printing C1:" << std::endl;
    print_card_details(C1);

    std::cout << "Printing C2:" << std::endl;
    print_card_details(C2);

    return 0;
}
