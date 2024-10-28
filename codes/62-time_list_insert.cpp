#include <iostream>
#include <stdexcept>
#include <list>
#include "stopwatch.hpp"

int main()
{
    const int num_elements = 100000;

    Stopwatch S{};

    { //Create a new scope so that L is destroyed at the end of this test (and recreated for the next one)
        std::list<unsigned int> L{};
        std::cout << "Inserting " << num_elements << " elements (push_back)" << std::endl;
        S.start();
        for (unsigned int i = 0; i < num_elements; i++)
            L.push_back(i * i);
        S.stop();
        std::cout << "Total time: " << S.elapsed() << " seconds" << std::endl;
    }

    {
        std::list<unsigned int> L{};
        std::cout << "Inserting " << num_elements << " elements (insert() at end)" << std::endl;
        S.start();
        for (unsigned int i = 0; i < num_elements; i++)
            L.insert(L.end(), i * i);
        S.stop();
        std::cout << "Total time: " << S.elapsed() << " seconds" << std::endl;
    }

    {
        std::list<unsigned int> L{};
        std::cout << "Inserting " << num_elements << " elements (insert() at beginning)" << std::endl;
        S.start();
        for (unsigned int i = 0; i < num_elements; i++)
            L.insert(L.begin(), i * i);
        S.stop();
        std::cout << "Total time: " << S.elapsed() << " seconds" << std::endl;
    }

    return 0;
}
