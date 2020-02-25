#include<stdio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>


void matmul(long long int n, double** a, double** b, double** c)
{
    int bi, bj, bk, i, j, k;
    int blockSize = 64;
    if(blockSize > n)
        blockSize = n;
    
    for(bi=0; bi<n; bi+=blockSize)
        for(bj=0; bj<n; bj+=blockSize)
            for(bk=0; bk<n; bk+=blockSize)
                for(i=0; i<blockSize; i++)
                    for(j=0; j<blockSize; j++)
                        for(k=0; k<blockSize; k++)
                            c[bi+i][bj+j] += a[bi+i][bk+k]*b[bk+k][bj+j];
    return;
}

int dummy(int x)
{
    return x+10;
}

int main(int argc, char* argv[])
{
    long long int minSize = pow(2, atoi(argv[1]));
    long long int maxSize = pow(2, atoi(argv[2]));
    
    long long int i, times, n = minSize;
    for(n=minSize; n<=maxSize; n*=2)
    {
        times = maxSize / n;
        
        //allocations
        double **a = (double**)malloc(n * sizeof(double *));
        double **b = (double**)malloc(n * sizeof(double *));
        double **c = (double**)malloc(n * sizeof(double *));
        for(i=0; i<n; i++)
        {
            a[i] = (double *)malloc(n * sizeof(double));
            b[i] = (double *)malloc(n * sizeof(double));
            c[i] = (double *)malloc(n * sizeof(double));
        }
        
        double time_taken;
        clock_t start, end;
        
        
        start = clock();
        for(i=0; i<times; i++)
        {
            matmul(n, a, b, c);
            if(n == maxSize * 2)
                dummy(n);
        }
        end = clock();
        
        time_taken = (end - start) / (double) CLOCKS_PER_SEC;
        time_taken /= times;
        
        printf("%.15lf,", time_taken);
    }

    
    
    return 0;
}
