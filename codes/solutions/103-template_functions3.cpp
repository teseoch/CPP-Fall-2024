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

template <typename InputT, typename OutputT>
std::vector<OutputT> convert_vector(std::vector<InputT> const &input)
{
    std::vector<OutputT> result{};
    for (InputT x : input)
        result.push_back(x);
    return result;
}

// std::vector<int> convert_vector(std::vector<float> const &input)
// {
//     std::vector<int> result{};
//     for (float x : input)
//         result.push_back(x);
//     return result;
// }
// Can't do this
// std::vector<unsigned int> convert_vector_to_uint(std::vector<float> const &input)
// {
//     std::vector<unsigned int> result{};
//     for (float x : input)
//         result.push_back(x);
//     return result;
// }

int main()
{

    std::vector<int> V1{-6, 10, 17};
    std::vector<float> V2{10.6, 11.6, 10.17};
    std::vector<std::string> bla;

    //Task: Create a vector IV2 containing the integer
    //      version of each element of V2.

    std::vector<int> IV2{};
    IV2 = convert_vector<float, int>(V2);
    print_vector(IV2);

    //Task: Create vector UIV2 containing the unsigned
    //      int version of each element of V2

    std::vector<unsigned int> UIV2{};
    UIV2 = convert_vector<float, unsigned int>(V2);
    UIV2 = convert_vector<int, unsigned int>(V1);
    UIV2 = convert_vector<std::string, unsigned int>(bla);

    // TO DO
    print_vector(UIV2);

    return 0;
}
