#include <iostream>
#include <vector>
#include <functional>

bool all_of(std::vector<int> const &V, std::function<bool(int)> condition)
{
    for (auto x : V)
        if (!condition(x))
            return false;
    return true;
}

bool is_even(int x)
{
    return x % 2 == 0;
}

int main()
{
    std::vector<int> V0{0, 0, 0, 0};
    std::vector<int> V1{0, 2, 4, 6, 8, 10};
    std::vector<int> V2{-2, -4, 0, 6, 10};
    std::vector<int> V3{6, 10, 17, 187};

    std::cout << "V0: is_even = " << all_of(V0, is_even) << std::endl;
    std::cout << "V1: is_even = " << all_of(V1, is_even) << std::endl;
    std::cout << "V2: is_even = " << all_of(V2, is_even) << std::endl;
    std::cout << "V3: is_even = " << all_of(V3, is_even) << std::endl;

    return 0;
}