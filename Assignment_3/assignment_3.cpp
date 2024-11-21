/*  Definitions for the StudentDB class.

   You may modify this file, but ONLY in the places indicated. In particular, you must
   place the implementation of each function.

   In the specification comments below, the following terms are used.
    - A "student ID" is a string identifier for a student. An example might be
      "V00123456", but any string could reasonably be used.
    - A "course ID" is a string identifier for a course. We might use something
      like "CSC 116", but again, any string is feasible.
    - A "term code" is a string representing a particular academic term. As
      with student and course IDs, a term code can be any string, but often
      we might choose a string representing a date in "YYYYMM" notation,
      like "202209".

   In each of the function specifications below, if there is a list of
   error cases provided, your code MUST check for the error cases in the
   order written. If a particular call to the function would result in
   more than one error condition being met, the exception thrown must be
   the error condition listed FIRST in the specification comment.
*/

#include <string>
#include <set>
#include <map>
#include <iostream>

/* Definitions of exception objects */
/* Do not modify these definitions in any way */

/* DBDuplicateError: Thrown when attempts are made to insert an already-existing
                     record into the database. */
struct DBDuplicateError
{
    // This structure has no members, since in the contexts where it is thrown,
    // the cause of the error will be unambiguous.
};

/* StudentNotFoundError: Thrown in cases where a function is called with a
                         student ID that has not yet been added to the
                         database. */
struct StudentNotFoundError
{
    std::string student_id{};
};

/* EnrollmentNotFoundError: Thrown when a student enrollment record is expected
                            to exist but does not exist. */
struct EnrollmentNotFoundError
{
    std::string student_id{};
    std::string course_id{};
    std::string term{};
};

/* InvalidGradeError: Thrown when an invalid grade value (greater than 100)
                      is provided to a database function. */
struct InvalidGradeError
{
    unsigned int bad_grade{}; //The grade value that produced the error
};

/* MissingGradeError: Thrown when a non-existant grade is requested. */
struct MissingGradeError
{
    // This has no members.
};

/* EmptyAverageError: Thrown when an average is requested but no source
                      grades exist. */
struct EmptyAverageError
{
    // This has no members.
};

/* Definition of the StudentDB class */
/* You are only permitted to modify the private section of this class definition. */

class StudentDB
{
public:
    /* Do not modify any of the declarations and code in this section in any way. */
    /* (Impelment these function below) */

    /* Constructor
       Initialize this StudentDB object to be empty.
    */
    StudentDB();

    /* add_student(student_id)
       Add the provided student ID to the database. If the student is already
       in the database, throw an instance of DBDuplicateError.
    */
    void add_student(std::string const &student_id);

    /* all_students()
       Return a set containing the IDs of all students in the database.
    */
    std::set<std::string> all_students();

    /* enroll(student_id, course_id, term)
       Given a student ID, course ID (e.g. "CSC 116") and term code
       (e.g. "202209"), add a record of the student being enrolled
       in the provided course/term.

       If the student is already enrolled in the provided course
       during the provided term, throw an instance of DBDuplicateError.

       If the student does not exist in the database, throw an instance
       of StudentNotFoundError containing the student ID.
    */
    void enroll(std::string const &student_id, std::string const &course_id, std::string const &term);

    /* get_student_enrollment_records(student_id)
       Given a student ID, return a set of (course_id, term) pairs
       reflecting all of the enrollment data for the provided student.

       Note that a student may be enrolled in the same course in multiple
       terms, and in such cases there will be a separate record in the
       result for each term in which the student was enrolled.

       If the student does not exist in the database, throw an instance
       of StudentNotFoundError containing the student ID.

       If the student does exist but has no enrollment data, return an
       empty set.
    */
    std::set<std::pair<std::string, std::string>> get_student_enrollment_records(std::string const &student_id);

    /* courses_taken_by_student(student_id)
       Given a student ID, return a set containing the course IDs of every
       course in which the student is enrolled (whether or not the student
       has been assigned a grade in that course).

       If the student does not exist in the database, throw an instance
       of StudentNotFoundError containing the student ID.

       If the student does exist but has no enrollment data, return an empty set.
    */
    std::set<std::string> courses_taken_by_student(std::string const &student_id);

