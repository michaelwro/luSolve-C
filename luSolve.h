/*

SOLVE SYSTEM OF EQUATIONS WITH LU-FACTORIZATION
Code By: Michael Wrona
Student, B.S. Aerospace Engineering, Iowa State University (Ames, IA)

This is the required header file for the code.

*/


void print1dArray(int rows, float *arr);
void print2dArray(int rows, int cols, float **arr);
void genRandSystem(int n, float **arr, float *b);
void luSolve(int n, float **arr, float *b, float *x);
