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
    virtual void charge(double amount)
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
    virtual void repay(double amount)
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

class PointsCard : public CreditCard
{
public:
    PointsCard(double initial_credit_limit) : CreditCard{initial_credit_limit}, points{0}
    {
    }

    //Task: Override the charge() function to produce the following behavior.
    //        1 Charge the card as usual (i.e. as in the CreditCard class)
    //        2 Assuming the charge succeeded (i.e. did not throw an exception),
    //          award one point per dollar spent (rounding down in fractional cases).

    void redeem_points()
    {
        //Redeem 1000 points for 10 dollars against the balance.
        if (points < 1000)
        {
            throw std::runtime_error{"Insufficient points to redeem."};
        }
        repay(10); //If this fails, the line below will never run.
        points -= 1000;
    }

    int get_points() const
    {
        return points;
    }

private:
    int points{};
};

void print_card_details(CreditCard const &C)
{
    std::cout << "Credit Card - Balance = $" << C.get_unpaid_balance();
    std::cout << ", Remaining Credit = $" << C.get_remaining_credit() << std::endl;
}

int main()
{

    CreditCard C1{2000};
    PointsCard C2{2000};

    C1.charge(701.87);
    C1.charge(610.17);

    C2.charge(701.87);
    std::cout << "Part 1: C2 has " << C2.get_points() << " points" << std::endl;
    C2.charge(610.17);
    std::cout << "Part 2: C2 has " << C2.get_points() << " points" << std::endl;

    std::cout << "Printing C1:" << std::endl;
    print_card_details(C1);

    std::cout << "Printing C2:" << std::endl;
    print_card_details(C2);
    std::cout << "Part 3: C2 has " << C2.get_points() << " points" << std::endl;

    C2.redeem_points();
    std::cout << "Part 4: C2 has " << C2.get_points() << " points" << std::endl;

    std::cout << "Printing C2:" << std::endl;
    print_card_details(C2);

    return 0;
}
