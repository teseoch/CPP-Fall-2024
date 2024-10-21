#include <iostream>
#include <vector>

//The "using" directive defines a new type (similar to typedef in C)
//Note that type definitions are scoped (so a using directive inside a function
//will only be visible from inside that function).
using Table = std::vector<std::vector<int>>;

void print(const Table &table)
{
    for (const auto &row : table)
    // for (const std::vector<int> &row : table)
    {
        for (auto value : row)
        // for (int value : row)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    //Create table T of integer values with 3 rows and 5 columns.
    //Notice that the elements in the initializer for T
    //are initializers for one-dimensional vectors.
    //Note that "jagged" tables are possible (rows are not required to have the same size)
    Table T{
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}};

    //Print the table with for-each loops
    print(T);

    std::cout << std::endl;

    //Print the table with a traditional indexing loop
    // for (size_t i{0}; i < T.size(); ++i)
    // {
    //     for (size_t j{0}; j < T.at(i).size(); ++j)
    //     {
    //         std::cout << T.at(i).at(j) << "  ";
    //         std::cout << T[i][j] << "  ";
    //     }
    //     std::cout << std::endl;
    // }
    for (size_t i{0}; i < T.size(); ++i)
    {
        const auto &row = T.at(i);

        for (size_t j{0}; j < row.size(); ++j)
        {
            std::cout << row.at(j) << "  ";
        }
        std::cout << std::endl;
    }

    return 0;
}