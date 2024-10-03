#include <iostream>

int main()
{
    int x{6};
    int y{10};

    bool q{true};

    if (q)
    {
        std::cout << "q is true" << std::endl;
    }
    else
    {
        std::cout << "q is false" << std::endl;
    }

    return 0;
}