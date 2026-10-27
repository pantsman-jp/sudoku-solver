# Sudoku Solver

A simple [Sudoku](https://en.wikipedia.org/wiki/Sudoku) solver
implemented in C++ using
[depth-first search (DFS)](https://en.wikipedia.org/wiki/Depth-first_search) and backtracking.

## Features

- Solves standard 9×9 [Sudoku](https://en.wikipedia.org/wiki/Sudoku) puzzles.
- Uses [DFS](https://en.wikipedia.org/wiki/Depth-first_search) and backtracking to find a solution.
- Reads the puzzle from `input.txt`.
- Writes the solution to `output.txt`.
- Uses only standard C++ libraries.

## Requirements

- A C++ compiler supporting C++17 or later.

## Usage

### 1. Prepare the input

Create an `input.txt` file containing the [Sudoku](https://en.wikipedia.org/wiki/Sudoku) puzzle.

- Use `0` to represent empty cells.
- Each row must contain exactly 9 digits.
- The puzzle must contain exactly 9 rows.

Example:

```text
000801000
000000043
500000000
000070800
000000100
020030000
600000075
003400000
000200600
```

### 2. Compile

```zsh
g++ -std=c++17 -O2 -o sudoku-solver main.cpp
```

### 3. Run

```zsh
./sudoku-solver
```

Run the command from the directory containing `input.txt`.

### 4. Check the output

If a solution is found, the completed [Sudoku](https://en.wikipedia.org/wiki/Sudoku) grid is written to `output.txt`.

Example:

```text
237841569
186795243
594326718
315674892
469582137
728139456
642918375
853467921
971253684
```

If no solution is found, `output.txt` contains:

```text
No solution
```

## Algorithm

The solver uses [depth-first search(DFS)](https://en.wikipedia.org/wiki/Depth-first_search) with backtracking.

1. Find an empty cell.
2. Try each digit from 1 to 9.
3. Check whether the digit satisfies the [Sudoku](https://en.wikipedia.org/wiki/Sudoku) constraints for its row, column, and 3×3 box.
4. If valid, place the digit and recursively solve the remaining puzzle.
5. If the current choice leads to a dead end, remove the digit and try the next candidate.
6. Repeat until a solution is found or all candidates have been exhausted.

The solver stops after finding the first solution.
It does not determine whether the solution is unique.

---

Copyright (c) 2026 pantsman
