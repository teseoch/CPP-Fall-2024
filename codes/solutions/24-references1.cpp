#include <iostream>
#include <string>

void print_vector(std::vector<double> &v)
{
    for (auto val : v)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main()
{

    int x{100};

    std::vector<double> vec{};
    //push 1000000000000000000000000 values
    print_vector(vec);

    std::cout << "x is " << x << std::endl;
    x = 6;
    std::cout << "x is " << x << std::endl;

    //Task: Create an alias "y" for the variable x,
    //      and use y to set the value of x to 1000
    // int &y{x};
    int &y = x;

    y = 1000;

    std::cout << "x is " << x << std::endl;

    //Task: Create an alias "z" for the variable x
    //      using the auto keyword, then use z to
    //      set the value of x to 10000.
    auto &z{x};
    z = 10000;

    std::cout << "x is " << x << std::endl;

    return 0;
}
