#include<stdio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>


void matmul(long long int n, double** a, double** b,int blocksize)
{
    int bi, bj, bk, i, j, k,l;

	for (i = 0; i < n; i += blocksize) {
        for (j = 0; j < n; j += blocksize) {
                    for (k = 0; k < blocksize; ++k) {
                            for (l = 0; l <   blocksize; ++l) {
                                    b[j + l][i+k] = a[i+k][j + l];
                            }
                    }
            }
    }
    return;
}
void matprint(double **a,int n)
{   
    int i,j;
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
            printf("%lf ",a[i][j]);
        printf("\n");
    }
}
int dummy(int x)
{
    return x+10;
}

int main(int argc, char* argv[])
{
    long long int minSize = 2048;
    long long int maxSize = 2048;
    
    long long int i,j, times, n = minSize;
    int blocksize = atoi(argv[1]); 
    for(n=minSize; n<=maxSize; n*=2)
    {
        times = maxSize / n;
        
        //allocations
        double **a = (double**)malloc(n * sizeof(double *));
        double **b = (double**)malloc(n * sizeof(double *));
        for(i=0; i<n; i++)
        {
            a[i] = (double *)malloc(n * sizeof(double));
            b[i] = (double *)malloc(n * sizeof(double));
        }
        for(i=0;i<n;++i)
        {
        for(j=0;j<n;++j)
           a[i][j] = i*j + i;
        }
        double time_taken;
        clock_t start, end;
        
        
        start = clock();
        for(i=0; i<times; i++)
        {
            matmul(n, a, b,blocksize);
            if(n == maxSize * 2)
                dummy(n);
        }
        end = clock();
        
        time_taken = (end - start) / (double) CLOCKS_PER_SEC;
        time_taken /= times;
        
        printf("%.15lf\n,", time_taken);

    }

    
    
    return 0;
}
