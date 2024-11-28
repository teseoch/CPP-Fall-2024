#include <iostream>
#include <string>
#include <vector>

template <typename T>
void print_vector(std::vector<T> const &V)
{
    for (auto x : V)
        std::cout << x << " ";
    std::cout << std::endl;
}

std::vector<float> convert_vector(std::vector<int> const &input)
{
    std::vector<float> result{};
    for (int x : input)
        result.push_back(x);
    return result;
}
std::vector<int> convert_vector(std::vector<float> const &input)
{
    std::vector<int> result{};
    for (float x : input)
        result.push_back(x);
    return result;
}
// Can't do this
/*
std::vector<unsigned int> convert_vector(std::vector<float> const & input){
    std::vector<unsigned int> result {};
    for(float x: input)
        result.push_back(x);
    return result;
}
*/

int main()
{

    std::vector<int> V1{-6, 10, 17};
    std::vector<float> V2{10.6, 11.6, 10.17};

    //Task: Create a vector IV2 containing the integer
    //      version of each element of V2.

    std::vector<int> IV2{};
    IV2 = convert_vector(V2);
    print_vector(IV2);

    //Task: Create vector UIV2 containing the unsigned
    //      int version of each element of V2

    /*
    std::vector<unsigned int> UIV2 {};
    // TO DO
    print_vector(UIV2);
    */

    return 0;
}
