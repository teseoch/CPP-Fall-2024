# Vector, Strings, Random, and IO


## Exercise 1 (Vectors)

Write a program that prompts the user for strictly positive integers. Continue to request numbers until a negative number (or zero) is read. The program should compute and print the mode of the numbers (i.e., the most frequent int). If the first number entered is negative (or zero), the mode should be 0. If several numbers have the same frequency, print the first one.

### Example of output

```
  Enter positive ints:
  > 2
  > 99
  > 2
  > -1

The mode is 2
```


## Exercise 2 (Strings)

Write a program that reads an integer input, and prints the corresponding month. If the input is larger than 12 or smaller or equal than zero, it should display an error message.

### Example of output

If the user writes 4, the program should print "April"
If the user writes 0, the program should print "Invalid month number"


## Exercise 3 (Vectors and Strings)

Write a program that reads a string of integer numbers separated by space and removes duplicated numbers (the order of the output is not important). Finally, print the result.


### Example of output

Input
```
Numbers:
> 3 4 5 6 3 1 2
```

Output
```
Without duplicates 3 1 5 6 4 2
```

## Exericse 4 (Vectors and io)

Write a program that simulates the [Bean machine](https://en.wikipedia.org/wiki/Galton_board).
Balls are dropped from the top opening of the board. Every time a ball hits a pin it has 50% chances of going left or right. Finally, all balls are accumulated in the slots the bottom of the box.

The program should ask the user to specify the number of balls and the number of slots. It should display the all paths taken by the balls as sequences of L and R depending on where that ball went. Finally, it should show the final disposition of the balls as a horizontal histogram.

### Example of output

Input
```
Number of balls to drop
> 5
Number of slots:
>8
```

Output:
```
Paths:
LRLRLRR
RRLLLRR
LLRLLRR
RRLLLLL
LRLRRLR

Disposition:


o
o
ooo



```

