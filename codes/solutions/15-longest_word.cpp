#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter some words: " << std::endl;

    std::string longest_word{};

    //Task: A basic loop to read words from the user is given below.
    //      Modify the code such that, once the user is done entering words,
    //      the _longest_ word entered is stored in the variable longest_word.
    //      If multiple words with the longest length are entered, only keep
    //      the first one.

    std::string word{};
    // while (std::cin >> word)
    // { //This loop will continue to iterate as long as the input operation is successful
    //     std::cout << "You entered \"" << word << "\"" << std::endl;

    //     if (word.length() > longest_word.length())
    //     {
    //         longest_word = word;
    //     }
    // }

    //Variants to try:
    // - If there are multiple longest words, keep the last one.
    while (std::cin >> word)
    { //This loop will continue to iterate as long as the input operation is successful
        std::cout << "You entered \"" << word << "\"" << std::endl;

        if (word.length() >= longest_word.length())
        {
            longest_word = word;
        }
    }
    // - Keep _all_ words with the longest length and print them out at the end.
    //   (this variant requires a collection type, like a vector)

    std::cout << "The longest word you entered was \"" << longest_word << "\"" << std::endl;
    return 0;
}