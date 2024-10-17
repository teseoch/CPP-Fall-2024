#include <iostream>
#include <utility>

struct Date
{
    int year;
    int month;
    int day;
};

void print_date(const Date &d)
{
    std::cout << "Date: " << d.year << "-" << d.month << "-" << d.day << std::endl;
}

int main()
{
    //Creating a struct out of data can be viewed as a way of
    //"packing" data together into a single object
    Date D1{2021, 12, 30};
    Date D2{2022, 6, 10};

    //C++ (starting with C++17) also supports "unpacking",
    //which extracts every element of a compound object and
    //assigns each value to a variable automatically.

    //In this example, y, m and d are created out of the year, month
    //and day members of D1 (and the type of each variable is deduced
    //based on the type of each member)
    auto [y, m, d] = D1;
    std::cout << "y = " << y << " m = " << m << " d = " << d << std::endl;

    //In the example, yr, mr, and dr are created as references to
    //the members of D2 (so changing yr will change the year member
    //of D2).
    auto &[yr, mr, dr] = D2;

    dr = 17;
    print_date(D2);

    return 0;
}
