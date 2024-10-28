#include <iostream>
#include <map>
#include <string>
#include <utility>

int main()
{

    std::map<std::string, std::string> the_weather{};
    the_weather.insert({"Victoria", "Rainy"});
    the_weather.insert({"Vancouver", "Rainy"});
    the_weather.insert({"Duncan", "Overcast"});
    the_weather.insert({"Campbell River", "Foggy"});

    std::cout << "Part 1" << std::endl;

    std::cout << "In Victoria, it is " << the_weather["Victoria"] << std::endl;
    std::cout << "In Nanaimo, it is " << the_weather["Nanaimo"] << std::endl;

    std::cout << "Part 2" << std::endl;
    for (auto [city, conditions] : the_weather)
    {
        std::cout << "In " << city << ", conditions are " << conditions << std::endl;
    }

    return 0;
}