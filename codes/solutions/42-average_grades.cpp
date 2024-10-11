#include <iostream>
#include <vector>
#include <stdexcept>

/* average_grades( grades )
   Given a vector of grades (integers in the range 0 - 100),
   compute and return the average of all elements.

   Task: Improve this code to deal with cases where the
         vector is empty or where grades in the vector are
         outside the range 0 - 100.

*/
float average_grades(std::vector<int> const &grades)
{
    if (grades.empty())
    {
        std::invalid_argument e{"The grades are empty, this is ok but bad!"};
        throw e;
    }

    for (auto g : grades)
    {
        if (g < 0)
        {
            std::out_of_range e{"One of the grades is negative"};
            throw e;
        }
        if (g > 100)
        {
            std::out_of_range e{"One of the grades is larger than 100"};
            throw e;
        }
    }

    float sum{0};
    for (unsigned int i{0}; i < grades.size(); i++)
    {
        sum += grades.at(i);
    }
    return sum / grades.size();
}

int main()
{

    std::vector<int> grades1{90, 70, 80};
    std::vector<int> grades2{};            //Invalid (can't average zero things)
    std::vector<int> grades3{90, 70, -80}; //Invalid (grades can't be negative)

    try
    {
        auto av{average_grades(grades1)};
        std::cout << "Average: " << av << std::endl;
    }
    // catch (...)
    // {
    //     std::cout << "I fixed everything!!!!!!!!!!!!!!!" << std::endl;
    // }
    catch (std::invalid_argument &e)
    {
        std::cout << "something bad happened, invalid arg: " << e.what() << std::endl;
    }
    catch (std::out_of_range &e)
    {
        std::cout << "something bad happened, out of range: " << e.what() << std::endl;
    }

    return 0;
}