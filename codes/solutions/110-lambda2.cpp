#include <iostream>
#include <vector>
#include <functional>

void for_each(std::vector<int> const &V, std::function<void(int)> element_function)
{
    for (auto x : V)
        element_function(x);
}

int main()
{
    std::vector<int> V{6, 10, 17};

    auto print_int{
        [](int v) {
            std::cout << v << ", ";
        }};

    for_each(V, print_int);
    std::cout << std::endl;

    return 0;
}