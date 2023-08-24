# Push_Swap - 42 Project

![Push_Swap](https://img.shields.io/badge/Push_Swap-42-success)

The **Push_Swap** project is part of the curriculum at [42 Adelaide](https://www.42adelaide.com/) and involves sorting a stack of numbers using a specific set of operations with the fewest possible moves.

## Project Objectives

The project aims to improve your algorithmic thinking and problem-solving skills. It challenges you to come up with an efficient sorting algorithm and implement it using a restricted set of stack operations. This project encourages you to:

- Analyse sorting algorithms and understand their efficiency
- Implement a sorting algorithm using stack operations
- Optimise the number of moves needed to sort the stack

## How to use

To use the **Push_Swap** program, you need to:
1. Clone the repository to your local machine
```bash
git clone https://github.com/your_username/push_swap.git
```

2. Compile the program using the provided Makefile
```bash
make
```

3. Run the program with a list of integers to sort
```bash
./push_swap 3 1 5 2 4
```

4. The program will output a series of instructions to sort the stack

## Sorting Algorithm

The **Push_Swap** program uses a sorting algorithm that utilises two stacks, referred to as Stack A and Stack B. The program takes an unsorted list of integers and uses a combination of operations (swap, push, rotate, and reverse rotate) to sort them in ascending order.

## Example Output

Running the program will output a list of instructions to sort the stack. For example:
```
sa
ra
```

This sequence of instructions would swap the first two elements of Stack A (sa) and then rotate the remaining elements in Stack A by one position (ra).

## Credits

The **Push_Swap** project was developed by [42 Adelaide](https://www.42adel.org.au).
