#include <iostream>
#include <string>

int main()
{

    std::string the_line{};

    //Read a line of text from the user
    std::cout << "Enter a line of text: " << std::endl;
    std::getline(std::cin, the_line);

    //Print it back out
    std::cout << "The line was [" << the_line << "], the legth is " << the_line.length() << std::endl;

    return 0;
}
