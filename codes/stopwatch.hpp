#pragma once

#include <chrono>

class Stopwatch
{
public:
    Stopwatch() = default;

    void start()
    {
        start_time = std::chrono::high_resolution_clock::now();
    }

    void stop()
    {
        end_time = std::chrono::high_resolution_clock::now();
    }

    double elapsed()
    {
        return std::chrono::duration<double>(end_time - start_time).count();
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
    std::chrono::time_point<std::chrono::high_resolution_clock> end_time;
};
