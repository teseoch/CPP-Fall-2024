#include <iostream>
#include <utility>
#include <string>

struct my_pair
{
    int first;
    std::string second;
};

int main()
{
    int a{5};
    std::string b{"Hello"};

    auto p = std::make_pair(a, b);

    std::cout << "1 First: " << p.first << ", Second: " << p.second << std::endl;

    auto &[x, y] = p;
    //  auto [x, y] = p;
    std::cout << "2 First: " << x << ", Second: " << y << std::endl;

    x = 42;

    std::cout << "3 First: " << p.first << ", Second: " << p.second << std::endl;
    std::cout << "4 First: " << x << ", Second: " << y << std::endl;

    return 0;
}