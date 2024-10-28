#include <iostream>
#include <list>
#include <string>

/* element_at_index(L, idx)
   Return a reference to the element of the list L at
   the provided index. If the provided index is out of
   range, throw an instance of std::out_of_range.
*/
std::string &element_at_index(std::list<std::string> &L, unsigned int idx)
{
    unsigned int index = 0;
    // for (std::string &s : L)
    for (auto &s : L)
    {
        if (idx == index)
            return s;

        ++index;
    }
    throw std::out_of_range{"Invalid index"};
}

int main()
{
    std::list<std::string> fruit{};

    //Add two elements to the end
    fruit.push_back("Raspberry");
    fruit.push_back("Cranberry");

    //Add two elements to the beginning
    fruit.push_front("Pineapple");
    fruit.push_front("Strawberry");

    //Add another element to the end
    fruit.push_back("Pineapple");

    //Print out the elements of the list
    std::cout << "Part 1: ";
    for (auto s : fruit)
    {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    //Task: Print out the first and last elements,
    //      then delete them from the list.
    // *fruit.begin(); //ok but hugly
    // *fruit.end(); //not ok
    // *fruit.rbegin(); //ok but even mor hugly
    std::cout << fruit.front() << std::endl;
    std::cout << fruit.back() << std::endl;

    fruit.pop_front();
    fruit.pop_back();

    //Print out the elements of the list
    std::cout << "Part 2: ";
    for (auto s : fruit)
    {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    //Task: Insert the value "Pear" as the third
    //      element of the list (before "Cranberry")
    auto it = fruit.begin();
    ++it;
    ++it;
    fruit.insert(it, "Pear");

    std::cout << "Part 3: ";
    for (auto s : fruit)
    {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    //Task: Complete the element_at_index function
    //      above, then use it to print out the element
    //      at index 2 and modify the element at index
    //      3 to be "Guava".

    std::cout << "Element at index 2: " << element_at_index(fruit, 2) << std::endl;

    element_at_index(fruit, 3) = "Guava";

    std::cout << "Part 4: ";
    for (auto s : fruit)
    {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    std::cout << "Element at index 5: " << element_at_index(fruit, 5) << std::endl;

    return 0;
}
