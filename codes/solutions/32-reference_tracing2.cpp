#include <iostream>

int F(int &a, int b)
{
    a = 6;
    b = 10;
    std::cout << "F: " << a << " " << b << std::endl;
    return a + b; //16
}

void G(int &a, int &b, int c)
{
    b = a; //6
    a = c;
    c = F(b, a); //16
    std::cout << "G: " << a << " " << b << " " << c << std::endl;
}

int main()
{
    int a{111};
    int b{116};
    int c{445};

    if (a > 100)
    {
        int aa{0};
        c = F(aa, b);
        std::cout << "Outside: " << aa << " " << b << " " << c << std::endl;
        if (aa < 100)
        {
            int bb{-1000};
            G(aa, bb, c);
            std::cout << "Inside: " << aa << " " << bb << " " << c << std::endl;
        }
    }

    std::cout << "End: " << a << " " << b << " " << c << std::endl;
    return 0;
}