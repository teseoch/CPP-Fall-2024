# Strings and vectors


The goal of this assignment is manipulate strings and vectors in C++. The goal of the assignment is to read a text, splits the text into words and outputs a justified representation of the input text. Your program will justify the text with spacing only, and no hyphenation will be added.

### Preparing the Environment

Follow instructions the [generale rules](../Rules.md) to setup what you need for the assignment




### Typesetting

Typesetting is the process of formatting a typed document for printing or publication.
When typesetting a page-based document the text is often rendered in a justified format, where the words on each line in a paragraph are spaced out to perfectly fill the line of text. One tecnique to acieve this, is to slightly vary the space between words to facilitate the justified alignment. *Note:* Typesetting software will normally use hyphenation to split large words across multiple lines to ensure more balanced spacing.
The usual alternative is left-aligned text results in a "ragged" appearance. The difference is especially noticeable when text is typeset in a narrow column-based format

## Overview

Your program program will reads words from standard input (the `std::cin` stream) and produces a justified representation for length 30 of to standard output (the `std::cout` stream).


## Exercise 1, Input (10pt)

The input text must be acquired with the `std::cin` and consist of a series of words, arranged arbitrarily: there may be inconsistent spacing between words, there may be any number of words per line and any number of lines.
For the purposes of this assignment, a word is any sequence of one or more non-whitespace characters.
The program must continue reading words until `std::cin` will no longer read input (that is, until the end of the input stream is reached). **Do not** use any other method to detect the end of the input. You can signal the end of the input stream by pressing Ctrl-D (Ctrl-Z then enter on **Windows**) at the beginning of a line.

## Exercise 2, Storing (20pt)

After all of the input words are read, I suggest storing every justified line in a `std::vector`. Here is a suggestion on how to implement such algorithm. You can use a different strategy as long as it produces the correct output. Note that justification should not be applied to the last line of output text produced by your program.

Create a vector of strings `L` to store the current line.

For each word `w` in the input text:

- Test whether `w` can fit into the current line: `(number of words in L) + (total length of all words in L) + (length of w) ≤ 30`
    - If `w` fits into the current line, add `w` to `L`.
    - Otherwise:
      -  Output the justified line `L`, Exercise 3
      - Delete all elements of `L`
      - If the length of `w` is greater than 30 characters utput `w` followed by a newline.
      - Otherwise `w` to` L`

Once all words are processed if `L` is non-empty, for each word `w` in `L` output `w` followed by a **single** space.

## Exercise 3, Justification (25pt)

Given a vector of strings containing the words for a single justified line of text, your program must
use the algorithm below to compute the justified representation of the line.

1. Compute the total number of spaces needed:
Spaces needed: `30 − (total number of characters in all words in the line)`
2. For each word `w` in the line:
   - Print `w`
   - If `w` is the last word in the line, print a newline character and stop processing this line.
   - If `w` is not the last word in the line, compute the following value `s` using **integer
division**: `s = (number of spaces remaining) / (number of words remaining after w)`
   - Print out exactly `s` spaces.
   - Subtract `s` from the number of spaces remaining to be printed.

### Example
Suppose the line consists of the following five words.
```
This text will be justified
```

These five words together comprise 23 characters, so to produce a justified line of text containing 30 characters, exactly 30 − 23 = 7 spaces must be used. Therefore the text becomes (`␣` marks a space)

```
This␣text␣␣will␣␣be␣␣justified
```
## Examples


### The Handmaid's Tale by Margaret Atwood
Input
```
We slept in what had once been the gymnasium.
The floor was of varnished wood,
with stripes and circles painted on it,
for the games that were formerly played there;
the hoops for the basketball nets were still in place,
though the nets were gone.
```

Output
```
We slept in what had once been
the gymnasium. The  floor  was
of   varnished   wood,    with
stripes and circles painted on
it, for the  games  that  were
formerly  played  there;   the
hoops for the basketball  nets
were still  in  place,  though
the nets were gone.
```

### soliloquy from Macbeth
Input
```
Tomorrow, and tomorrow, and tomorrow,
Creeps in this petty pace from day to day,
To the last syllable of recorded time;
And all our yesterdays have lighted fools
The way to dusty death. Out, out, brief candle!
Life's but a walking shadow, a poor player
That struts and frets his hour upon the stage
And then is heard no more. It is a tale
Told by an idiot, full of sound and fury
Signifying nothing.
```

Output
```
Tomorrow,  and  tomorrow,  and
tomorrow, Creeps in this petty
pace from day to day,  To  the
last  syllable   of   recorded
time; And all  our  yesterdays
have lighted fools The way  to
dusty death. Out,  out,  brief
candle! Life's but  a  walking
shadow,  a  poor  player  That
struts and frets his hour upon
the stage And then is heard no
more. It is a tale Told by  an
idiot, full of sound and  fury
Signifying nothing.
```

### Special case of overly-long words

Input
```
If you want      to       learn more about typesetting,
you can try the Wikipedia article at https://en.wikipedia.org/wiki/Typesetting or    not.
```

Output
```
If  you  want  to  learn  more
about typesetting, you can try
the   Wikipedia   article   at
https://en.wikipedia.org/wiki/Typesetting
or not.
```

### Instructions

- The `goto` statement is not permitted in any assignment submissions.
- Global variables are not permitted, except when explicitly allowed by the assignment.
- Every function with a non-void return type must return a value.
- Uninitialized variables may not be used before being assigned a value.
- Other than the justified text, no other output will be produced by the program.

The solution of the exercises must be provides as a cpp file.
