#include <iostream>

void F(int x)
{
    x = x + 6;
}
void G(int &x)
{
    x = x + 10;
}

int main()
{
    int Z{0};
    std::cout << "Z = " << Z << std::endl;

    F(Z);
    std::cout << "Z = " << Z << std::endl;

    G(Z);
    std::cout << "Z = " << Z << std::endl;

    int &W{Z};
    G(W);
    std::cout << "Z = " << Z << std::endl;

    return 0;
}
