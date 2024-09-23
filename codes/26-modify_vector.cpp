#include <iostream>
#include <vector>

/* print_vector( V )
   Print out each element in a vector of ints
*/
void print_vector(std::vector<int> V)
{
    for (auto x : V)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

/* add_ten(V)
   Given a vector of integers, add 10 to each element
   of the vector. (Needs to be fixed)
*/
void add_ten(std::vector<int> V)
{
    for (unsigned int i{0}; i < V.size(); i++)
    {
        V.at(i) += 10;
    }
}

int main()
{
    std::vector<int> V{6, 8, 10, 17};

    std::cout << "Before : ";
    print_vector(V);

    //Add 10 to each element in the vector
    add_ten(V);

    std::cout << "After: ";
    print_vector(V);

    return 0;
}
