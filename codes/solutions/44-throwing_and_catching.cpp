#include <string>
#include <iostream>
#include <stdexcept>

int F(int x)
{
    int a{42};
    std::string bla{"hello word"};
    float b{3.14};

    if (x < 0)
    {
        throw a;
    }
    else if (x == 0)
    {
        throw b;
    }
    else if (x > 10)
    {
        throw bla;
    }

    return 6;
}

int main()
{
    int y{1000};

    try
    {
        y = F(100);
    }
    catch (int number)
    {
        std::cout << "got an int " << number << std::endl;
    }
    catch (float number)
    {
        std::cout << "got a float " << number << std::endl;
    }
    catch (...)
    {
        std::cout << "got a ... " << std::endl;
    }

    std::cout << "y = " << y << std::endl;

    return 0;
}