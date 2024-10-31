#include <iostream>
#include <string>

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
    std::cout << "F (2)" << std::endl;
}

int main()
{
    std::cout << "main (1)" << std::endl;
    Fruit A{"Raspberry"};
    F("Grape");
    if (0 < 1)
    {
        Fruit B{"Pineapple"};
        std::cout << "main (2)" << std::endl;
    }
    Fruit C{"Pear"};
    std::cout << "main (3)" << std::endl;
    return 0;
}