#include <iostream>
#include <string>
#include <vector>

/* contains(vec, search_element)
   Given a vector of integers and an element to search for, return
   true if the element is found anywhere in the vector and false
   otherwise.
*/
bool contains(std::vector<int> const &vec, int search_element)
{
    for (auto x : vec)
    {
        if (x == search_element)
        {
            return true;
        }
    }
    return false;
}

/* contains(vec, search_element)
   Given a vector of strings and an element to search for, return
   true if the element is found anywhere in the vector and false
   otherwise.
*/
bool contains(std::vector<std::string> const &vec, std::string search_element)
{
    for (auto x : vec)
    {
        if (x == search_element)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    std::vector<std::string> V{"Raspberry", "Pineapple", "Pear"};
    std::vector<int> W{6, 10, 17};

    if (contains(V, "Pear"))
    {
        std::cout << "V contains \"Pear\"" << std::endl;
    }
    else
    {
        std::cout << "V does not contain \"Pear\"" << std::endl;
    }
    if (contains(V, "Grapefruit"))
    {
        std::cout << "V contains \"Grapefruit\"" << std::endl;
    }
    else
    {
        std::cout << "V does not contain \"Grapefruit\"" << std::endl;
    }

    if (contains(W, 6))
    {
        std::cout << "W contains 6" << std::endl;
    }
    else
    {
        std::cout << "W does not contain 6" << std::endl;
    }
    if (contains(W, 187))
    {
        std::cout << "W contains 187" << std::endl;
    }
    else
    {
        std::cout << "W does not contain 187" << std::endl;
    }
    return 0;
}
