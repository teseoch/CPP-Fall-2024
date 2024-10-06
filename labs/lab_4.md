# Vectors and References


## Exercise 1 (Vectors)

Write a program that computes the Median of a vector of numbers. The median is the middle element of a sorted sequence. If the sequence has an even number of elements, the median is the average of the two middle elements. To compute it, you need to sort the vector; the C++ standard library includes a function `std::sort` (available via `#include <algorithm>`), which sorts a data sequence. The arguments to `std::sort` indicate the beginning and end of the sequence to sort.
```
std::vector<double> vec{...}
std::sort(vec.begin(), vec.end());
```

### Example of output

```
  Numbers:
  71 49 92 87 0 66 81 74 0 51 64 94 79

The median is 68.5
```


## Exercise 2 (Vectors)

Write a program that receives a vector integer, removes all duplicates, and finally prints the cleaned data set.


### Example of output


```
  Numbers:
  1 1 1 2 6 5 1 1 6

Clean:
1 2 5 6
```


## Exercise 3 (References)

Write a function that swaps two integers. Then, print the swapped numbers.


### Example of output

Input
```
int a{6}, b{10};
std::cout << a << " " << b << std::endl;
swap(a, b);
std::cout << a << " " << b << std::endl;
```
The output prints 6 10, then 10 6;


## Exercise 4 (References and Vectors)

Write two functions that compute and print the sum of a vector of integers. In one function, pass the vector by reference and one by copy.
Add 100,000 numbers to the vector and time the two functions. To measure time, you can use `chrono`:
```
#include <chrono>
#include <iostream>

int main()
{
    std::vector<int> vec{};
    // add numbers to vec

    auto start = std::chrono::high_resolution_clock::now();
    sum_and_print_copy(vec);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
    std::cout << "Time taken by function: " << duration.count() << " seconds" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    sum_and_print_ref(vec);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
    std::cout << "Time taken by function: " << duration.count() << " seconds" << std::endl;
}
```
