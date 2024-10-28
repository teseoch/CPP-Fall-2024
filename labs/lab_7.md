# Iterator, Collections and Maps

## Exercise 1 (Set)
Implement a function punctuation, which creates a set of all punctuation characters used in a vector of input strings. Once all the input has been processed, print each punctuation character separated by spaces. [Here](https://en.cppreference.com/w/cpp/header/cctype), you can find functions to check if a character is a punctuation.

### Example of input
```
{"Sea", "Shore,", "sea", "shell's.", "SHORE.", "line!"}
```

### Example of output
```
! ' , .
```

## Exercise 2 (Iterators)

Write a program that prompts the user for a string. Print the string in reverse order using iterators.

### Example of output

```
  Enter string:
  > of that im sure

Reverse is string: erus mi taht fo
```


## Exercise 3 (Set)

Write a program that receives a vector integer, removes all duplicates using a set, and prints the cleaned data set.


### Example of output

```
  Numbers:
  1 1 1 2 6 5 1 1 6

Clean:
1 2 5 6
```


## Exericse 4 (Word Frequencies using Maps)

Write a program which reads a string and prints the word frequency for each word using a map.


### Example of output

```
Input
> sally sells seashells by the seashore
she sells seashells on the seashell shore
the seashells she sells are seashore shells

Word Frequencies:
sally 1
sells 3
seashells 3
by 1
the 3
seashore 2
she 2
on 1
seashell 1
shore 1
are 1
shells 1
```
