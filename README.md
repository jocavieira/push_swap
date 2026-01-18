*This project has been created as part of the 42 curriculum by jocarlo2.*

## Description

Push Swap is a sorting algorithm project that challenges you to sort a stack of integers using a limited set of operations with the smallest number of moves possible. The goal is to sort a stack (stack A) with the help of an auxiliary stack (stack B) using only predefined operations.

The project implements the **Turk Algorithm**, an efficient approach that analyzes the cost of each possible move and always chooses the cheapest option. This results in optimal sorting with a minimal number of operations.

### Available Operations

- **sa** (swap a): Swap the first 2 elements at the top of stack A
- **sb** (swap b): Swap the first 2 elements at the top of stack B
- **ss**: sa and sb at the same time
- **pa** (push a): Take the first element at the top of B and put it at the top of A
- **pb** (push b): Take the first element at the top of A and put it at the top of B
- **ra** (rotate a): Shift all elements of stack A up by 1
- **rb** (rotate b): Shift all elements of stack B up by 1
- **rr**: ra and rb at the same time
- **rra** (reverse rotate a): Shift all elements of stack A down by 1
- **rrb** (reverse rotate b): Shift all elements of stack B down by 1
- **rrr**: rra and rrb at the same time

### Algorithm Overview

The Turk Algorithm works by:
1. Pushing elements from stack A to stack B (keeping the 3 last elements in A)
2. For each element, calculating the cost of moving it to its target position
3. Always choosing the cheapest move to execute
4. Sorting the remaining 3 elements in stack A with a specialized small-stack sort
5. Pushing back all elements from B to A in their correct positions
6. Rotating stack A to bring the minimum element to the top

## Instructions

### Compilation

To compile the project, run:

```bash
make
```

This will create the `push_swap` executable using the following compiler flags: `-Wall -Wextra -Werror`

### Execution

Run the program with a list of integers as arguments:

```bash
./push_swap 4 67 3 87 23
```

Or with a quoted string:

```bash
./push_swap "4 67 3 87 23"
```

The program will output the list of operations needed to sort the stack. For example:

```bash
pb
pb
sa
pa
pa
```

## Resources

### Classic References

- **Push Swap Video**: [push_swap : a performant sorting algorithm using 2 stacks (100-630 moves | 500-5470 moves)](https://www.youtube.com/watch?v=OaG81sDEpVk&t=934s) - A helpful video to understanding the project and the algorithm
- **Turk Algorithms**: [Push Swap — A journey to find most efficient sorting algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) - Detail information about the turk algorithm

### Algorithm References

- **Mechanical Turk Algorithm**: The implementation is based on the cost-calculation approach where each move's efficiency is evaluated before execution
- **Stack Data Structures**: Understanding of doubly-linked lists and stack operations

### AI Usage

AI tools were used in the following ways during this project:

- **Code Review and Debugging**: AI was consulted to review logic errors and suggest improvements to the cost calculation functions
- **Understanding**: AI assisted in understading better the behavior of linked lists and the turk logic
- **Optimization Ideas**: AI provided insights on potential optimizations in the target selection and cost calculation algorithms
