# General Rules



## Plagiarism Note and Late Submissions

Copying code (either from other students or from external sources) is strictly prohibited. We will use automatic anti-plagiarism tools, and any violation of this rule will be reported to Academic Integrity. Late assignments will be graded out of 70%.

## Provided Software

For this class, you will use the minimal framework provided with each assignment. It compiles on Windows, Linux, and Mac. No special hardware is required for this class as we will not be using the GPU for the assignments.

## Preparing the Build Environment

You must install a C++ compiler: `gcc/clang` on Linux, `clang` on Mac, [Visual Studio](https://www.visualstudio.com/) on Windows.

If you are looking for an IDE to develop in C++, we recommend [Visual Studio Code](https://code.visualstudio.com) on Mac/Linux, and [Visual Studio](https://www.visualstudio.com/) on Windows.

### Compiling the Sample Projects (Windows)

Follow the instructions on [Windows](Windows.md).

### Compiling the Sample Projects (Unix)

We will provide a folder for each assignment with some sample code to get you started. For each assignment, you will need to do the following:

1. Download the assignment code
2. Create a directory called `build` in the assignment directory, e.g.:
   ```
   cd assignment_X; mkdir build
   ```
3. Use the compiler to compile inside the `build/` directory:
   ```
   cd build; g++ ../assignment_X.cpp -o assignment_X
   ```
4. Run the compiled executable by typing:
   ```
   ./assignment_X
   ```


## What to Hand In

The delivery of the exercises is done using brightspace. The repository should follow the template provided in the starter code, and it must contain:

- The source code, together with any changed files, but excluding all compiled binaries/libraries. Specifically, do not include the `build/` directory. The code must successfully compile on your operating system of choice: code that does not compile will not be awarded any points, even if it contains a partial implementation of the solution.

Note: Using additional external software for your assignments will not be necessary. If you need to use additional binaries/external libraries other than those provided by us, please first get approval by sending a message on Teams.

## Grading

Your submission will be graded according to the correctness of the implemented algorithms.
