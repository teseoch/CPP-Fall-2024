#include <iostream>

struct Point
{
    int x{0};
    int y{0};
};

void print_point(Point pt)
{
    std::cout << "(" << pt.x << ", " << pt.y << ")" << std::endl;
}

int main()
{

    Point P{6, 10};

    Point Q{};
    Q.x = 17;
    Q.y = 187;

    Point R{};
    R = Q;

    std::cout << "P = ";
    print_point(P);
    std::cout << "Q = ";
    print_point(Q);
    std::cout << "R = ";
    print_point(R);
    return 0;
}
