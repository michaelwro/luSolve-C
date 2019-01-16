/*
SOLVE SYSTEM OF EQUATIONS WITH LU-FACTORIZATION
Code By: Michael Wrona
Student, B.S. Aerospace Engineering, Iowa State University (Ames, IA)



*/

#include <stdio.h>
#include <stdlib.h>
#include "luSolve.h"



int main(void) {
	// Initialize variables
	int i;
	int n = 120;		// Size of system

	// ALLOCATE DYNAMIC ARRAYS 'a', 'b', and 'x'
	float **a = malloc(n * sizeof(float *));	// Allocate 2D array 'a'
	for (i = 0; i < n; i++) {
		a[i] = malloc(n * sizeof(float));

		// Check if out of memory
		if (a[i] == NULL) {
			printf("CANNOT ALLOCATE \"a\", OUT OF MEMORY \n");
			return 0;
		}
	}

	float *b = malloc(n * sizeof(float));	// Allocate 1D array 'b'
	float *x = malloc(n * sizeof(float));	// Allocate 1D array 'x'
	for (i = 0; i < n; i++) {
		x[i] = 0.0;		// Populate with zeros
	}

	// Generate system of equations
	genRandSystem(n, a, b);

	// SOLVE SYSTEM
	luSolve(n, a, b, x);

	// // Print result
	// print1dArray(n, x);

	// Free memory
	printf("Freeing memory... \n");
	for (i = 0; i < n; i++) {
		free(a[i]);
	}
	free(a);
	free(b);
	free(x);

	return 0;
}
