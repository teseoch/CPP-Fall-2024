#include <string>
#include <iostream>
#include <stdexcept>

int F(int x)
{
    return 6;
}

int main()
{
    int y{1000};

    y = F(5);

    std::cout << "y = " << y << std::endl;

    return 0;
}