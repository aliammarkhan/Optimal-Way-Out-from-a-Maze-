# Optimal-Way-Out-from-a-Maze-
An approach to solve the maze problem in C++

## About the Problem

The content of the array can be
any character {1 (path), 0 (block), s (start), e (end), ! (visited)}.
The input maze may contain multiple-paths and you need to implement a recursive path finding
approach that enumerate all cell of the array that are on the unique path in order of traverse from
start s to end e. You need to enumerate all paths. Here is an example of a maze.
s 1 1 1 1 1 0
1 0 0 1 1 0 1
1 0 0 0 1 0 1
1 1 1 e 1 1 1
There are three possible paths:
Path#1= {(0,0),(0,1),(0,2),(0,3),(1,3),(2,3),(3,3)} Cost=7
Path#2= {(0,0),(1,0),(2,0),(3,0),(3,1),(4,1),(4,2),(4,3),(3,3)} Cost=9
Path#3= {(0,0),(1,0),(2,0),(3,0),(4,0),(4,1),(4,2),(4,3),(3,3)} Cost=9 

All you need to develop a recursive routine for finding path, the search is only allowed to follow
{Left, Right, Up and Down} from any location. The output for this problem is complete path from
starting to end location. The validation of input cases required as start and end location must be at
the boundary of the maze. There can be several paths for all valid input cases. You need to
enumerate all paths from starting to each cell followed till the end. The cost of a path is total
number of cell traveled. Hence the shortest path or optimal path is the minimum length path.

Input
The input is from the file, the first line contains two integers n and m, representing the dimension
of the maze. The maze is a 2-dimensional array of char. The next n lines contain the rows of the
maze; each row contains m columns. Hence there are m characters in each line. 

```bash
Input file
4 7
s 1 1 1 1 1 0
1 0 0 1 1 0 1
1 0 0 0 1 0 1
1 1 1 e 1 1 1 
```
Output
The output file contains paths enumerated as path numbers with cost of each path, starting from
the minimum cost path.
```bash
Output file
Path#1={(0,0),(0,1),(0,2),(0,3),(1,3),(2,3),(3,3)}
Cost=7
Path#2={(0,0),(1,0),(2,0),(3,0),(3,1),(4,1),(4,2),(
4,3),(3,3)} Cost=9
Path#3={(0,0),(1,0),(2,0),(3,0),(4,0),(4,1),(4,2),(
4,3),(3,3)} Cost=9 

```

