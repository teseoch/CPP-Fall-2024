#include <iostream>
#include <list>
#include <stdexcept>

/* list_sum_elementwise(L1, L2)
   Given two lists L1 and L2 of equal size, return a new list
   whose elements are the sum of the corresponding elements of L1 and L2.
   For example, with
     L1:   6   10   17
     L2: 116  187  111
   the result will be
         122  197  128

   If the two input lists do not have equal size, throw an instance
   of std::invalid_argument.
*/
std::list<int> list_sum_elementwise(std::list<int> const &L1, std::list<int> const &L2)
{
    // ???
}

int main()
{
    std::list<int> A{10, 20, 30, 40};
    std::list<int> B{6, 10, 17, 187};

    auto result = list_sum_elementwise(A, B);

    std::cout << "Result: ";
    for (auto x : result)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
