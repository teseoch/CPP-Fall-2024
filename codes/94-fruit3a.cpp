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

class Raspberry : public Fruit
{
public:
    /* Note that the virtual keyword is not required in front of
       these functions, since if a function is virtual in a base
       class, it is automatically virtual in all derived classes.
       It is harmless (and maybe better for readability) to add
       the virtual keyword, though.
    */
    std::string get_name() override
    {
        return "Raspberry";
    }
    bool is_delicious() override
    {
        return true;
    }

    Raspberry(int seed_count)
    {
        num_seeds = seed_count;
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

    try
    {
        Raspberry &r = dynamic_cast<Raspberry &>(f);
        std::cout << "f is a raspberry (" << r.get_num_seeds() << " seeds)" << std::endl;
        std::cout << "Name of r: " << r.get_name() << std::endl;
    }
    catch (std::bad_cast &e)
    {
        std::cout << "f is not a raspberry" << std::endl;
    }
}

int main()
{
    Fruit F{};
    Raspberry R{6};

    print_fruit(F);

    print_fruit(R);

    std::cout << "Name of R: " << R.get_name() << std::endl;

    Fruit &fr = R;
    std::cout << "Name of fr: " << fr.get_name() << std::endl;

    return 0;
}
