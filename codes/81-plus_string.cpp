#include <string>
#include <iostream>

std::string string_plus_string(const std::string &s1, const std::string &s2)
{
    std::string res{};

    for (auto c : s1)
    {
        res.push_back(c);
    }

    for (auto c : s2)
    {
        res.push_back(c);
    }

    return res;
}

std::string string_plus_float(const std::string &s, float v)
{
    std::string res{};
    std::string vstring{std::to_string(v)};

    for (auto c : s)
    {
        res.push_back(c);
    }

    for (auto c : vstring)
    {
        res.push_back(c);
    }
    return res;
}

std::string string_plus_int(const std::string &s, int i)
{
    std::string res{};
    std::string istring{std::to_string(i)};

    for (auto c : s)
    {
        res.push_back(c);
    }

    for (auto c : istring)
    {
        res.push_back(c);
    }
    return res;
}

int main()
{

    std::string A{"Hello"};
    std::string B{"World"};

    int x{42};
    float y{3.14};

    std::cout << "A plus B: " << string_plus_string(A, B) << std::endl;
    std::cout << "A plus x: " << string_plus_int(A, x) << std::endl;
    std::cout << "A plus y: " << string_plus_float(A, y) << std::endl;

    std::string res{};
    /*Task: make the following work*/
    // res = s + x;

    return 0;
}