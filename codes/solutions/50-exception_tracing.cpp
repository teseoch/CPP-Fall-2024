#include <iostream>

int G(int z)
{
    if (z < 0)
        throw std::domain_error{"z must be non-negative"};
    return 6;
}
int F(int y)
{
    int sum{0};
    try
    {
        sum += G(y);
    }
    catch (std::domain_error &e)
    {
        return 10;
    }
    if (sum > 5)
        throw std::runtime_error{"Sum too large"};
    sum += G(y - 2);
    return sum;
}
int main()
{
    int x{116};
    try
    {
        auto x{F(-1)};
        std::cout << "x is " << x << std::endl;
        x = F(1);
        std::cout << "x is " << x << std::endl;
    }
    catch (std::domain_error &e)
    {
        std::cout << "Domain Error" << std::endl;
    }
    catch (std::runtime_error &e)
    {
        std::cout << "Runtime Error" << std::endl;
    }
    std::cout << "Final value of x is " << x << std::endl;
    return 0;
}
