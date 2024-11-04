#include <iostream>
#include <stdexcept>
#include <vector>
#include "stopwatch.hpp"

bool found_in_vector(const std::vector<unsigned int> &V, unsigned int element)
{
    for (auto x : V)
        if (x == element)
            return true;
    return false;
}

int main()
{

    Stopwatch BigS{};
    BigS.start();

    std::vector<unsigned int> V{};

    {
        Stopwatch S{};
        std::cout << "Inserting 25000 elements" << std::endl;
        S.start();
        for (unsigned int i = 0; i < 25000; i++)
            V.push_back(i * i);
        S.stop();
        std::cout << "Total time: " << S.elapsed() << " seconds" << std::endl;
    }

    {
        Stopwatch S{};
        std::cout << "Running 25000 valid lookups" << std::endl;
        S.start();
        for (unsigned int i = 0; i < 25000; i++)
        {
            if (!found_in_vector(V, i * i))
            {
                throw std::runtime_error{"Error with find()"};
            }
        }
        S.stop();
        std::cout << "Total time: " << S.elapsed() << " seconds" << std::endl;
    }

    {
        Stopwatch S{};
        std::cout << "Running 25000 invalid lookups" << std::endl;
        S.start();
        for (unsigned int i = 0; i < 25000; i++)
        {
            if (found_in_vector(V, i * i + 6))
            {
                throw std::runtime_error{"Error with find()"};
            }
        }
        S.stop();
        std::cout << "Total time: " << S.elapsed() << " seconds" << std::endl;
    }

    BigS.stop();
    std::cout << "Absolute total time: " << BigS.elapsed() << std::endl;

    return 0;
}
