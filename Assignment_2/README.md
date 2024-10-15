# Overview
This assignment covers text parsing and data processing using strings, vectors and C++ structure types.

The main objective is to implement a set of C++ functions, whose behavior is described in detail in the provided file `assignment_2.cpp`. Your submission should be a single C++ source file called `assignment_2.cpp`.

## Task (50pt)
BC Ferries provides ferry services for a variety of ferry routes across the province. This assignment will use a collection of scheduling data to analyze various aspects of on-time performance for BC Ferries sailings.

A sailing is a single journey of a single vessel from one terminal to another (for example, the 5:00pm sailing from Swartz Bay to Tsawassen on June 10, 2022). For data analysis purposes, BC Ferries might collect data on each sailing, including:

- Weather conditions
- The total number of passengers or vehicles
- The specific vessel making the trip
- The duration of the sailing
- The expected duration of the sailing

For this assignment, we will use a dataset cataloguing the vessel, duration and expected duration of
each sailing (the other factors will be omitted). Note that the "expected duration" is the estimated
time of sailing in normal conditions (for example, the Swartz Bay to Tsawwassen route has an
expected duration of 95 minutes).
The actual duration may vary.
In the provided datasets, we have computed the actual duration of each sailing based on the time between the scheduled departure of the vessel and its arrival (so, for example, if a ferry scheduled to leave at 2:00pm actually leaves
at 2:30pm and arrives at 3:00pm, the duration will be taken to be 60 minutes).
The input data will be provided in a text file, where each line contains the following data fields,
separated by commas:

1. Route number
2. Departure ("source") terminal
3. Arrival ("destination") terminal
4. Year
5. Month
6. Day
7. Hour of scheduled departure (in 24-hour format)
8. Minute of scheduled departure
9. Vessel name
10. Expected duration (in minutes)
11. Actual duration (in minutes)

Note that the two duration values will always be integer values.
For example, the input line
```
1,Swartz Bay,Tsawwassen,2022,6,10,7,0,Spirit of Vancouver Island,95,93
```
describes a sailing on route number 1, which departed from Swartz Bay and sailed to Tsawwassen
on June 10th, 2022 (2022-06-10) at 7:00 using the vessel "Spirit of Vancouver Island". The sailing
was expected to last 95 minutes but took only 93 minutes.

Part of this assignment involves tabulating "late sailings", which we define to be any sailing for
which actual duration >= expected duration + 5.
In the example above, if the sailing had an actual duration of 100 minutes (or more), it would be
classified as late.
The `assignment_2.cpp` file contains a series of structure definitions and function prototypes for
various operations on the dataset. Your task is to implement the required functions.

### Driver Program
A complete program has been provided in `assignment_2.cpp` which performs various analysis tasks
using all the functions.

`route_summary` - Print a summary of the on-time performance for each route in the dataset.

`days` - Print a summary of the "best days" and "worst days" in the dataset. The best days
are days with the lowest percentage of late sailings, and the worst days are days with the
highest.

For both of the actions specified above, the output may contain multiple records (for example, with the days action, there might be multiple days that are tied for "best", and all of them would be part of the result). Your
implementation must produce the same set of records as the model solution, but it is not necessary
for them to appear in the same order.

### Visual Studio
Passing comma-line arguments to Visual Studio is annoying. To run and test your code you can comment these lines
```
    if (argc < 3)
    {
        std::cout << "Usage: ./assignment_2 action input_filename" << std::endl;
        std::cout << "       where action is either 'route_summary' or 'days'" << std::endl;
        return 1;
    }

    std::string action{argv[1]};
    std::string input_filename{argv[2]};
```
and hardcode the `action` and `input_filename`. **Remember** to undo the changes before submitting.


## Code Requirements

- If your code does not compile as submitted (with no modifications
whatsoever), you will receive a mark of zero
- The `goto` statement is not permitted in any assignment submissions. Instead, your code
should use structured control flow elements, like `if`, `for` and `while`.
- Global variables (data variables created outside of the scope of a function) are not permitted, except for const variables if needed.
- Every function with a non-void return type must return a value.
- Uninitialized variables may not be used before being assigned a value.
