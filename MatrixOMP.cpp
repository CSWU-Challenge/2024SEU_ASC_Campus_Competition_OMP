#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h> // for Linux
//#include <windows.h> // for Windows


// Timer function for Linux
double get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec * 1e-6;
}


// Timer function for Windows
/*
double get_time() {
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);
    return (double)start.QuadPart / (double)frequency.QuadPart;
}
*/

void matrix_vector_mult(const double* A, const double* x, double* y, int n) {
    for (int i = 0; i < n; i++) {
        double sum = 0.0;
        for (int j = 0; j < n; j++) {
            sum += A[i * n + j] * x[j];
        }
        y[i] = sum;
    }
}

int main() {
    const int n = 10000;
    double* A = (double*)malloc(n * n * sizeof(double));
    double* x = (double*)malloc(n * sizeof(double));
    double* y = (double*)malloc(n * sizeof(double));
    
    // Initialize arrays with random values
    srand(time(NULL));
    for (int i = 0; i < n * n; i++) {
        A[i] = (double)rand() / RAND_MAX;
    }
    for (int i = 0; i < n; i++) {
        x[i] = (double)rand() / RAND_MAX;
    }
    
    // Measure execution time
    double start_time = get_time();
    matrix_vector_mult(A, x, y, n);
    double end_time = get_time();
    
    printf("Serial Execution Time: %.6f seconds\n", end_time - start_time);
    
    // Print first few results for verification
    printf("First 5 elements of result:\n");
    for (int i = 0; i < 5; i++) {
        printf("y[%d] = %.6f\n", i, y[i]);
    }
    
    free(A);
    free(x);
    free(y);
    return 0;
}
