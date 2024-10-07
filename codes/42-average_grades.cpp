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

    auto av{average_grades(grades1)};
    std::cout << "Average: " << av << std::endl;
    return 0;
}