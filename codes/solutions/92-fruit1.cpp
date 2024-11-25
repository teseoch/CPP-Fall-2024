#include <iostream>
#include <string>
#include <typeinfo>

class Fruit
{
public:
    virtual std::string get_name() const
    {
        return "Generic Fruit";
    }
    virtual bool is_delicious() const
    {
        return false;
    }
};

void print_fruit(const Fruit &f)
{
    std::cout << "Fruit: " << f.get_name();
    std::cout << " ";
    if (f.is_delicious())
        std::cout << "(delicious)";
    else
        std::cout << "(not delicious)";

    //this dosent work
    // f.get_num_seeds();

    std::cout << std::endl;
}

//Task: Add classes for Raspberry, Pumpkin and Pineapple.
//      Have the constructor for Raspberry take a single
//      int parameter (storing the number of seeds in the
//      raspberry).
class Raspberry : public Fruit
{

public:
    Raspberry(int ns) : n_seeds{ns} {}

    virtual std::string get_name() const override
    {
        return "Raspberry";
    }

    virtual bool is_delicious() const override
    {
        return true;
    }

    int num_seeds() const
    {
        return n_seeds;
    }

private:
    int n_seeds;
};

class Pumpkin : public Fruit
{

public:
    virtual std::string get_name() const override
    {
        return "Pumpkin";
    }

    virtual bool is_delicious() const override
    {
        return true;
    }
};

class Pineapple : public Fruit
{

public:
    virtual std::string get_name() const override
    {
        return "Pineapple";
    }

    virtual bool is_delicious() const override
    {
        return false;
    }
};

int main()
{
    Fruit F{};
    Raspberry R{6};
    Pumpkin J{};
    Pineapple P{};
    print_fruit(F);
    print_fruit(R);
    print_fruit(P);
    print_fruit(J);
    return 0;
}
