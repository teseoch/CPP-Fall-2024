#include <iostream>
#include <string>
#include <vector>

// template <typename type, int K>
template <typename type>
void print_vector(std::vector<type> const &V)
{
    for (const auto &x : V)
        std::cout << x << " ";
    std::cout << std::endl;
}

// void print_vector(std::vector<int> const &V)
// {
//     for (auto x : V)
//         std::cout << x << " ";
//     std::cout << std::endl;
// }
// void print_vector(std::vector<float> const &V)
// {
//     for (auto x : V)
//         std::cout << x << " ";
//     std::cout << std::endl;
// }

// void print_vector(std::vector<std::string> const &V)
// {
//     for (auto x : V)
//         std::cout << x << " ";
//     std::cout << std::endl;
// }

/*
write new function copying this by replacing T with your type

void print_vector(std::vector<T> const &V)
{
    for (auto x : V)
        std::cout << x << " ";
    std::cout << std::endl;
}

int x = 6;
std::array<int, x>

*/

int main()
{
    std::vector<int> V1{-6, 10, 17};
    std::vector<float> V2{10.6, 11.6, 10.17};
    std::vector<std::string> V3{"Pear", "Raspberry", "Pineapple"};

    // Task: Write a new version of the functions below which can handle V3

    print_vector<int>(V1);
    print_vector<float>(V2);
    print_vector<std::string>(V3); // TO DO

    // print_vector<int, 4>(V1);
    // print_vector<float, 1>(V2);
    // print_vector<std::string, 40>(V3); // TO DO

    return 0;
}
