#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

struct TimeOfDay
{
    unsigned int hour{0};
    unsigned int minute{0};
};

void print_time(const TimeOfDay &the_time)
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
TimeOfDay parse_time(const std::string &input)
{

    std::string before_colon{};
    std::string after_colon{};

    bool colon_found{false};

    for (const auto &c : input)
    // for (auto c : input)
    {
        if (c == ':')
            colon_found = true;
        else if (colon_found)
            after_colon += c;
        else
            before_colon += c;
    }
    std::cout << before_colon << std::endl;
    std::cout << after_colon << std::endl;

    if (!colon_found)
    {
        throw std::domain_error{"Invalid time"};
    }

    int hour{};
    int min{};

    try
    {
        hour = std::stoi(before_colon);
        min = std::stoi(after_colon);
    }
    catch (std::invalid_argument &e)
    {
        throw std::domain_error{"Invalid time"};
    }

    if (hour < 0 || hour > 23 || min < 0 || min > 59)
    {
        throw std::out_of_range{"Wrong time"};
    }

    // TimeOfDay time{};
    // time.hour = hour;
    // time.minute = min;

    TimeOfDay time{(unsigned int)hour, (unsigned int)min};

    return time;
}

int main()
{
    std::string input_string{};

    std::cout << "What time is it? ";
    std::getline(std::cin, input_string);
    std::cout << "You entered " << input_string << std::endl;

    // Task: Handle the error cases
    try
    {
        TimeOfDay T{parse_time(input_string)};
        std::cout << "The time is ";
        print_time(T);
        std::cout << std::endl;
    }
    catch (std::domain_error &e)
    {
        std::cout << "Invalid input" << std::endl;
    }
    catch (std::out_of_range &e)
    {
        std::cout << "Invalid input" << std::endl;
    }

    return 0;
}
