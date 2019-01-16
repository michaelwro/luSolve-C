#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*
SOLVE SYSTEM OF EQUATIONS WITH LU-FACTORIZATION
By: Michael Wrona
*/

// Print 1D column arrays
void print1dArray(int rows, float *arr) {
	int i;
	printf("|");
	for (i = 0; i < rows; i++) {
		printf("%f \t", arr[i]);
	}
	printf("| \n");
	return;
}


// Print 2D array
void print2dArray(int rows, int cols, float **arr) {
	int i, j;
	for (i = 0; i < rows; i++) {
		printf("|");
		for (j = 0; j < cols; j++) {
			printf("%f \t", arr[i][j]);
		}
		printf("|\n");
	}
	return;
}


// Generate random system of equations for Ax = b
void genRandSystem(int n, float **arr, float *b) {
	float num, maxRange = 5.0;		// Maximum value for random numbers [0, maxRange]
	int i, j;
	srand((unsigned int)time(NULL));	// Seed random generator

	// First, populate coef. matrix 'A'
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			num = ((float)rand()/(float)(RAND_MAX)) * maxRange;
			arr[i][j] = num;
		}
	}

	// Then, populate solution matrix 'b'
	for (i = 0; i < n; i++) {
		num = ((float)rand() / (float)(RAND_MAX)) * maxRange;
		b[i] = num;
	}
	return;
}


// Solve linear system of equations using lu factorization
void luSolve(int n, float **arr, float *b, float *x) {
    /*
    'n', 'arr[][]': Coef. matrix
    'm', 'b[]': RHS of system
    'p', 'x[]': Solution array
    */

    int i, j, k;
    float sum;

    // Create dynamic array 'lu'
    float **lu = malloc(n * sizeof(float *));
    for (i = 0; i < n; i++) {
        lu[i] = malloc(n * sizeof(float));
        if (lu[i] == NULL) {
            printf("CANNOT ALLOCATE, OUT OF MEMORY \n");
            return;
        }
    }

    float *y = malloc(n * sizeof(float));   // Create dynamic array 'y'

    /* BEGIN LU FACTORIZATION */
    // Fill lu and y with zeros
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            lu[i][j] = 0.0;     // Fill 'lu'
        }
        y[i] = 0.0;             // Fill 'y'
    }

    // PERFORM LU FACTORIZATION
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            sum = 0.0;
            for (k = 0; k < i; k++) {
                sum += (lu[i][k] * lu[k][j]);
            }
            lu[i][j] = arr[i][j] - sum;
        }
        for (j=i+1; j < n; j++) {
            sum = 0.0;
            for (k = 0; k < i; k++) {
                sum += (lu[j][k] * lu[k][i]);
            }
            lu[j][i] = (1 / lu[i][i]) * (arr[j][i] - sum);
        }
    }

    // FIND SOLUTION OF Ly = b
    for (i = 0; i < n; i++) {
        sum = 0.0;
        for (k = 0; k < i; k++) {
            sum += (lu[i][k] * y[k]);
        }
        y[i] = b[i] - sum;
    }

    // FIND SOLUTION OF Ux = y
    for (i = n-1; i >=0; i--) {
        sum = 0.0;
        for (k = i+1; k < n; k++) {
            sum += (lu[i][k] * x[k]);
        }
        x[i] = (1 / lu[i][i]) * (y[i] - sum);
    }

    // Free memory
    for (i = 0; i < n; i++) {
        free(lu[i]);
    }
    free(lu);
    free(y);
    
    printf("SOLVE COMPLETE\n");
    return;
}

/*
index = row * n + col
*/

