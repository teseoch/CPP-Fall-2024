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

    int the_sum{0};
    // int test{1};

    auto sum_items{
        [&the_sum](int v) {
            the_sum += v;
        }};

    for_each(V, sum_items);

    std::cout << "The sum is " << the_sum << std::endl;

    return 0;
}