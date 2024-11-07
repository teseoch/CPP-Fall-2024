
class Matrix
{
    //...[]
};

int main()
{
    Matrix A{3, 4}; // create a 3x4 matrix
    Matrix B{4, 5}; // create a 4x5 matrix
    Matrix c{3, 1}; // create a 3x1 matrix (col vector)

    Matrix P = A + B; // add two matrices
    Matrix Q = A * B; // multiply two matrices
    Matrix R = -A;    // negate a matrix

    if (A + B == Q)
    { //use the == operator to compare two matrices
        //...
    }

    //maybe compute the vector x such that Ax = c
    Matrix x = A % c;
}