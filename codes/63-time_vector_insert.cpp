#include <iostream>
#include <stdexcept>
#include <vector>
#include "stopwatch.hpp"

int main()
{
    const int num_elements = 100000;

    Stopwatch S{};

    { //Create a new scope so that V is destroyed at the end of this test (and recreated for the next one)
        std::vector<unsigned int> V{};
        std::cout << "Inserting " << num_elements << " elements (push_back)" << std::endl;
        S.start();
        for (unsigned int i = 0; i < num_elements; i++)
            V.push_back(i * i);
        S.stop();
        std::cout << "Total time: " << S.elapsed() << " seconds" << std::endl;
    }

    {
        std::vector<unsigned int> V{};
        std::cout << "Inserting " << num_elements << " elements (insert() at end)" << std::endl;
        S.start();
        for (unsigned int i = 0; i < num_elements; i++)
            V.insert(V.end(), i * i);
        S.stop();
        std::cout << "Total time: " << S.elapsed() << " seconds" << std::endl;
    }

    {
        std::vector<unsigned int> V{};
        std::cout << "Inserting " << num_elements << " elements (insert() at beginning)" << std::endl;
        S.start();
        for (unsigned int i = 0; i < num_elements; i++)
            V.insert(V.begin(), i * i);
        S.stop();
        std::cout << "Total time: " << S.elapsed() << " seconds" << std::endl;
    }

    return 0;
}
