# Matrices and Exceptions


## Exercise 1 (Matrices)

Implement a function to construct an N x M random matrix.
Use the `using` statement; for instance, you can define your matrix type as `using matrix_type = std::vector<std::vector<double>>`.

## Exercise 2 (Matrices and exceptions)

Implement a function `add_matrices` that adds two matrices together and returns the result.
The function should throw an exception if the two matrix sizes are wrong. When these errors occur, throw an appropriate exception (`std::domain_error`).

## Exercise 3 (Matrices and exceptions)

Implement a function `trace` that computes the matrix's trace (the sum of diagonal entries) and returns the result.
The function must detect various error cases that may occur when inputs are invalid (i.e., the matrix is not square). When these errors occur, throw appropriate exceptions (`std::domain_error`).

## Exercise 4 (Matrices and exceptions)

Implement a function to verify if a matrix is correct (i.e., all rows have the same length). Create a custom `InvalidMatrix` exception and throw it.

