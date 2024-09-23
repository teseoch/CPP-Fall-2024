#include <iostream>
#include <vector>
#include <string>

int main()
{
    //Task 0: Create a vector VS of string containing foo bar baz
    std::vector<std::string> VS{"foo", "bar", "baz"};
    //This is the same but longer
    // VS.push_back("foo");
    // VS.push_back("bar");
    // VS.push_back("baz");

    //Task 1: Print the vector
    for (std::string s : VS)
    {
        std::cout << s << std::endl;
    }

    //Task 2: Create big string by concatenating all the strings in the vector
    std::string big_string{};
    for (std::string s : VS)
    {
        //V0
        big_string += s + " ";

        //V1
        // big_string += s;
        // big_string += " ";

        //V2
        // big_string = big_string + s;
        // big_string = big_string + " ";

        //V3
        // big_string = big_string + s + " ";
    }

    //Task 3: Print the big string
    std::cout << big_string << std::endl;

    return 0;
}
