# OpenMPTask

You are required to:

1. Use OpenMP to parallelize both the initialization and computation
2. Submit your code


# Run 

```
make run
```

Example result
```
$make run
gcc -fopenmp -Wall -O2 MatrixOMP.cpp -o test -fopenmp
./test
Serial Execution Time: 0.097904 seconds
First 5 elements of result:
y[0] = 2520.382032
y[1] = 2490.132520
y[2] = 2466.238442
y[3] = 2459.820816
y[4] = 2494.885474
```
