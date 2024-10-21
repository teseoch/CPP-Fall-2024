#include <iostream>
#include <vector>
#include <stdexcept>

using std::cout;
using std::endl;
using std::vector;

/* average_grades( grades )
   Given a vector of grades (integers in the range 0 - 100),
   compute and return the average of all elements.

   Task: Improve this code to deal with cases where the
         vector is empty or where grades in the vector are
         outside the range 0 - 100.

*/
float average_grades(vector<int> const &grades)
{
    if (grades.size() == 0)
    {
        throw std::invalid_argument{"Can't compute the average of zero things"};
    }
    float sum{0};
    for (unsigned int i{0}; i < grades.size(); i++)
    {
        if (grades.at(i) < 0 || grades.at(i) > 100)
        {
            throw std::out_of_range{"Grade out of range"};
        }
        sum += grades.at(i);
    }
    return sum / grades.size();
}

int main()
{
    vector<int> grades1{90, 70, 80};
    vector<int> grades2{};            //Invalid (can't average zero things)
    vector<int> grades3{90, 70, -80}; //Invalid (grades can't be negative)

    auto av{average_grades(grades1)};
    cout << "Average: " << av << endl;
    return 0;
}