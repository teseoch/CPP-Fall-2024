#include <iostream>
#include <vector>
#include <functional>

int element_sum(std::vector<int> const &V)
{
    int sum{0};
    for (auto x : V)
        sum += x;
    return sum;
}

int element_product(std::vector<int> const &V)
{
    int product{1};
    for (auto x : V)
        product = product * x;
    return product;
}

int element_min(std::vector<int> const &V)
{
    int minimum{V.at(0)};
    for (auto x : V)
    {
        if (x < minimum)
        {
            minimum = x;
        }
    }
    return minimum;
}

int main()
{

    std::vector<int> V{6, 10, 100};

    std::cout << "Sum of V: " << element_sum(V) << std::endl;
    std::cout << "Product of V: " << element_product(V) << std::endl;
    std::cout << "Minimum element of V: " << element_min(V) << std::endl;

    // std::cout << "Sum of V: " << accumulate(V, add2, 0) << std::endl;
    // std::cout << "Product of V: " << accumulate(V, mul2, 1) << std::endl;
    // std::cout << "Minimum element of V: " << accumulate(V, min2, V.at(0)) << std::endl;

    return 0;
}