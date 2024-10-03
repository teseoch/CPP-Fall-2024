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
    c = 0;
    std::cout << "G: " << a << " " << b << " " << c << std::endl;
}

int main()
{
    int a{111};
    int b{116};
    int c{445};

    c = F(a, b);

    G(b, c, a);

    std::cout << "End of main: " << a << " " << b << " " << c << std::endl;
    return 0;
}