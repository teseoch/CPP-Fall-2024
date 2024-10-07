#include <iostream>
#include <string>
#include <vector>

struct Student
{
    std::string student_id;
    std::vector<int> grades;
};

/* compute_gpa(s)
   Given a student S, compute and return the GPA (average of all grades)
   of S. */
float compute_gpa(Student const &s)
{
    /* TO DO */
}

/* print_student(s)
   Given a student S, print the ID, list of grades
   and GPA of S (using the compute_gpa function above to compute
   the GPA).
*/
void print_student(Student const &s)
{

    std::cout << "Student (" << s.student_id << "): ";
    std::cout << "Grades are ";
    /* TO DO */
}

int main()
{

    Student A{};
    A.student_id = "V00999999";
    A.grades.push_back(84);
    A.grades.push_back(100);

    Student B{"V00123456", {90, 70, 80}};

    print_student(A);
    print_student(B);
    return 0;
}
