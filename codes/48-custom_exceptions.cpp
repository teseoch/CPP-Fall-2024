#include <iostream>
#include <vector>

struct InvalidGradeException
{
    unsigned int grade_index{}; //Index of the invalid grade
};

struct EmptyGradeArrayException
{
    //This structure has no members (but it can still be created and thrown)
};

/* average_grades( grades )
   Given a vector of grades (integers in the range 0 - 100),
   compute and return the average of all elements.

   Task: Improve this code to handle the following errors.
          - If the vector is empty, throw EmptyGradeArrayException
          - If any grades in the vector are invalid (negative or greater than
            100), throw an instance of InvalidGradeException containing the
            index of the first invalid grade in the vector.

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