#include <iostream>
#include <string>
#include <stdexcept>

/* Read a number from the user and return it */

int read_one_number()
{
    int value{};
    if (std::cin >> value)
    {
        //Value read successfully
        return value;
    }
    else
    {
        // ???
    }
}

int main()
{

    std::cout << "Enter a number: ";

    int n{read_one_number()};

    //Question: How can we detect cases where read_one_number failed?

    std::cout << "You entered " << n << std::endl;
    std::cout << "End of main" << std::endl;
    return 0;
}