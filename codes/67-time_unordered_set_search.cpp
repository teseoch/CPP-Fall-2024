#include <iostream>
#include <stdexcept>
#include <unordered_set>
#include "stopwatch.hpp"

bool found_in_set(const std::unordered_set<unsigned int> &S, unsigned int element)
{
    return S.contains(element);
}

int main()
{
    Stopwatch BigS{};
    BigS.start();

    std::unordered_set<unsigned int> V{};

    {
        Stopwatch S{};
        std::cout << "Inserting 25000 elements" << std::endl;
        S.start();
        for (unsigned int i = 0; i < 25000; i++)
            V.insert(i * i);
        S.stop();
        std::cout << "Total time: " << S.elapsed() << " seconds" << std::endl;
    }

    {
        Stopwatch S{};
        std::cout << "Running 25000 valid lookups" << std::endl;
        S.start();
        for (unsigned int i = 0; i < 25000; i++)
        {
            if (!found_in_set(V, i * i))
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
            if (found_in_set(V, i * i + 6))
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
