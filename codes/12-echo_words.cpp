#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter some words: " << std::endl;

    std::string word{};

    while (std::cin >> word)
    { //This loop will continue to iterate as long as the input operation is successful
        std::cout << "You entered \"" << word << "\"" << std::endl;
    }

    //Question: How does the user signal to the program that they are done entering words?
    std::cout << "Done" << std::endl;
    return 0;
}