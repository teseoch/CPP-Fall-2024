#include <iostream>
#include <string>

int main()
{
    std::string word1{}, word2{};

    std::cout << "Enter two words: ";

    std::cin >> word1;
    std::cin >> word2;

    // std::cin >> word1 >> word2;

    //Task: Read two words from the user into word1 and word2

    std::cout << "You entered [" << word1 << "] and [" << word2 << "]" << std::endl;
    return 0;
}