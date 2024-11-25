#include <iostream>
#include <stdexcept>
#include <string>

class Rectangle
{
public:
    Rectangle()
    {
        width = 0;
        height = 0;

        name = "Private dont touch me";
    }
    Rectangle(double initial_width, double initial_height)
    {
        width = initial_width;
        height = initial_height;

        name = "Private dont touch me";
    }

    void set_width(double w)
    {
        width = w;
    }

    double get_width()
    {
        return width;
    }
    double get_height()
    {
        return height;
    }
    double get_area()
    {
        return get_width() * get_height();
    }

protected:
    double width;
    double height;

private:
    std::string name;
    friend std::ostream &operator<<(std::ostream &stream, Rectangle &R);
};

//An operator to allow Rectangle objects to be output directly into streams.
std::ostream &operator<<(std::ostream &stream, Rectangle &R)
{
    stream << "Rectangle: " << R.get_width() << " x " << R.get_height();
    stream << " (area = " << R.get_area() << ")";
    stream << " (name = " << R.name << ")";
    return stream;
}

class Square : public Rectangle
{
public:
    Square(double side_length)
    {
        width = side_length;
        height = side_length;

        // name = "hehe i am touching";
    }

    void change_side_length(double side_length)
    {
        width = side_length;
        height = side_length;
    }
    double get_side_length()
    {
        return width;
    }
};

int main()
{

    Rectangle R{6, 10};
    Square S{10};

    std::cout << R << std::endl;

    /* Task: Make the code below work for Squares by
             defining a Square to be a specialization
             of Rectangle.*/
    std::cout << S << std::endl;

    std::cout << "Area of S: " << S.get_area() << std::endl;
    std::cout << "Side length of S: " << S.get_side_length() << std::endl;

    S.change_side_length(2);

    // S.set_width(4);

    std::cout << S << std::endl;
    std::cout << "Area of S: " << S.get_area() << std::endl;
    std::cout << "Side length of S: " << S.get_side_length() << std::endl;

    return 0;
}
