#include <iostream>
#include <string>

int main()
{
    //A string of characters can be represented with the std::string type.

    //Task 0: Create two strings s1 and s2, each with some initial text.
    std::string s1{"hello"};
    std::string s2{"world"};

    //Task 1: Print out the value of s1
    std::cout << "the string s1 is [" << s1 << "]" << std::endl;
    std::cout << "the string s2 is [" << s2 << "]" << std::endl;

    //Task 2: Create an empty string s3.
    //        Is an initializer necessary?
    std::string s3{};

    std::cout << "the string s3 is [" << s3 << "]" << std::endl;

    //Task 3: Set s3 to contain the concatenation of s1 and s2,
    //        then print out the value of s3.
    s3 = s1 + s2;

    std::cout << "the string s1 is [" << s1 << "]" << std::endl;
    std::cout << "the string s2 is [" << s2 << "]" << std::endl;
    std::cout << "the string s3 is [" << s3 << "]" << std::endl;

    //Task 4: Print out the length of s1, s2 and s3.

    std::cout << "the length of the string s1 is " << s1.length() << std::endl;
    std::cout << "the length of the string s2 is " << s2.size() << std::endl;
    std::cout << "the length of the string s3 is " << s3.length() << std::endl;

    std::cout << "the char at index 1 of s1 is " << s1.at(1) << std::endl;

    s3.at(1) = 'X';

    s3.push_back('!');
    s3.push_back('!');
    s3.push_back('!');

    //Task 5: Iterate over each character in s3 (with two different kinds of
    //        loop) and print each character by itself.
    for (char c : s3)
    {
        std::cout << c << std::endl;
    }

    std::cout << "-------------------------" << std::endl;

    for (size_t i{0}; i < s3.length(); ++i)
    {
        std::cout << s3.at(i) << std::endl;
    }

    return 0;
}
