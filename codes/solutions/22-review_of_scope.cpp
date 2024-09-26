#include <iostream>

int x{999};

int f(int x)
{
    std::cout << "f: x is " << x << std::endl;
    x = x + 10;
    return 1000;
}
int g()
{
    std::cout << "g: x is " << x << std::endl;
    x = 187;
    return x;
}

int main()
{
    int x{6};
    int y{10};
    std::cout << "main (1): " << x << " " << y << std::endl;
    if (x < y)
    {
        int x{100};
        int y = f(x);
        std::cout << "main (2): " << x << " " << y << std::endl;
    }
    std::cout << "main (3): " << x << " " << y << std::endl;
    y = g();
    std::cout << "main (4): " << x << " " << y << std::endl;

    return 0;
}
