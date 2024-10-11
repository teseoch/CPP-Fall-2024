# References, Structs, and Exceptions


## Exercise 1 (References and Exceptions)

Implement the function that solves the quadratic equation (`ax^2 + bx + c = 0`). The function should take the 3 coefficients `a`, `b`, `c`, and two variables `r1` and `r2` for the two roots.

You should compute the `discriminant=b^2 - 4ac` and throw an invalid argument exception if the equation has no real root (i.e., the discriminant is negative).

If `a=0`, it is not a quadratic equation, and it has no solution only if `b=0` (infinite if `c=0` or none); in that case, throw an invalid argument exception. Otherwise, both roots are `r1=r2=-c/b`.

If `a!=0` the two roots are `r1 = (-b+sqrt(discriminant))/(2a)` and `r2 = (-b-sqrt(discriminant))/(2a)`


## Exercise 2 (Structs and References)

Implement the `Matrix` struct using a `std::vector<std::vector<double>>`. Implement a function to initialize an `n x m` zero matrices, a function to initialize a `n x n` identity, and a function to print the matrix.

## Exercise 3 (Exceptions)

Write a program that prompts the user for a number until the user inputs an integer.

### Example
```
Input an integer:
> blah
Try again:
> 134.53.435
Try again:
> 1
The number is 1
```


## Exercise 4 (References)

Write a program that draws a spiral pattern (shown in the example) in an all-zeros square matrix. The program takes one positive integer representing the size of the matrix.

Example of a spiral for a `6 x 6` matrix.

```
6 6 6 6 6 6
0 0 0 0 0 5
0 3 2 2 0 5
0 3 0 1 0 5
0 3 0 0 0 5
0 4 4 4 4 5
```
