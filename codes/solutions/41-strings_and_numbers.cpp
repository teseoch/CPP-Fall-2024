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

    try
    {
        int x{std::stoi(str)};
        std::cout << "As a number: " << x << std::endl;
    }
    catch (std::invalid_argument &e)
    {
        std::cout << "Not a number" << std::endl;
    }
    catch (std::out_of_range &e)
    {
        std::cout << "Really????" << std::endl;
    }
    catch (...)
    {
        std::cout << "we caught them all" << std::endl;
    }

    std::cout << "Done!" << std::endl;

    return 0;
}
