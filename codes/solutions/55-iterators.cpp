#include <iostream>
#include <string>
#include <vector>

/* print_vector( V )
   Print out each element in a vector of ints, in forward order.
*/
void print_vector(const std::vector<int> &V)
{
    // for (auto x : V)
    // {
    //     std::cout << x << " ";
    // }
    // std::cout << std::endl;

    // Task: Rewrite this using an iterator instead of a for-each loop
    for (auto it{V.begin()}; it != V.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

/* print_reverse( V )
   Print out each element in a vector of ints, in reverse order.
*/
void print_reverse(std::vector<int> V)
{
    // for (int i = 0; i < V.size(); ++i)
    // {
    //     //bla
    // }
    // for (int i = V.size() - 1; i >= 0; --i)
    // {
    //     //bla
    // }
    // // auto it{V.end()};

    // Task: Write this without using indices
    for (auto it{V.rbegin()}; it != V.rend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> V{6, 8, 10, 17};

    std::cout << "Before : ";
    print_vector(V);

    auto iter = V.begin(); //not a pointer, but an iterator

    std::cout << "Part 1: iter refers to " << *iter << std::endl;

    ++iter;
    iter++;
    std::cout << "Part 2: iter refers to " << *iter << std::endl;

    *iter = 42;
    std::cout << "Part 3: iter refers to " << *iter << std::endl;

    std::cout << "After: ";
    print_vector(V);

    std::cout << "In reverse: ";
    print_reverse(V);

    return 0;
}
