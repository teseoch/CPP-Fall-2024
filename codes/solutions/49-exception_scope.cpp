#include <iostream>
#include <stdexcept>

int F(int start, int end)
{

    int total{0};
    try
    {
        if (start < 1)
            throw std::runtime_error{"Start value too small"};
        for (int i{start}; i <= end; i++)
        {
            try
            {
                if (i > 5)
                    throw std::domain_error{"Too big"};
                total += i;
            }
            catch (std::domain_error &e)
            {
                std::cout << "F: Caught domain_error" << std::endl;
                //Question: What happens if the following line is uncommented?
                //throw std::domain_error("Uh oh");
            }
        }
    }
    catch (std::runtime_error &e)
    {
        std::cout << "F: Caught runtime_error" << std::endl;
        return 1000;
    }
    return total;
}

int main()
{
    std::cout << "main (1)" << std::endl;
    int sum{1000};
    try
    {
        sum = F(2, 4);
        std::cout << "main (2): sum = " << sum << std::endl;
        sum = F(3, 6);
        std::cout << "main (3): sum = " << sum << std::endl;
    }
    catch (std::domain_error &e)
    {
        std::cout << "main: Caught domain_error" << std::endl;
    }
    catch (std::runtime_error &e)
    {
        std::cout << "main: Caught runtime_error" << std::endl;
    }
    catch (...)
    {
        std::cout << "main: Caught something?" << std::endl;
    }
    std::cout << "main (4)" << std::endl;
    std::cout << "sum = " << sum << std::endl;
    return 0;
}
