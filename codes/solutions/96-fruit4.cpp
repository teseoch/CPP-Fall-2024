#include <iostream>
#include <string>
#include <typeinfo>

class Fruit
{
public:
    Fruit()
    {
    }
    virtual std::string get_name()
    {
        return "Generic Fruit";
    }
    virtual bool is_delicious()
    {
        return false;
    }
};

// To do: make this the base class of Raspberry and Pumpkin
class SeedFruit : public Fruit
{
public:
    int get_num_seeds()
    {
        return num_seeds;
    }

protected:
    int num_seeds;
};

class Raspberry : public SeedFruit
{
public:
    virtual std::string get_name() override
    {
        return "Raspberry";
    }
    virtual bool is_delicious() override
    {
        return true;
    }

    Raspberry(int seed_count)
    {
        num_seeds = seed_count;
    }
};

class Pineapple : public Fruit
{
public:
    virtual std::string get_name() override
    {
        return "Pineapple";
    }
    virtual bool is_delicious() override
    {
        return false;
    }
};

class Pumpkin : public SeedFruit
{
public:
    virtual std::string get_name() override
    {
        return "Pumpkin";
    }
    virtual bool is_delicious() override
    {
        return false;
    }

    Pumpkin()
    {
        num_seeds = 100000000;
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

    //Task: Adapt this for the new SeedFruit class
    try
    {
        SeedFruit &R = dynamic_cast<SeedFruit &>(f);
        std::cout << "F is a seeded fuit (" << R.get_num_seeds() << " seeds)" << std::endl;
    }
    catch (std::bad_cast &e)
    {
        std::cout << "F is not a seeded" << std::endl;
    }
}

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
