#include <iostream>
#include <stdexcept>
#include <set>

class Point;                                                            //Class declaration
std::ostream &operator<<(std::ostream &output_stream, const Point &pt); //Operator declaration

class Point
{
public:
    Point(double x_val, double y_val) : x{x_val}, y{y_val}
    {
        std::cout << "Constructor for " << *this << std::endl;
    }

    Point() : Point{0, 0} //The default constructor defers to the two-argument constructor.
    {
    }

    ~Point()
    {
        const Point &p = *this;

        std::cout << "Destructor for " << p << std::endl;
    }

    /* Copy constructor */
    /* Used in all cases where a new Point is being created as a copy of an existing,
       non-temporary Point object. */
    /* If not explicitly provided, the compiler will provide a default version that
       performs a shallow copy. */
    Point(const Point &other_pt)
    {
        std::cout << "Copy constructor. Copying " << other_pt << std::endl;
        x = other_pt.x;
        y = other_pt.y;
    }

    /* Copy assignment operator */
    /* Used for assignments of the form "X = Y" where X is an already-constructed
       Point object and Y is a non-temporary object (that would not otherwise be
       immediately destroyed). */
    Point &operator=(const Point &other_pt)
    {
        std::cout << "Copy assignment operator. Copying " << other_pt << std::endl;
        x = other_pt.x;
        y = other_pt.y;
        return *this;
    }

    /* Move constructor */
    /* Used in all cases where a new Point is being created as a copy of an existing,
       non-temporary Point object. */
    /* If not explicitly provided, the compiler will provide a default version that
       performs a shallow (renaming-style) move. */
    Point(const Point &&other_pt)
    {
        std::cout << "Move constructor. Moving " << other_pt << std::endl;
        x = other_pt.x;
        y = other_pt.y;
    }

    /* Move assignment operator */
    /* Used for assignments of the form "X = Y" where X is an already-constructed
       Point object and Y is a temporary object (that would not otherwise be
       immediately destroyed). */
    Point &operator=(Point const &&other_pt)
    {
        std::cout << "Move assignment operator. Moving " << other_pt << std::endl;
        x = other_pt.x;
        y = other_pt.y;
        return *this;
    }

    double get_x() const
    {
        return x;
    }
    double get_y() const
    {
        return y;
    }

private:
    double x, y;
};

std::ostream &operator<<(std::ostream &output_stream, const Point &pt)
{
    output_stream << "(" << pt.get_x() << "%" << pt.get_y() << ")";
    return output_stream;
}

//Notice how this function returns a Point object that is a "copy"
//of a local variable that is immediately destroyed after the return.
Point make_a_point(double x, double y)
{
    Point a_point{x, y};
    return a_point;
}

void make_a_point(double x, double y, Point &p)
{
    p = Point{x, y};
}

int main()
{

    //Create two points with the ordinary constructors
    Point P{6, 17};
    Point Q{10, 187};

    std::cout << "Part A" << std::endl;
    Point A{P}; //Directly invoke copy constructor

    std::cout << "Part B" << std::endl;
    Point B = P; //Copy via initialization assignment

    std::cout << "Part C" << std::endl;
    Q = P; //Copy without construction (P and Q already exist)

    //Note: The behaviors demonstrated below this line are technical and above the
    //      level of CSC 116 (so they won't appear on exams). It might be helpful to
    //      have some idea that these occur, though (which is why they are present).

    std::cout << "Part D" << std::endl;

    //Call the make_a_point function which creates a local variable of type Point
    //and returns it. The return value is assigned to D, and the original local variable
    //in the function is destroyed. Therefore, arguably the variable D is just the original
    //local variable with a new name (it is not necessary to actually copy the local variable
    //into D). The compiler has two options here:
    // - Call the move constructor to "move" the return value into D
    // - Silently set D to _be_ the return value, thereby extending its lifespan (so the local
    //   variable a_point in make_a_point is not destructed yet, since it is now called D and
    //   has been re-scoped into main). Most modern compilers will take this option (copy elision).
    Point D{make_a_point(-999, -888)};

    std::cout << "Part E" << std::endl;
    Point E;
    //As above, the result of make_a_point is a local variable that would otherwise be immediately
    //destroyed. In this case, we can't silently rescope the local variable into this scope, since
    //it is being assigned to an existing variable E (so there might be extra work needed to
    //accomplish the move). In this case, the move assignment operator is called and the local
    //variable that was returned is destructed as usual.
    E = make_a_point(-10, -20);

    std::cout << "Part F" << std::endl;

    return 0;
}
