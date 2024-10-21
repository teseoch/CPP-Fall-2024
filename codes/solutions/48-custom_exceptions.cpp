#include <iostream>
#include <vector>

struct InvalidGradeException
{
    unsigned int grade_index{}; //Index of the invalid grade
    int bad_grade{};
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
    if (grades.empty())
    {
        throw EmptyGradeArrayException{};
    }

    float sum{0};
    for (unsigned int i{0}; i < grades.size(); i++)
    {
        if (grades.at(i) < 0 || grades.at(i) > 100)
        {
            // InvalidGradeException ige{};
            // ige.grade_index = i;
            // ige.bad_grade = grades.at(i);

            // throw ige;

            // InvalidGradeException ige{i, grades.at(i)};
            // throw ige;

            throw InvalidGradeException{i, grades.at(i)};
        }
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
        auto av{average_grades(grades3)};
        std::cout << "Average: " << av << std::endl;
    }
    catch (EmptyGradeArrayException &e)
    {
        std::cout << "Empty grades" << std::endl;
    }
    catch (InvalidGradeException &e)
    {
        std::cout << "Invalid grade at " << e.grade_index << " value is " << e.bad_grade << std::endl;
    }
    return 0;
}