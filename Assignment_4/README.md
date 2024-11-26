# Assignment 4 - BONUS


## Exercise 1 (7 points)

Implement the `Point2d` class that contains:

- The `x` and `y` coordinates
- The minus operator
- The plus operator
- The operator `[]` as a getter and setter
- A function `norm()` that returns `sqrt(x*x - y*y)`
- allows to be printed by `cout`
- `==` operator

Implement the `GeometricObject` class, it should provide:

- The a `Point2d` for the position of the center
- An empty constructor that initializes the position at 0,0
- A constructor that takes a `Point2d` as position
- The getters and setters for all fields
- A function `get_perimeter()` that returns the perimeter
- A function `contains(p)` that checks if a `Point2d` is inside
- allows to be printed by `cout`
- `==` operator

Implement also 2 subclasses (add all necessary fields and functions): `Circle` and  `Rectangle`

To check containment inside a circle, you must check if `||p - c||<r` where `p` is the query point, `c` is the center, and `r` is the radius.

To check containment inside a rectangle, you need to check whether the query point `p` x and y coordinates are within the rectangle's lower and upper bounds.



## Exercise 2 (7 points)

Write the `Complex` number class.
The conversion

It should provide

- An empty constructor (initialize the number to 0)
- A constructor with one parameter (real number)
- A constructor with 2 parameters (real and imaginary parts)
- `re()` that returns the real part
- `im()` that returns the imaginary part
- `conjugate()` that returns the complex conjugate
- conversion to double as the real part.
- addition, subtraction, and multiplication, with complex numbers or doubles using operators (see [wikipedia](https://en.wikipedia.org/wiki/Complex_number#Elementary_operations))
- allows to be printed by `cout`
- `==` operator


## Exercise 3 (5 points)

Implement the `Stack` of int class by extending the `vector` class. It should contain the following functions:

- `size()` that returns the size of the stack
- `peek()` returns the top integer
- `pop()` returns the top integer and returns it.
- `push(int)` adds an integer to the top of the stack
- allows to be printed by `cout`
- `==` operator

Note that some functions might already be implemented in the `vector` class, so you will not need to reimplement them.
