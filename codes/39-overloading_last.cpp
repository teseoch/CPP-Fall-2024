#include <iostream>
#include <string>
#include <vector>

std::string last(std::vector<std::string> input)
{
    /* Question: What should we do if the input vector
                 has no elements at all? */
    return input.at(input.size() - 1);
}

int last(std::vector<int> input)
{
    /* Question: What should we do if the input vector
                 has no elements at all? */
    return input.at(input.size() - 1);
}

char last(std::string input)
{
    /* Question: What should we do if the input string
                 has no elements at all? */
    return input.at(input.size() - 1);
}

int main()
{
    std::vector<std::string> V{"Raspberry", "Pineapple", "Pear"};
    std::vector<int> W{6, 10, 17};
    auto x{last(V)};
    auto y{last(x)};
    auto z{last(W)};
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "z: " << z << std::endl;
    return 0;
}
