#include <iostream>
#include <vector>

int main()
{
    //Task 1: Create a vector W of element type float containing the sequence
    //        10.6, 1.87, 11.1, 11.6, 4.45
    std::vector<float> W{ 10.6, 1.87, 11.1, 11.6, 4.45 };

    //Task 2: Print the contents of the vector on one line.
    //        (Challenge exercise for later: Print commas between each element, but not after the last element)
    for (float v : W)
        std::cout << v << " ";
    std::cout << std::endl;

    //Task 3: Modify the element at index 1 to equal 999.
    //        Weigh the benefits of the .at() function versus square brackets.
    W.at(1) = 999;
    //W[1] = 999;

    for (float v : W)
        std::cout << v << " ";
    std::cout << std::endl;


    //Task 4: Copy/paste the loop from task 2 to print the vector again.

    return 0;
}
