#include <iostream>
#include <string>
#include <stdexcept>

class Fruit
{
public:
    Fruit(std::string the_name) : name{the_name}
    {
        std::cout << "Fruit Constructor: " << name << std::endl;
    }
    ~Fruit()
    {
        std::cout << "Fruit Destructor: " << name << std::endl;
    }

private:
    std::string name{};
};

void F(std::string prefix)
{
    std::cout << "F (1)" << std::endl;
    Fruit Z{prefix + "fruit"};
    throw std::runtime_error{"Uh oh"};
    std::cout << "F (2)" << std::endl;
}

int main()
{
    std::cout << "main (1)" << std::endl;
    Fruit A{"Raspberry"};
    try
    {
        Fruit B{"Pear"};
        F("Grape");
    }
    catch (std::runtime_error &e)
    {
        std::cout << "main (2)" << std::endl;
        Fruit C{"Lime"};
    }
    std::cout << "main (3)" << std::endl;
    return 0;
}