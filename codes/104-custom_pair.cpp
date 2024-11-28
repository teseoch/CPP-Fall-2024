#include <iostream>
#include <string>

struct IntPair
{
    int first;
    int second;
};

IntPair make_int_pair(int j, int k)
{
    IntPair result{j, k};
    return result;
}

int main()
{
    IntPair P = make_int_pair(6, 10);

    std::cout << "P.first: " << P.first << ", P.second: " << P.second << std::endl;
    auto [a, b] = P;
    std::cout << "a: " << a << ", b: " << b << std::endl;

    /* Task: Comment out the above and make the code below work instead.

    CustomPair<int, int> P = make_custom_pair( 6, 10 );

    std::cout << "P.first: " << P.first << ", P.second: " << P.second << std::endl;
    auto [a, b] = P;
    std::cout << "a: " << a << ", b: " << b << std::endl;

    std::string str {"Raspberry"};
    double g {10.6};
    CustomPair<std::string, double> Q = make_custom_pair( str, g );

    std::cout << "Q.first: " << Q.first << ", Q.second: " << Q.second << std::endl;
    auto [c, d] = Q;
    std::cout << "c: " << c << ", d: " << d << std::endl;

    */

    return 0;
}