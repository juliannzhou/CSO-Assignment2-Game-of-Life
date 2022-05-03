# CSO-Assignment2-Game-of-Life
This C program simulates Conway's game of life with a 5*5 matrix where 1 represents a live cell and 0 represents a dead cell and allows for multiple generations.

The rules for the game of life is as follows:

1. A live cell with fewer than two live neighbors dies.
2. A live cell with more than three live neighbors also dies.
3. A live cell with exactly two or three live neighbors lives.
4. A dead cell with exactly three live neighbors becomes alive. 


Usage: 
```
gcc -Wall -std=c99 -o automata automata.c
./automata (number of generations) (input file in txt)
```
Input: a txt file with 5*5 matrix
Output: a txt file of the final state of the 5*5 matrix

