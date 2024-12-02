#include <iostream>
#include <string>
#include <vector>

template <typename T>
T second_to_last(std::vector<T> const &V)
{
    if (V.size() < 2)
        throw std::runtime_error("Vector does not contain 2 elements");
    T element = V.at(V.size() - 2);
    return element;
}

int main()
{
    std::vector<int> V1{-6, 10, 17};
    std::vector<float> V2{10.6, 11.6, 10.17};
    std::vector<std::string> V3{"Pear", "Raspberry", "Pineapple"};

    // Task: Condense the implementations of second_to_last into
    //       a single templated version which supports vectors
    //       of any element type.

    std::cout << "Second to last (V1): ";
    std::cout << second_to_last(V1);
    std::cout << std::endl;

    std::cout << "Second to last (V2): ";
    std::cout << second_to_last(V2);
    std::cout << std::endl;

    // TO DO
    std::cout << "Second to last (V3): ";
    std::cout << second_to_last(V3);
    std::cout << std::endl;

    return 0;
}
