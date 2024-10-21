#include <iostream>
#include <string>
#include <vector>

/* print_vector( V )
   Print out each element in a vector of ints, in forward order.
*/
void print_vector(std::vector<int> V)
{

    for (auto x : V)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Task: Rewrite this using an iterator instead of a for-each loop
}

/* print_reverse( V )
   Print out each element in a vector of ints, in reverse order.
*/
void print_reverse(std::vector<int> V)
{
    // Task: Write this without using indices
    std::cout << std::endl;
}

int main()
{
    std::vector<int> V{6, 8, 10, 17};

    std::cout << "Before : ";
    print_vector(V);

    auto iter = V.begin();

    std::cout << "Part 1: iter refers to " << *iter << std::endl;

    std::cout << "After: ";
    print_vector(V);

    std::cout << "In reverse: ";
    print_reverse(V);

    return 0;
}
