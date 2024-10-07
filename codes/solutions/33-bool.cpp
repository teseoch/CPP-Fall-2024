#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v0{};
    std::vector<bool> v1{};

    int x{6};
    int y{10};

    bool p{true};
    bool q{false};
    auto r{p && q};
    // int z{};

    // z = 3.2;

    if (!r || !((p == q) && (x >= y)))
    {
        std::cout << "q is false" << std::endl;
    }
    else
    {
        std::cout << "q is true" << std::endl;
    }

    return 0;
}