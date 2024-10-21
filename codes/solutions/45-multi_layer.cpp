#include <iostream>
#include <stdexcept>

int F(int x)
{
    // try
    // {
    if (x > 10)
    {
        throw std::runtime_error{"Something bad happened."};
    }
    // }
    // catch (std::runtime_error &e)
    // {
    //     std::cout << "got it in f" << std::endl;
    // }
    return x * 10;
}

int G(int y)
{
    int result{0};
    // try
    // {
    try
    {
        while (y < 100)
        {
            result += F(y);

            y = 2 * y;
        }
    }
    catch (std::runtime_error &e)
    {
        std::cout << "got it in g" << std::endl;

        // std::invalid_argument ex{"i dont know what to do"};
        // throw ex;

        throw std::invalid_argument{"i dont know what to do"};
    }
    catch (std::invalid_argument &e)
    {
        std::cout << "invalid argument" << std::endl;
    }
    // }
    // catch (std::invalid_argument &e)
    // {
    //     std::cout << "invalid argument" << std::endl;
    // }
    return result;
}

int main()
{

    int y{999};
    y = G(6);

    std::cout << "y is " << y << std::endl;

    return 0;
}
