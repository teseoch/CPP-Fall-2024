#include <iostream>
#include <string>
#include <typeinfo>

class Fruit
{
public:
    //Notice that this is not virtual
    std::string get_name()
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
    /*
    Since get_name and is_delicious are not virtual in the base
    class, the "override" keyword is inappropriate here (and
    would generate a compile error). One reason that "override"
    is useful is as an error-checking feature (with "override"
    used, the program will only compile if the function is
    actually virtual in the base class).
    */
    std::string get_name()
    {
        return "Raspberry";
    }
    bool is_delicious()
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
    //Since the "apparent type" of f is Fruit&, we should
    //expect that the version of get_name() in the Fruit
    //class will be called on the line below (even if
    //the provided object is actually a Raspberry).
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
        //The "apparent type" of r is Raspberry&, so we should
        //expect that the version of get_name() in the Raspberry
        //class will be called on the line below.
        //Notice that r and f are the _same object_, but
        //the two references have different apparent types.
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
