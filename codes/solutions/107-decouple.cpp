#include <iostream>
#include <vector>
#include <functional>

/* Task: condense the "all" and "any" functions into
a generic all_of and any_of function which take a condition as argument*/
bool is_positive(int x)
{
    return x > 0;
}

bool is_even(int x)
{
    return x % 2 == 0;
}

bool is_zero(int x)
{
    return x == 0;
}

template <typename T>
bool all_of(const std::vector<T> &V, const std::function<bool(T)> &condition)
{
    for (const T &v : V)
    {
        //if (condition(v) == false)
        if (!condition(v))
            return false;
    }

    return true;
}

template <typename T>
bool any_of(const std::vector<T> &V, const std::function<bool(T)> &condition)
{
    for (const T &v : V)
    {
        //if (condition(v) == true)
        if (condition(v))
            return true;
    }

    return false;
}

void print_results(std::vector<int> const &V)
{
    std::cout << "all_even = " << all_of<int>(V, is_even);
    std::cout << ", all_positive = " << all_of<int>(V, is_positive);
    std::cout << ", all_zero = " << all_of<int>(V, is_zero);
    std::cout << ", any_even = " << any_of<int>(V, is_even);
    std::cout << ", any_positive = " << any_of<int>(V, is_positive);
    std::cout << ", any_zero = " << any_of<int>(V, is_zero);
    std::cout << std::endl;
}

bool is_long(const std::string &s)
{
    return s.length() > 3;
}

int main()
{
    std::vector<int> V0{0, 0, 0, 0};
    std::vector<int> V1{0, 2, 4, 6, 8, 10};
    std::vector<int> V2{-2, -4, 0, 6, 10};
    std::vector<int> V3{6, 10, 17, 187};

    std::cout << "V0: ";
    print_results(V0);

    std::cout << "V1: ";
    print_results(V1);

    std::cout << "V2: ";
    print_results(V2);

    std::cout << "V3: ";
    print_results(V3);

    std::vector<std::string> Vs1{"Raspberry", "Pear", "Pineapple"};
    std::vector<std::string> Vs2{"pear", "peach", "lemon"};

    std::cout << all_of<std::string>(Vs1, is_long) << std::endl;

    return 0;
}

// /* all_even: Return true if every element of the provided
//          vector is an even number. */
// bool all_even(std::vector<int> const &V)
// {
//     for (auto x : V)
//         if (x % 2 != 0) //If the element is not even, return false.
//             return false;
//     return true;
// }

// /* all_positive: Return true if every element of the provided
//          vector is a positive number. */
// bool all_positive(std::vector<int> const &V)
// {
//     for (auto x : V)
//         if (x <= 0) //If the element is zero or negative, return false.
//             return false;
//     return true;
// }

// /* all_zero: Return true if every element of the provided
//          vector is zero. */
// bool all_zero(std::vector<int> const &V)
// {
//     for (auto x : V)
//         if (x != 0) //If the element is not zero, return false.
//             return false;
//     return true;
// }

// /* any_even: Return true if any element of the provided
//          vector is an even number. */
// bool any_even(std::vector<int> const &V)
// {
//     for (auto x : V)
//         if (x % 2 == 0) //If the element is even, return true.
//             return true;
//     return false;
// }

// /* any_positive: Return true if any element of the provided
//          vector is a positive number. */
// bool any_positive(std::vector<int> const &V)
// {
//     for (auto x : V)
//         if (x > 0) //If the element is positive, return true.
//             return true;
//     return false;
// }

// /* any_zero: Return true if any element of the provided
//          vector is zero. */
// bool any_zero(std::vector<int> const &V)
// {
//     for (auto x : V)
//         if (x == 0) //If the element is zero, return true.
//             return true;
//     return false;
// }