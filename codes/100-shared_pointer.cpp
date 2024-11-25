#include <iostream>
#include <memory>

class Fruit
{
public:
    Fruit(std::string the_name) : name{the_name}
    {
        std::cout << "Fruit constructor: " << name << std::endl;
    }
    ~Fruit()
    {
        std::cout << "Fruit destructor: " << name << std::endl;
    }

private:
    std::string name;
};

Fruit *make_thing()
{
    Fruit *Y = new Fruit("Raspberry");
    Fruit *Z = new Fruit("Pineapple");
    return Y;
}

int main()
{
    std::cout << "main (1)" << std::endl;
    /* Task 1: Modify the statement below to use a smart pointer instead of raw
               dynamic allocation. */
    Fruit *A = new Fruit{"Pear"};

    std::cout << "main (2)" << std::endl;
    /* Task 2: Try out the following statement (which would cause a memory leak
               using normal dynamic allocation). */
    //A = nullptr;
    std::cout << "main (3)" << std::endl;
    /* Task 3: Comment out Task 2 and try reassigning A to point at a new Fruit
               object with the name "Grapefruit" instead. */

    std::cout << "main (4)" << std::endl;
    /* Task 4a: Create another smart pointer B and set it equal to A.

    /* Task 4b: Call the make_thing() function above and assign its return value to A. */

    std::cout << "main (5)" << std::endl;
    return 0;
}
