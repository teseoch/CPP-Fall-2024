#include <iostream>
#include <vector>

int last(std::vector<int> input)
{
    /* Question: What should we do if the input vector
                 has no elements at all? */

    //opt 1
    //  return input.at(input.size() - 1);

    //opt 2
    // if (input.empty())
    // {
    //     throw std::invalid_argument{"The input vector is empty."};
    // }
    // return input.at(input.size() - 1);

    //opt 3
    // try
    // {
    //     return input.at(input.size() - 1);
    // }
    // catch (std::out_of_range &e)
    // {
    //     throw std::invalid_argument{"The input vector is empty."};
    // }
}

int main()
{
    // std::vector<int> W{6, 10, 17};
    std::vector<int> W{};
    auto z{last(W)};
    std::cout << "z: " << z << std::endl;
    return 0;
}
