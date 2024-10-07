#include <iostream>
#include <string>

int main()
{

    std::cout << "Enter a string: ";
    std::string str{};
    std::cin >> str;

    std::cout << "You entered \"" << str << "\"" << std::endl;
    /* Task: If the string str contains a number (e.g. "6" or "-187"),
             print out "As a number: " followed by the numerical representation.
             Otherwise, print "Not a number".
             Note that std::stoi can be used to convert strings to integers. */

    return 0;
}
