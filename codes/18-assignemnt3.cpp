#include <iostream>
#include <vector>

int main()
{
    std::vector<int> V{6, 10, 17};
    std::vector<int> W{};

    // Second law of assignemnt statements
    // An ordinary (not initialization) assignment statement is ALWAYS a copy

    W = V;
    V.at(0) = 999;
    W.push_back(42);

    for (int v : V)
    {
        std::cout << v << std::endl;
    }

    for (int w : W)
    {
        std::cout << w << std::endl;
    }
}
