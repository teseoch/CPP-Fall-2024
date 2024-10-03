#include <iostream>

int main()
{
    //The "const" specifier is used to define constant values
    //(which can have a type and name just like variables).
    //The compiler will generate an error if you attempt to modify
    //a variable with the "const" specifier.
    const float PI{3.1415};

    int x{6};
    // std::cout << x << " " << y << std::endl;
    x = 10;
    // std::cout << x << " " << y << std::endl;

    return 0;
}