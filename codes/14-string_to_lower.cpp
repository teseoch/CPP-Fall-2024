#include <iostream>
#include <string> // Don't forget to include <string> if you use strings
#include <cctype> // cctype contains std::tolower (and C++ declarations of other ctype.h functions)

int main()
{
    std::string original_string{};
    std::string lower_string{};

    original_string = "Hello World";
    std::cout << "Before: " << '[' << original_string << ']' << std::endl;

    //Task: Add some code such that the print statement below prints out
    //      the lowercase version of the value of original_string.
    //      You will likely want to use the std::tolower function.

    std::cout << "After: " << '[' << lower_string << ']' << std::endl;

    return 0;
}
