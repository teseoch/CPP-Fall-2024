#include <iostream>
#include <string>
#include <typeinfo>

class Fruit
{
public:
    Fruit()
    {
        std::cout << "Fruit default constructor" << std::endl;
    }
    virtual ~Fruit()
    {
        std::cout << "Fruit destructor" << std::endl;
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

/* To do: make this the base class of Raspberry and Pumpkin
class SeedFruit: public Fruit{
public:

    virtual int get_num_seeds(){
        return num_seeds;
    }
private:
    int num_seeds;
};
*/

class Raspberry : public Fruit
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
        std::cout << "Raspberry constructor" << std::endl;
        num_seeds = seed_count;
    }
    virtual ~Raspberry()
    {
        std::cout << "Raspberry destructor" << std::endl;
    }
    int get_num_seeds()
    {
        return num_seeds;
    }

private:
    int num_seeds;
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

class Pumpkin : public Fruit
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
    int get_num_seeds()
    {
        return num_seeds;
    }

private:
    int num_seeds;
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
        Raspberry &R = dynamic_cast<Raspberry &>(f);
        std::cout << "F is a raspberry (" << R.get_num_seeds() << " seeds)" << std::endl;
    }
    catch (std::bad_cast &e)
    {
        std::cout << "F is not a raspberry" << std::endl;
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
