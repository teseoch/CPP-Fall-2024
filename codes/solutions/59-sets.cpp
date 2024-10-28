#include <iostream>
#include <set>
#include <string>

int main()
{
    std::set<std::string> fruit{};

    /* Add some elements to the set */
    fruit.insert("Raspberry");
    fruit.insert("Pear");
    fruit.insert("Cranberry");
    fruit.insert("Strawberry");
    fruit.insert("Pineapple");
    fruit.insert("Guava");
    fruit.insert("Lemon");
    fruit.insert("Orange");
    fruit.insert("Apple");

    /* Task 1: Print out the size */
    std::cout << fruit.size() << std::endl;

    // a < b

    /* Task 2: Add the same element repeatedly and print the size again */
    fruit.insert("Apple");
    fruit.insert("Apple");
    fruit.insert("Apple");
    fruit.insert("Apple");
    fruit.insert("Apple");

    std::cout << fruit.size() << std::endl;

    /* Task 3: Try iterating over the set with a for-each loop */
    for (const auto &f : fruit)
    {
        std::cout << f << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    /* Task 4a: Search for the values "Lemon" and "Lime" using .contains */
    if (fruit.contains("Lemon"))
    {
        std::cout << "lemon is there" << std::endl;
    }
    else
    {
        std::cout << "lemon is not there" << std::endl;
    }
    if (fruit.contains("Lime"))
    {
        std::cout << "Lime is there" << std::endl;
    }
    else
    {
        std::cout << "Lime is not there" << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    /* Task 4b: Search for the values "Lemon" and "Lime" using .count */
    if (fruit.count("Lemon") == 1)
    {
        std::cout << "lemon is there" << std::endl;
    }
    else
    {
        std::cout << "lemon is not there" << std::endl;
    }
    if (fruit.count("Lime") == 1)
    {
        std::cout << "Lime is there" << std::endl;
    }
    else
    {
        std::cout << "Lime is not there " << fruit.count("Lime") << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    /* Task 4c: Search for the values "Lemon" and "Lime" using .find */
    if (fruit.find("Lemon") != fruit.end())
    {
        std::cout << "lemon is there" << std::endl;
    }
    else
    {
        std::cout << "lemon is not there" << std::endl;
    }
    if (fruit.find("Lime") != fruit.end())
    {
        std::cout << "Lime is there" << std::endl;
    }
    else
    {
        std::cout << "Lime is not there" << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    /* Task 5: Attempt to delete the values "Lemon" and "Grapefruit" */
    std::cout << "deleted " << fruit.erase("Lemon") << " Lemons" << std::endl;
    std::cout << "deleted " << fruit.erase("Grapefruit") << " Grapefruits" << std::endl;

    for (const auto &f : fruit)
    {
        std::cout << f << " ";
    }
    std::cout << std::endl;

    /* Task 6: Insert the values "Lime" and "Raspberry", using the return
               value of .insert to check whether the element was already
               present */
    // auto pair = fruit.insert("Lime");
    // auto it1 = pair.first;
    // auto bool1 = pair.second;
    auto [it1, bool1] = fruit.insert("Lime");
    auto [it2, bool2] = fruit.insert("Raspberry");

    // std::cout << "Lime was succesfull? " << bool1 << std::endl;
    // std::cout << "Raspberry was succesfull? " << bool2 << std::endl;

    std::cout << *it1 << " was succesfull? " << bool1 << std::endl;
    std::cout << *it2 << " was succesfull? " << bool2 << std::endl;

    return 0;
}
