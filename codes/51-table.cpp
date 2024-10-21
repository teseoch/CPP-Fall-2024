#include <iostream>
#include <vector>

//The "using" directive defines a new type (similar to typedef in C)
//Note that type definitions are scoped (so a using directive inside a function
//will only be visible from inside that function).

int main()
{
    //Create table T of integer values with 3 rows and 5 columns.
    //Notice that the elements in the initializer for T
    //are initializers for one-dimensional vectors.
    //Note that "jagged" tables are possible (rows are not required to have the same size)
    std::vector<std::vector<int>> T{
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}};

    //Print the table with for-each loops
    // TO DO

    std::cout << std::endl;

    //Print the table with a traditional indexing loop
    // TO DO

    return 0;
}