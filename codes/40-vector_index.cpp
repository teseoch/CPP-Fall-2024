#include <iostream>
#include <vector>

int main()
{

    std::vector<int> V{6, 111, 116, 10, 187, 17};

    std::cout << "Enter an index: ";
    int idx{};
    if (std::cin >> idx)
    {
        int element = V.at(idx);
        std::cout << "The element at index " << idx << " is " << element << std::endl;
    }
    else
    {
        std::cout << "You didn't enter an index" << std::endl;
    }

    return 0;
}
