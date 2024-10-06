#include <iostream>
#include <string>

char &get_character(std::string &s)
{
    size_t last_index{s.length() - 1};

    return s.at(last_index);
}

int main()
{
    std::string str{"Hello, World!"};
    std::cout << "Part 1: " << str << std::endl;

    char &ch{str.at(2)};
    ch = 'X';
    std::cout << "Part 2: " << str << std::endl;

    char &r1{get_character(str)};
    r1 = 'X';
    std::cout << "Part 3: " << str << std::endl;

    auto r12{get_character(str)};
    r12 = 'Y';
    std::cout << "Part 4: " << str << std::endl;
}