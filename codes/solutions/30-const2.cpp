#include <iostream>
#include <vector>

void print_vector(const std::vector<int> &V)
{
    // const int &bla{V.at(0)};
    // bla = 10;
    for (const auto &x : V)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> V{1, 2, 3, 4, 5};

    const std::vector<int> &V_ref{V};

    V.at(1) = 42;

    //Task: Try uncommenting the line below. What happens?
    // V_ref.at(2) = 100;

    print_vector(V);
    print_vector(V_ref);

    return 0;
}