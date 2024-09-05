#include <iostream>

int main()
{

    //Task 1: Create three variables with the names, types and initial values
    //        below. Use C-style initialization (i.e. assignment statements).
    //
    //        name |     type     | initial value
    //        -----+--------------+--------------
    //          i  |     int      |   -116
    //          j  | unsigned int |      6
    //          g  | double       | 10.187

    //Task 2: Once Task 1 is complete and tested, comment out the
    //        declarations above and rewrite them using uniform
    //        initialization syntax.

    //Task 3: What is the difference between an "uninitialized variable"
    //        and a variable which is declared with an empty uniform
    //        initializer?

    //Task 4: What happens if the wrong type is used inside the initializer?

    std::cout << "Values: ";
    std::cout << "i = " << i << ", ";
    std::cout << "j = " << j << ", ";
    std::cout << "g = " << g << std::endl;

    return 0;
}