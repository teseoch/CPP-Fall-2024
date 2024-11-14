#include <iostream>
#include <stdexcept>
#include <set>

class Point; //Class declaration
void print_point(Point const &pt);

class Point
{
public:
    Point(double x, double y)
    {
        //Task: Below this line, initialize the two members of this object
        //      to be the provided values of x and y. You aren't allowed to
        //      change the names of the parameters in the signature on line 17,
        //      and don't try any funny business either (just write some assignment statements).
    }
    Point() : Point{0, 0}
    { //The default constructor defers to the two-argument constructor.
    }
    double get_x() const
    {
        return x;
    }
    double get_y() const
    {
        return y;
    }
    void print() const
    {
        //Task: Instead of printing anything here, call the print_point function
        //      with the current Point instance to print it out.
    }

private:
    double x{};
    double y{};
};

void print_point(Point const &pt)
{
    std::cout << "print_point: (" << pt.get_x() << ", " << pt.get_y() << ")" << std::endl;
}

int main()
{

    Point P{6, 17};
    Point Q{10, 187};

    std::cout << "Calling print_point on P" << std::endl;
    print_point(P);

    std::cout << "Calling Q.print()" << std::endl;
    Q.print();

    return 0;
}
