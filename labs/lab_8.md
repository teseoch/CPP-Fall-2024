# Iterator, Operators, Classes

## Exercise 1 (Class)

Implement the class StopWatch. The class should contain:

- An constructor that initialises the start time with the current time
- Function `start` that resets the start time
- Function `stop` that sets the end time
- Function `get_time` that returns the elapsed time in *seconds*.


## Exercise 2 (Class)

Implement the class `QuadraticEquation` (`ax^2 + bx + c = 0`). The class should contain:

- A constructor that takes the 3 coefficients, if the equation has no solutution throw an invalid argument exception
- The getters and setters for all fields, if the equation has no solutution throw an invalid argument exception
- Function `get_discriminant` that computes the discriminant `b^2 - 4ac`
- Function `has_real_solution` that checks if the discriminant is positive
- Function `is_quadratic` that checks if a is different from zero
- Function `has_duplicated_solution` that checks if the discriminant is zero
- Two functions `get_solution1` and `get_solution2` that returns the two solutions (`(-b+sqrt(discriminant))/(2a)` and `(-b-sqrt(discriminant))/(2a)`)



## Exercise 3 (Class, Operators, Iterators)

Implement the `IntVector` class as a vector of int. It should:

- contain `size()` return the size of the vector
- use `(int)` and `[int]` to acces the element at a given index
- contain `push(int)` adds an integer at the end
- be printable with `cout<<``
- contain `begin()` and `end()` that return `IntVectIt`

Implement the iterator class `IntVectIt`, it should contain:

- `++` to increment the iterator
- `*` to access the element
- `==` to compare it with another iterator



## Exericse 4 (Class, Operators)

Write the class `Point`, which represents an (x,y) point in the plane.
Provide operators to sum two points, multiply them (element whise), multiply with scalar, and compare them.


