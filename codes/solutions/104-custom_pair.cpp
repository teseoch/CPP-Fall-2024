#include <iostream>
#include <string>

template <typename F, typename S>
class CustomPair
{
public:
    F first;
    S second;
};

template <typename F, typename S>
CustomPair<F, S> make_custom_pair(const F &f, const S &s)
{
    CustomPair<F, S> result{f, s};
    return result;
}

int main()
{
    // auto P = make_custom_pair(6, 10);
    // auto P = make_custom_pair<int, int>(6, 10);
    // CustomPair<int, int> P = make_custom_pair<int, int>(6, 10);
    // CustomPair<int, int> P = make_custom_pair(6, 10);

    // std::cout << "P.first: " << P.first << ", P.second: " << P.second << std::endl;
    // auto [a, b] = P;
    // std::cout << "a: " << a << ", b: " << b << std::endl;

    /* Task: Comment out the above and make the code below work instead.*/

    CustomPair<int, int> P = make_custom_pair(6, 10);

    std::cout << "P.first: " << P.first << ", P.second: " << P.second << std::endl;
    auto [a, b] = P;
    std::cout << "a: " << a << ", b: " << b << std::endl;

    std::string str{"Raspberry"};
    double g{10.6};
    // CustomPair<std::string, double> Q = make_custom_pair(str, g);
    auto Q = make_custom_pair(str, g);

    std::cout << "Q.first: " << Q.first << ", Q.second: " << Q.second << std::endl;
    auto [c, d] = Q;
    std::cout << "c: " << c << ", d: " << d << std::endl;

    return 0;
}