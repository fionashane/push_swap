# push_swap

![push_swap](https://img.shields.io/badge/push_swap-42-success)

The **push_swap** project is part of the curriculum at [42 Adelaide](https://www.42adel.org.au) and involves sorting a stack of numbers using a specific set of operations with the fewest possible moves.

## Project Objectives

The project aims to improve your algorithmic thinking and problem-solving skills. It challenges you to come up with an efficient sorting algorithm and implement it using a restricted set of stack operations. This project encourages you to:

- Analyse sorting algorithms and understand their efficiency
- Implement a sorting algorithm using stack operations
- Optimise the number of moves needed to sort the stack

## How to use

To use the **push_swap** program, you need to:
1. Clone the repository to your local machine
```bash
git clone https://github.com/fionashane/push_swap.git
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

The **push_swap** program uses a sorting algorithm that utilises two stacks, referred to as Stack A and Stack B. The program takes an unsorted list of integers and uses a combination of operations (swap, push, rotate, and reverse rotate) to sort them in ascending order.

## Example Output

Running the program will output a list of instructions to sort the stack. For example:
```
sa
ra
```

This sequence of instructions would swap the first two elements of Stack A (sa) and then rotate the remaining elements in Stack A by one position (ra).
