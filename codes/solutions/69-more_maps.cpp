#include <iostream>
#include <map>
#include <string>

#include "stopwatch.hpp"

int main()
{
    //Various ways to add new elements to a map
    std::vector<int> bla{1, 1, 1};
    // bla.push_back(1);
    // bla.push_back(1);
    // bla.push_back(1);

    //Method 1: Add {key, value} pairs when creating the map
    std::map<std::string, unsigned int> fruit_ratings{
        {"Dragon fuit", 8},
        {"Chesnut", 9},
        {"Persimon", 0}};

    //Method 2: Use .insert to add {key, value} pair objects
    fruit_ratings.insert(std::pair<std::string, unsigned int>{"Cherry", 5});
    fruit_ratings.insert(std::make_pair("Mago", 9));
    fruit_ratings.insert({"Passionfruit", 10});

    //Method 3: Use the square bracket operator
    fruit_ratings["Pineapple"] = 6;
    fruit_ratings["Pumpkin"] = 10;
    //.at would not work

    for (const auto &[name, rating] : fruit_ratings)
    {
        std::cout << name << ": " << rating << "/10" << std::endl;
    }

    std::map<std::string, std::vector<int>> fruit_ratingss{
        {"Dragon fuit", {8, 8, 8}},
        {"Chesnut", {9}},
        {"Persimon", {0, 10}}};

    std::map<std::string, std::pair<int, double>> test{};
    std::map<std::vector<double>, Stopwatch> not_really_make_sense{
        {{1.0, 2.0, 3.0}, Stopwatch{}}, {{1.0, 2.0, 2.0}, Stopwatch{}}};

    not_really_make_sense.at({1.0, 2.0, 3.0});

    return 0;
}
