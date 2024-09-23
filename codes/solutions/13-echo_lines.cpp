#include <iostream>
#include <string>

int main()
{
    std::string the_line{};

    while (std::getline(std::cin, the_line))
    {
        std::cout << "The line was [" << the_line << "]" << std::endl;
    }

    return 0;
}
