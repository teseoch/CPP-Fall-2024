#include <iostream>
#include <string>
#include <typeinfo>

class Fruit
{
public:
    virtual std::string get_name()
    {
        return "Generic Fruit";
    }
    virtual bool is_delicious()
    {
        return false;
    }
};

void print_fruit(Fruit &f)
{
    std::cout << "Fruit: " << f.get_name();
    std::cout << " ";
    if (f.is_delicious())
        std::cout << "(delicious)";
    else
        std::cout << "(not delicious)";
    std::cout << std::endl;
}

//Task: Add classes for Raspberry, Pumpkin and Pineapple.
//      Have the constructor for Raspberry take a single
//      int parameter (storing the number of seeds in the
//      raspberry).

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
