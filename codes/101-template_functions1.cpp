#include <iostream>
#include <string>
#include <vector>

void print_vector(std::vector<int> const &V)
{
    for (auto x : V)
        std::cout << x << " ";
    std::cout << std::endl;
}
void print_vector(std::vector<float> const &V)
{
    for (auto x : V)
        std::cout << x << " ";
    std::cout << std::endl;
}

int main()
{

    std::vector<int> V1{-6, 10, 17};
    std::vector<float> V2{10.6, 11.6, 10.17};
    std::vector<std::string> V3{"Pear", "Raspberry", "Pineapple"};

    // Task: Write a new version of the functions below which can handle V3

    print_vector(V1);
    print_vector(V2);
    //print_vector(V3); // TO DO

    return 0;
}
