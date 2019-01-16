# luSolve-C

**Use LU-Factorization to solve a system of linear equations. Implemented in C.**

**Michael Wrona** _Student, B.S. Aerospace Engineering, Iowa State University (Ames, IA)_


## How to Use

### Description of Files

The `main.c` file is the main part of the code. There is a parameter '_n_' that changes the size of the system of equations. The files `luSolve.c` and `luSolve.h` contain the functions required to run the code. The functions within `luSolve.c` are:

* **print1dArray:** Print a 1D array/vector, such as the RHS and solution.
* **print2dArray:** Print a 2D array, such as the coefficient matrix.
* **genRandSystem:** Generate a dense, random system of equations. Generates the coefficient matrix and RHS.
* **luSolve:** Use LU-Factorization to solve the system of linear equations

### How to compile

The command to compile the project is:

```
gcc main.c luSolve.c -o foo
```

Where `foo` is the name of the output file/executable that runs your code.