    /* assign_grade(student_id, course_id, term, grade)
       Given enrollment details for a particular student/course/term, set the
       grade associated with that enrollment to the provided value. If a grade
       was previously set for this student/course/term, overwrite it with the
       provided value.

       Note that a student might be enrolled in the same course in different
       terms, so this function must ensure that only the grade for the specified
       offering is set.

       If the student does not exist in the database, throw an instance
       of StudentNotFoundError containing the student ID.

       If the student does exist, but is not already enrolled in the provided
       course/term, throw an instance of EnrollmentNotFoundError containing
       the student/course/term.

       If the grade is greater than 100, throw an InvalidGradeError containing
       the grade value.
    */
    void assign_grade(std::string const &student_id, std::string const &course_id, std::string const &term, unsigned int grade);

    /* get_grade(student_id, course_id, term)
       Given a student ID, course ID and term, retrieve the assigned grade for
       the provided student/course/term.

       If the student does not exist in the database, throw an instance
       of StudentNotFoundError containing the student ID.

       If the student does exist, but is not already enrolled in the provided
       course/term, throw an instance of EnrollmentNotFoundError containing
       the student/course/term.

       If the student is enrolled in the provided course/term but has not been
       assigned a grade, throw an instance of MissingGradeError.

    */
    unsigned int get_grade(std::string const &student_id, std::string const &course_id, std::string const &term);

    /* student_transcript_by_course(student_id)
       Given a student ID, return a mapping of course IDs to grades.
       The result will only contain entries for courses in which the student
       has at least one assigned grade.

       If a student has received multiple grades for the same course ID
       (due to taking the course in multiple terms), only store the _highest_
       grade received in the resulting map.

       If the student does not exist in the database, throw an instance
       of StudentNotFoundError containing the student ID.

       If the student does exist but does not have any assigned grades,
       return an empty map.
    */
    std::map<std::string, unsigned int> student_transcript_by_course(std::string const &student_id);

    /* compute_student_average(student_id)
       Given a student ID, compute the average percentage (between 0 and 100)
       of the assigned grades in each of the student's courses.

       If a student has received multiple grades for the same course ID
       (due to taking the course in multiple terms), incorporate only the
       _highest_ recorded grade for each course in the average.

       If the student does not exist in the database, throw an instance
       of StudentNotFoundError containing the student ID.

       If the student does exist but has no assigned grades, throw
       an instance of EmptyAverageError.
    */
    double compute_student_average(std::string const &student_id);

    /* enrolled_students(course_id, term)
       Given a course ID (e.g. "CSC 116") and a term code (e.g. "202209"),
       return a set of all students who are enrolled in the provided course
       in the provided term (whether or not they have been assigned a grade).

       If there are no entries in the database for the provided course/term,
       return an empty set.
    */
    std::set<std::string> enrolled_students(std::string const &course_id, std::string const &term);

    /* course_grades(course_id, term)
       Given a course ID (e.g. "CSC 116") and a term code (e.g. "202209"),
       return a mapping which maps the student ID of every student
       enrolled in the given course/term to their grade.

       The result must include every student enrolled in the provided
       course/term who has been assigned a grade, but not include students
       who are enrolled but have no assigned grade.

       If there are no entries in the database for the provided course/term,
       return an empty map.
    */
    std::map<std::string, unsigned int> course_grades(std::string const &course_id, std::string const &term);

    /* compute_course_average(course_id, term)
       Given a student ID, compute the average percentage (between 0 and 100)
       of all assigned grades for the provided course in the provided term.

       Only those students who have assigned grades for the provided course/term
       will be incorporated into the average.

       If there are no grades assigned in the database for the provided
       course/term, throw an instance of EmptyAverageError
    */
    double compute_course_average(std::string const &course_id, std::string const &term);

    /* Do not modify any of the code above this line */

private:
    /* Your code here */
    /* (Add any private data or functions you need)*/
    /* (You may also add new #include directives at the top of the file) */
};

StudentDB::StudentDB()
{
    /* Your code here */
}

void StudentDB::add_student(std::string const &student_id)
{
    /* Your code here */
}

std::set<std::string> StudentDB::all_students()
{
    /* Your code here */
}

void StudentDB::enroll(std::string const &student_id, std::string const &course_id, std::string const &term)
{
    /* Your code here */
}

std::set<std::pair<std::string, std::string>> StudentDB::get_student_enrollment_records(std::string const &student_id)
{
    /* Your code here */
}

std::set<std::string> StudentDB::courses_taken_by_student(std::string const &student_id)
{
    /* Your code here */
}

