# Overview

This assignment aims to complete the implementation of a class called `StudentDB`, which maintains records of students and courses, including which students are enrolled in which courses and what grades have been assigned. The class also provides functionality to compute the average grade across all of a student's courses or those enrolled in a particular course.

Each `StudentDB` instance functions as a database that stores data (added by calling functions like `add_student` and enroll) and can provide various views on the data by calling its member functions. For example, the `student_transcript_by_course` can be used to retrieve a record of courses taken by a student and the best grade received among all the times the student took each course.

The `StudentDB` object will keep track of enrollments (where a student has registered for a particular course for a specific term) and assigned grades. Sometimes, a student may be enrolled in a course without being assigned a grade. A specific course may be oﬀered in multiple terms (and have a distinct set of students each term). Students may enroll in the same course in multiple
terms (and may receive a separate grade for each enrollment).

The file `assignment_3.cpp` contains the specification of the `StudentDB` class, each required public member function, and empty placeholders for each member function. You must implement all member functions and add private members to the class definition in `assignment_3.cpp` as needed. You are not permitted to modify any provided function signatures or add other public members to the `StudentDB` class beyond those provided.

**Important**: Testing your implementation is your responsibility, but a basic tester program has been provided in the `main` function to get you started. When your code is tested, shorter purpose-built testers will be used for each test case instead of a single long test program. You may modify the `main` function for your own testing, but you must ensure that your code compiles against the unmodified `main` function before submitting.

## Implementation Advice

Many of the required member functions have significant overlap in their expected behaviour. If you implement each function to call other member functions if needed, you can save a large amount of redundant work.

For example, the `courses_taken_by_student` function is relatively simple to implement if it calls the `get_student_enrollment_records` function. The two functions to compute averages are much more straightforward if written to call other functions to gather their data before computing the average.

## Task (50pt)

Implement all necessary functions.


## Code Requirements

- You must ensure that your code compiles against the unmodified version of the `main` function before submitting.
- The goto statement is not permitted in any assignment submissions.
- Global variables (data variables created outside of the scope of a function) are not permitted,
- Every function with a non-void return type must return a value.

### Ouput for the provide `main` function

```bash
Test 1: Adding some students
  Test 1a: Attempting to create a duplicate student
    Caught DBDuplicateError: Behaviour is correct.

Test 2: Retrieving student list.
  Students are: V00123456 V00123457 V00123458

Test 3: Enrolling students in courses.
  Test 3a: Attempting to enroll an invalid student.
    Caught StudentNotFoundError (V00999999): Behaviour is correct.
  Test 3b: Attempting a duplicate enrollment.
    Caught DBDuplicateError: Behaviour is correct.

Test 4: Retrieving enrollment records.
  For V00123456:
    Course: CSC 116  Term: 202209
    Course: MATH 204  Term: 202209
    Course: MECH 200  Term: 202209
  For V00123457:
    Course: CSC 116  Term: 202201
    Course: CSC 116  Term: 202209
    Course: MATH 204  Term: 202209

Test 5: Retrieving courses taken by students.
  For V00123456: CSC 116 MATH 204 MECH 200
  For V00123457: CSC 116 MATH 204

Test 6: Adding more students and enrollments

Test 7: Assigning some grades
  Test 7a: Attempting to grade an invalid student.
    Caught StudentNotFoundError (V00999999): Behaviour is correct.
  Test 7b: Attempting to grade an unenrolled student.
    Caught EnrollmentNotFoundError (V00123458, CSC 116, 202209): Behaviour is correct.
  Test 7c: Attempting to assign an invalid grade.
    Caught InvalidGradeError (187): Behaviour is correct.

Test 8: Retrieving student grades.
  Grade for V00123456 in CSC 116 in 202209: 67
  Grade for V00123457 in CSC 116 in 202201: 93
  Grade for V00123457 in CSC 116 in 202209: 87
  Test 8a: Attempting to retrieve a grade for an unenrolled student.
   Caught EnrollmentNotFoundError (V00123458, CSC 116, 202209): Behaviour is correct.
  Test 8b: Attempting to retrieve an unassigned grade.
    Caught MissingGradeError: Behaviour is correct.

Test 9: Retrieving transcripts.
  For V00123456:
    Course: CSC 116  Grade: 67
    Course: MATH 204  Grade: 92
    Course: MECH 200  Grade: 85
  For V00123457:
    Course: CSC 116  Grade: 93
  For V00123458: Transcript is empty: Behaviour is correct.

Test 10: Computing student averages.
  Average for V00123456: 81.3333
  Average for V00123457: 93
  Test 10a: Attempting to compute average for a student with no grades.
    Caught EmptyAverageError: Behaviour is correct.

Test 11: Retrieving enrollment by course.
  For CSC 116 in 202201: V00123457 V00123458
  For CSC 116 in 202209: V00123456 V00123457 V00123459
  For MATH 204 in 202209: V00123456 V00123457 V00123460

Test 12: Retrieving grades by course.
  For CSC 116 in 202201:
    Student: V00123457  Grade: 93
  For CSC 116 in 202209:
    Student: V00123456  Grade: 67
    Student: V00123457  Grade: 87
    Student: V00123459  Grade: 78
  For MATH 204 in 202209:
    Student: V00123456  Grade: 92
    Student: V00123460  Grade: 90

Test 13: Computing course averages.
  Average for CSC 116 in 202201: 93
  Average for CSC 116 in 202209: 77.3333
  Test 13a: Attempting to compute average for a course with no grades.
    Caught EmptyAverageError: Behaviour is correct.
```