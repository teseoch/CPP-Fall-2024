#include <iostream>

int F(int &a, int b)
{
    a = 6;
    b = 10;
    std::cout << "F: " << a << " " << b << std::endl;
    return a + b;
}

void G(int &a, int &b, int c)
{
    b = a;
    a = c;
    c = F(b, a);
    std::cout << "G: " << a << " " << b << " " << c << std::endl;
}

int main()
{
    int a{111};
    int b{116};
    int c{445};

    if (a > 100)
    {
        int a{0};
        c = F(a, b);
        std::cout << "Outside: " << a << " " << b << " " << c << std::endl;
        if (a < 100)
        {
            int b{-1000};
            G(a, b, c);
            std::cout << "Inside: " << a << " " << b << " " << c << std::endl;
        }
    }

    std::cout << "End: " << a << " " << b << " " << c << std::endl;
    return 0;
}