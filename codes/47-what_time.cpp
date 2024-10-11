#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

struct TimeOfDay
{
    unsigned int hour{0};
    unsigned int minute{0};
};

void print_time(TimeOfDay the_time)
{
    std::cout << the_time.hour << ":" << the_time.minute;
}

/* parse_time(input)
   Given a string, attempt to parse the contents into an hour and minute
   and return a TimeOfDay object containing the result.

   Exceptions should be thrown in the following cases. The cases
   must be checked in the order below.
    - If the string does not contain two numerical fields separated
      by a colon (e.g. "10:06" or "17:10", but not "6" or "10:"),
      throw std::domain_error (NOT std::invalid_argument).
    - If the hour is not in the range 0 - 23 or the minute is not
      in the range 0 - 59, throw std::out_of_range

    (For this exercise, assume that if std::stoi finishes successfully, the
     value returned is a valid numerical interpretation of the input string)
*/
TimeOfDay parse_time(std::string input)
{

    std::string before_colon{};
    std::string after_colon{};

    // ???
}

int main()
{
    std::string input_string{};

    std::cout << "What time is it? ";
    std::getline(std::cin, input_string);
    std::cout << "You entered " << input_string << std::endl;

    // Task: Handle the error cases
    TimeOfDay T{parse_time(input_string)};
    std::cout << "The time is ";
    print_time(T);
    std::cout << std::endl;

    return 0;
}
