/*
HEADER FILE FOR luSolve.h
Michael Wrona
*/

void print1dArray(int rows, float *arr);
void print2dArray(int rows, int cols, float **arr);
void genRandSystem(int n, float **arr, float *b);
void luSolve(int n, float **arr, float *b, float *x);
