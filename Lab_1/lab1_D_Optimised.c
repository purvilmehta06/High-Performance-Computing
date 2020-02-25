#include<stdio.h>
#include<omp.h>
#include<math.h>
#define ll int
int dummy(){
	return 0;}
int main()
{
	ll minSize = pow(2,1),maxSize = pow(2,15);
	ll total = maxSize;
	ll RUNS;
	ll i,size,j,N,k;
	int d,cnt=0;
	for (size = minSize;size < maxSize;size=size*2)
	{
		N = size;
		/*double *A,*B,*C,*D;
		A = (double *)malloc(size*sizeof(double));
		B = (double *)malloc(size*sizeof(double));
		C = (double *)malloc(size*sizeof(double));
		D = (double *)malloc(size*sizeof(double));*/
		double mat[N][N], s[N][N];
		int v[N];
		RUNS = (double)total/size;
		double start_time = omp_get_wtime();
		for(i =0 ;i<N;++i)
		{
			for(j=0;j<N;++j)
				s[i][j]=1;
			v[i] = 2;
		}
		for(k=0;k<RUNS;++k)
		{
			for(i=0; i<N ; ++i) {
				double val = 2*(double)(v[i] % 256);
				double llt = -cos(val);
				for(j=0; j<N; ++j) {
					mat[i][j] = s[i][j]*(llt);
			}
			}
			if(size == maxSize)
				d=dummy();
		}
		double end_time = omp_get_wtime() - start_time;
		//double throughput = (sizeof(double)*2*total)/end_time;
		//printf("%lf,\n",throughput);
		printf("%.15lf,\n",end_time);
	} 
	
	return 0;
}