void StudentDB::assign_grade(std::string const &student_id, std::string const &course_id, std::string const &term, unsigned int grade)
{
    /* Your code here */
}

unsigned int StudentDB::get_grade(std::string const &student_id, std::string const &course_id, std::string const &term)
{
    /* Your code here */
}

std::map<std::string, unsigned int> StudentDB::student_transcript_by_course(std::string const &student_id)
{
    /* Your code here */
}

double StudentDB::compute_student_average(std::string const &student_id)
{
    /* Your code here */
}

std::set<std::string> StudentDB::enrolled_students(std::string const &course_id, std::string const &term)
{
    /* Your code here */
}

std::map<std::string, unsigned int> StudentDB::course_grades(std::string const &course_id, std::string const &term)
{
    /* Your code here */
}

double StudentDB::compute_course_average(std::string const &course_id, std::string const &term)
{
    /* Your code here */
}

/*
   This is a basic tester program for the StudentDB object.

   You are welcome to use this to assist with your testing, but it is your
   responsibility to test your implementation thoroughly, including on test
   cases not in this file.

   For example, you could modify this file to add more tests, or write
   your own separate tester.

   One thing that is not tested by this program but is still important in
   general is to ensure that if multiple StudentDB objects are created,
   they are all independent (so adding or modifying a record in one StudentDB
   object has no effect on any other StudentDB objects in existence).
*/
int main()
{
    StudentDB db{};

    std::cout << "Test 1: Adding some students" << std::endl;
    db.add_student("V00123458");
    db.add_student("V00123457");
    db.add_student("V00123456");

    std::cout << "  Test 1a: Attempting to create a duplicate student" << std::endl;
    try
    {
        db.add_student("V00123456");
        std::cout << "    Did not catch DBDuplicateError: Behaviour is incorrect." << std::endl;
    }
    catch (DBDuplicateError &e)
    {
        std::cout << "    Caught DBDuplicateError: Behaviour is correct." << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Test 2: Retrieving student list." << std::endl;
    {
        std::cout << "  Students are: ";

        std::set<std::string> all_students{db.all_students()};
        for (auto s : all_students)
        {
            std::cout << s << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Test 3: Enrolling students in courses." << std::endl;
    db.enroll("V00123456", "CSC 116", "202209");
    db.enroll("V00123456", "MECH 200", "202209");
    db.enroll("V00123456", "MATH 204", "202209");

    db.enroll("V00123457", "CSC 116", "202209");
    db.enroll("V00123457", "CSC 116", "202201");
    db.enroll("V00123457", "MATH 204", "202209");

    db.enroll("V00123458", "CSC 116", "202201");

    std::cout << "  Test 3a: Attempting to enroll an invalid student." << std::endl;
    try
    {
        db.enroll("V00999999", "CSC XYZ", "222222"); //The only invalid part of this call is the student ID (which is not in the database yet)
        std::cout << "    Did not catch StudentNotFoundError: Behaviour is incorrect." << std::endl;
    }
    catch (StudentNotFoundError &e)
    {
        std::cout << "    Caught StudentNotFoundError (" << e.student_id << "): Behaviour is correct." << std::endl;
    }

    std::cout << "  Test 3b: Attempting a duplicate enrollment." << std::endl;
    try
    {
        db.enroll("V00123457", "MATH 204", "202209");
        std::cout << "    Did not catch DBDuplicateError: Behaviour is incorrect." << std::endl;
    }
    catch (DBDuplicateError &e)
    {
        std::cout << "    Caught DBDuplicateError: Behaviour is correct." << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Test 4: Retrieving enrollment records." << std::endl;
    {
        std::set<std::pair<std::string, std::string>> enrollment_set{};
        enrollment_set = db.get_student_enrollment_records("V00123456");
        std::cout << "  For V00123456:" << std::endl;
        for (auto [course, term] : enrollment_set)
        {
            std::cout << "    Course: " << course << "  Term: " << term << std::endl;
        }

        enrollment_set = db.get_student_enrollment_records("V00123457");
        std::cout << "  For V00123457:" << std::endl;
        for (auto [course, term] : enrollment_set)
        {
            std::cout << "    Course: " << course << "  Term: " << term << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "Test 5: Retrieving courses taken by students." << std::endl;
    {
        std::set<std::string> courses_taken{};
        courses_taken = db.courses_taken_by_student("V00123456");
        std::cout << "  For V00123456: ";
        for (auto course : courses_taken)
        {
            std::cout << course << " ";
        }
        std::cout << std::endl;

        courses_taken = db.courses_taken_by_student("V00123457");
        std::cout << "  For V00123457: ";
        for (auto course : courses_taken)
        {
            std::cout << course << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Test 6: Adding more students and enrollments" << std::endl;
    db.add_student("V00123459");
    db.add_student("V00123460");

    db.enroll("V00123459", "CSC 116", "202209");
    db.enroll("V00123460", "MATH 204", "202209");
    db.enroll("V00123460", "MATH 342", "202209");

    std::cout << std::endl;
    std::cout << "Test 7: Assigning some grades" << std::endl;

    db.assign_grade("V00123456", "CSC 116", "202209", 67);
    db.assign_grade("V00123456", "MECH 200", "202209", 85);
    db.assign_grade("V00123456", "MATH 204", "202209", 92);

    db.assign_grade("V00123457", "CSC 116", "202201", 93);
    db.assign_grade("V00123457", "CSC 116", "202209", 87);

    db.assign_grade("V00123459", "CSC 116", "202209", 78);
    db.assign_grade("V00123460", "MATH 204", "202209", 90);

    std::cout << "  Test 7a: Attempting to grade an invalid student." << std::endl;
    try
    {
        db.assign_grade("V00999999", "CSC 116", "202209", 17);
        std::cout << "    Did not catch StudentNotFoundError: Behaviour is incorrect." << std::endl;
    }
    catch (StudentNotFoundError &e)
    {
        std::cout << "    Caught StudentNotFoundError (" << e.student_id << "): Behaviour is correct." << std::endl;
    }
    std::cout << "  Test 7b: Attempting to grade an unenrolled student." << std::endl;
    try
    {
        db.assign_grade("V00123458", "CSC 116", "202209", 17);
        std::cout << "    Did not catch EnrollmentNotFoundError: Behaviour is incorrect." << std::endl;
    }
    catch (EnrollmentNotFoundError &e)
    {
        std::cout << "    Caught EnrollmentNotFoundError (";
        std::cout << e.student_id << ", " << e.course_id << ", " << e.term;
        std::cout << "): Behaviour is correct." << std::endl;
    }
    std::cout << "  Test 7c: Attempting to assign an invalid grade." << std::endl;
    try
    {
        db.assign_grade("V00123458", "CSC 116", "202201", 187);
        std::cout << "    Did not catch InvalidGradeError: Behaviour is incorrect." << std::endl;
    }
    catch (InvalidGradeError &e)
    {
        std::cout << "    Caught InvalidGradeError (" << e.bad_grade << "): Behaviour is correct." << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Test 8: Retrieving student grades." << std::endl;
    std::cout << "  Grade for V00123456 in CSC 116 in 202209: " << db.get_grade("V00123456", "CSC 116", "202209") << std::endl;
    std::cout << "  Grade for V00123457 in CSC 116 in 202201: " << db.get_grade("V00123457", "CSC 116", "202201") << std::endl;
    std::cout << "  Grade for V00123457 in CSC 116 in 202209: " << db.get_grade("V00123457", "CSC 116", "202209") << std::endl;

    std::cout << "  Test 8a: Attempting to retrieve a grade for an unenrolled student." << std::endl;
    try
    {
        ;
        auto gr{db.get_grade("V00123458", "CSC 116", "202209")};
        std::cout << "    Grade for V00123458 for CSC 116 in 202209: " << gr << std::endl;
        std::cout << "    Did not catch EnrollmentNotFoundError: Behaviour is incorrect." << std::endl;
    }
    catch (EnrollmentNotFoundError &e)
    {
        std::cout << "   Caught EnrollmentNotFoundError (";
        std::cout << e.student_id << ", " << e.course_id << ", " << e.term;
        std::cout << "): Behaviour is correct." << std::endl;
    }
    std::cout << "  Test 8b: Attempting to retrieve an unassigned grade." << std::endl;
    try
    {
        auto gr{db.get_grade("V00123458", "CSC 116", "202201")};
        std::cout << "    Grade for V00123458 for CSC 116 in 202201: " << gr << std::endl;
        std::cout << "    Did not catch MissingGradeError: Behaviour is incorrect." << std::endl;
    }
    catch (MissingGradeError &e)
    {
        std::cout << "    Caught MissingGradeError: Behaviour is correct." << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Test 9: Retrieving transcripts." << std::endl;
    {
        std::map<std::string, unsigned int> transcript_map{};
        transcript_map = db.student_transcript_by_course("V00123456");
        std::cout << "  For V00123456:" << std::endl;
        for (auto [course, grade] : transcript_map)
        {
            std::cout << "    Course: " << course << "  Grade: " << grade << std::endl;
        }

        transcript_map = db.student_transcript_by_course("V00123457");
        std::cout << "  For V00123457:" << std::endl;
        for (auto [course, grade] : transcript_map)
        {
            std::cout << "    Course: " << course << "  Grade: " << grade << std::endl;
        }

        transcript_map = db.student_transcript_by_course("V00123458");
        if (transcript_map.size() == 0)
        {
            std::cout << "  For V00123458: Transcript is empty: Behaviour is correct." << std::endl;
        }
        else
        {
            std::cout << "  For V00123458:" << std::endl;
            for (auto [course, grade] : transcript_map)
            {
                std::cout << "    Course: " << course << "  Grade: " << grade << std::endl;
            }
            std::cout << "  This is incorrect (the transcript should be empty)." << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "Test 10: Computing student averages." << std::endl;
    std::cout << "  Average for V00123456: " << db.compute_student_average("V00123456") << std::endl;
    std::cout << "  Average for V00123457: " << db.compute_student_average("V00123457") << std::endl;

    std::cout << "  Test 10a: Attempting to compute average for a student with no grades." << std::endl;
    try
    {
        auto av{db.compute_student_average("V00123458")};
        std::cout << "    Average for V00123458: " << av << std::endl;
        std::cout << "    Did not catch EmptyAverageError: Behavior is incorrect" << std::endl;
    }
    catch (EmptyAverageError &e)
    {
        std::cout << "    Caught EmptyAverageError: Behaviour is correct." << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Test 11: Retrieving enrollment by course." << std::endl;
    {
        std::set<std::string> enrollment_set{};
        enrollment_set = db.enrolled_students("CSC 116", "202201");
        std::cout << "  For CSC 116 in 202201: ";
        for (auto student_id : enrollment_set)
        {
            std::cout << student_id << " ";
        }
        std::cout << std::endl;

        enrollment_set = db.enrolled_students("CSC 116", "202209");
        std::cout << "  For CSC 116 in 202209: ";
        for (auto student_id : enrollment_set)
        {
            std::cout << student_id << " ";
        }
        std::cout << std::endl;

        enrollment_set = db.enrolled_students("MATH 204", "202209");
        std::cout << "  For MATH 204 in 202209: ";
        for (auto student_id : enrollment_set)
        {
            std::cout << student_id << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Test 12: Retrieving grades by course." << std::endl;
    {
        std::map<std::string, unsigned int> grade_map{};
        grade_map = db.course_grades("CSC 116", "202201");
        std::cout << "  For CSC 116 in 202201:" << std::endl;
        for (auto [student_id, grade] : grade_map)
        {
            std::cout << "    Student: " << student_id << "  Grade: " << grade << std::endl;
        }

        grade_map = db.course_grades("CSC 116", "202209");
        std::cout << "  For CSC 116 in 202209:" << std::endl;
        for (auto [student_id, grade] : grade_map)
        {
            std::cout << "    Student: " << student_id << "  Grade: " << grade << std::endl;
        }

        grade_map = db.course_grades("MATH 204", "202209");
        std::cout << "  For MATH 204 in 202209:" << std::endl;
        for (auto [student_id, grade] : grade_map)
        {
            std::cout << "    Student: " << student_id << "  Grade: " << grade << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "Test 13: Computing course averages." << std::endl;
    std::cout << "  Average for CSC 116 in 202201: " << db.compute_course_average("CSC 116", "202201") << std::endl;
    std::cout << "  Average for CSC 116 in 202209: " << db.compute_course_average("CSC 116", "202209") << std::endl;

    std::cout << "  Test 13a: Attempting to compute average for a course with no grades." << std::endl;
    try
    {
        auto av{db.compute_course_average("MATH 342", "202209")};
        std::cout << "    Average for MATH 342 in 202209: " << av << std::endl;
        std::cout << "    Did not catch EmptyAverageError: Behavior is incorrect" << std::endl;
    }
    catch (EmptyAverageError &e)
    {
        std::cout << "    Caught EmptyAverageError: Behaviour is correct." << std::endl;
    }

    return 0;
}
