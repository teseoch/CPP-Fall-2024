#include <iostream>
#include <vector> //Don't forget to include this every time you need to use vectors

int main()
{

    //Task 0: Create an empty vector V for integer elements
    std::vector< int > V{};

    //Task 1: Add the elements 6, 10, 17 to V (in that order)
    V.push_back(6); //0
    V.push_back(10);//1

    std::cout <<"the size of V is " << V.size() << std::endl;

    V.push_back(17); //2

    //Task 2: Print out the size of V

    std::cout <<"At the end the size is: " << V.size() << std::endl;
    //Task 3: Print out the element at index 1 of V
    std::cout << "The first element is " << V.at(0) << std::endl;
    std::cout << "The last element is " << V.at(2) << std::endl;
    size_t size{ V.size() };
    std::cout << "Better way is " << V.at(size - 1) << std::endl;
    //std::cout << "bla " << V.at(30) << std::endl;
    V.push_back(333);
    V.push_back(42);
    //Task 4: Iterate over V and print out each element.
    for (int value : V)
    {
        std::cout << "the value is " << value << std::endl;
    }

    //Task 5: Use an indexing loop (that is, a C-style for-loop) to iterate
    //        over each index of the vector. For each index, print the index
    //        and the element at that index.
    //        Note that the "natural" type for an index variable is "unsigned int".
    for (size_t i{ 0 }; i < V.size(); ++i)
    {
        std::cout << "the value at index " << i << " is " << V.at(i) << std::endl;
    }

    for (int i{ (int) V.size()-1}; i >= 0; --i)
    {
        std::cout << "the value at index " << i << " is "  << std::endl;
    }


    //Task 6: Add the value 187 to the end of V, then repeat steps 2-4 (by copying/pasting)

     unsigned int x{ 0 };
     std::cout << "unsigned " << x << std::endl;
     --x;
     std::cout << "unsigned " << x << std::endl;

    return 0;
}
