# Vector, Random, and IO


## Exercise 1 (io)

Write a program that prompts the user for strictly positive doubles. Continue to request numbers until a negative number (or zero) is read. The program should compute and print the maximum of the numbers. If the first number entered is negative (or zero), the maximum should be 0.

### Example of output

```
  Enter positive doubles:
  > 2.1
  > 99.6
  > -1

The maximum is 99.6
```



## Exercise 2 (Random and io)

Write a program that simulates the Rock-Paper-Scissors game. The program should ask the player to input his choice ((r) rock, (p) paper, or (s)scissors) and randomly generate the computer choice. Then, it should decide the winner and print the result.

The program should start with the player choosing the first letter of the element (both uppercase and lowercase letters should be accepted). The program should continue to ask for the element until a valid letter is chosen.

After making the correct choice, the program should display the player and computer choice on screen using ASCII art.


Rock
```
 __.--.--._
/  | _|  | `|
|  |` |  |  |
| /’--:--:__/
|/  /      |
(  ’ \     |
 \    `.  /
  |      |
  |      |
```

Paper
```
    --.--.
   |  |  |
.""|  |  |_
|  |  |  | `|
|  | _|  |  |
|  |` )  |  |
| /’  /     /
|/   /      |
(   ’ \     |
\      `.  /
 |        |
 |        |
```

Scissors
```
."".   ."",
|  |  /  /
|  | /  /
|  |/ .--._
|    _|  | `|
|  /` )  |  |
| /  /’--:__/
|/  /      |
(  ’ \     |
 \    `.  /
  |      |
  |      |
```


Finally, it should determine the (if any) winner by using the following rules:

- rock beats scissors
- paper beats rock
- scissors beat paper

### Example of output

```
=========================================
Welcome to the Rock-Paper-Scissors game! =========================================

Select your element:
	R/r - rock
	P/p - paper
	S/s - scissors
> R

 __.--.--._
/  | _|  | `|
|  |` |  |  |
| /’--:--:__/
|/  /      |
(  ’ \     |
 \    `.  /
  |      |
  |      |
Player

."".   ."",
|  |  /  /
|  | /  /
|  |/ .--._
|    _|  | `|
|  /` )  |  |
| /  /’--:__/
|/  /      |
(  ’ \     |
 \    `.  /
  |      |
  |      |
Computer

Player won! (rock beats scissor)
```


## Exercise 3 (Vectors)

Write a program that reads `N` double numbers `x_i` and prints their standard deviation.

![](https://latex.codecogs.com/svg.latex?\sigma=\sqrt{\frac{1}{N}\sum_{i=1}^N(x_i-\mu)^2})

where

![](https://latex.codecogs.com/svg.latex?\mu=\frac{1}{N}\sum_{i=1}^Nx_i)

The program should first prompt the user to input the number of numbers. Then it should read the numbers, compute their standard deviation, and print it.


### Example of output

```
How many numbers:
> 3
Insert 3 numbers:
> 2.1
> 2.6
> 1

Their std is 0.6683312552
```




## Exericse 4 (Vectors and io)

Write a program that plots an **horizontal** bar chart from a vector containing the length of each bar. Display the bar chart horizontally and use equal signs to visualize the columns.
Use `1, 3, 5, 0, 2` to create your vector.



### Example of output

```
Bar chart:
=
===
=====

==
```