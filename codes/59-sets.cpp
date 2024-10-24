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

    /* Task 1: Print out the size */

    /* Task 2: Add the same element repeatedly and print the size again */

    /* Task 3: Try iterating over the set with a for-each loop */

    /* Task 4a: Search for the values "Lemon" and "Lime" using .contains */

    /* Task 4b: Search for the values "Lemon" and "Lime" using .count */

    /* Task 4c: Search for the values "Lemon" and "Lime" using .find */

    /* Task 5: Attempt to delete the values "Lemon" and "Grapefruit" */

    /* Task 6: Insert the values "Lime" and "Raspberry", using the return
               value of .insert to check whether the element was already
               present */

    return 0;
}
