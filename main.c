/*
SOLVE LINEAR SYSTEM OF EQUATIONS
Michael Wrona
*/

#include <stdio.h>
#include <stdlib.h>
#include "src/luSolve.h"



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
			printf("CANNOT ALLOCATE, OUT OF MEMORY \n");
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
	printf("Generated system \n");

	// SOLVE SYSTEM
	luSolve(n, a, b, x);
	printf("System solved \n");

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
	printf("Memory freed \n");

	return 0;
}

