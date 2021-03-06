#include<stdio.h>
#include<math.h>
#include<omp.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

#define min(x, y) (((x) < (y)) ? (x) : (y))
//  Using the MONOTONIC clock 
#define CLK CLOCK_MONOTONIC

/* Function to compute the difference between two points in time */
struct timespec diff(struct timespec start, struct timespec end);

/* 
   Function to computes the difference between two time instances

   Taken from - http://www.guyrutenberg.com/2007/09/22/profiling-code-using-clock_gettime/ 

   Further reading:
http://stackoverflow.com/questions/6749621/how-to-create-a-high-resolution-timer-in-linux-to-measure-program-performance
http://stackoverflow.com/questions/3523442/difference-between-clock-realtime-and-clock-monotonic
 */
struct timespec diff(struct timespec start, struct timespec end){
	struct timespec temp;
	if((end.tv_nsec-start.tv_nsec)<0){
		temp.tv_sec = end.tv_sec-start.tv_sec-1;
		temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
	}
	else{
		temp.tv_sec = end.tv_sec-start.tv_sec;
		temp.tv_nsec = end.tv_nsec-start.tv_nsec;
	}
	return temp;
}


int main(int argc, char* argv[])
{
	struct timespec start_e2e, end_e2e, start_alg, end_alg, e2e, alg;
	/* Should start before anything else */
	clock_gettime(CLK, &start_e2e);

	/* Check if enough command-line arguments are taken in. */
	if(argc < 3){
		printf( "Usage: %s n p \n", argv[0] );
		return -1;
	}

	int n=atoi(argv[1]);	/* size of input array */
	int p=atoi(argv[2]);	/* number of processors*/
	char *problem_name = "image_warping";
	char *approach_name = "collapsed_directive";
//	char buffer[10];
//	FILE* inputFile;
	FILE* outputFile;
	//	inputFile = fopen(argv[3],"r");

	char outputFileName[50];		
	sprintf(outputFileName,"output/%s_%s_%s_%s_output.txt",problem_name,approach_name,argv[1],argv[2]);	

	//**********************
	int i,s,k,j;
	double start= omp_get_wtime();
	double **a,**r,**q;
	a = (double**)malloc(n*sizeof(double*));
	r = (double**)calloc(n,sizeof(double*));
	q = (double**)calloc(n,sizeof(double*));
	for(i=0;i<n;i++){
		a[i] = (double*)malloc(n*sizeof(double));
		r[i] = (double*)calloc(n,sizeof(double));
		q[i] = (double*)calloc(n,sizeof(double));
	} 	
	
	for(i=0;i<n;i++)
	    for(s=0;s<n;s++)
	        a[i][s]=(i*n+s)*(i*n+s);
	//**********************
	omp_set_num_threads(p);
	clock_gettime(CLK, &start_alg);	/* Start the algo timer */

	/*----------------------Core algorithm starts here----------------------------------------------*/
	
	for(i=0; i<n; i++)
	{
	    s=0;
	    #pragma omp parallel for schedule(dynamic,10) reduction(+:s)
	    for(j=0; j<n; j++)
	        s=s+a[j][i]*a[j][i];
	    
	    r[i][i]=sqrt(s);
		
		#pragma omp parallel for schedule(dynamic,10) private(j)
		for(j=0; j<n; j++)
		    q[j][i]=a[j][i]/r[i][i];
		
		//#pragma omp parallel for schedule(dynamic,10) private(j, s)
		for(j=i+1; j<n; j++)
		{
		    s=0;
		    #pragma omp parallel for schedule(dynamic,10) reduction(+:s)
		    for(k=0; k<n; k++)
		        s=s+a[k][j]*q[k][i];
		    
		    r[i][j]=s;
		    
		    #pragma omp parallel for schedule(dynamic,10) private(k)
		    for(k=0; k<n; k++)
		        a[k][j]=a[k][j]-r[i][j]*q[k][i];
		}
	}
	
	/*----------------------Core algorithm finished--------------------------------------------------*/

	clock_gettime(CLK, &end_alg);	/* End the algo timer */
	/* Ensure that only the algorithm is present between these two
	   timers. Further, the whole algorithm should be present. */


	/* Should end before anything else (printing comes later) */
	clock_gettime(CLK, &end_e2e);
	e2e = diff(start_e2e, end_e2e);
	alg = diff(start_alg, end_alg);
	

	/* problem_name,approach_name,n,p,e2e_sec,e2e_nsec,alg_sec,alg_nsec
	   Change problem_name to whatever problem you've been assigned
	   Change approach_name to whatever approach has been assigned
	   p should be 0 for serial codes!! 
	 */
	 
	 for(i=0;i<n;i++)
	{{for(s=0;s<n;s++)printf("%f ",q[i][s]);}printf("\n");}
    	printf("\n");
    	for(i=0;i<n;i++){{for(s=0;s<n;s++)printf("%f ",r[i][s]);}printf("\n");}
	printf("%s,%s,%d,%d,%d,%ld,%d,%ld\n", problem_name, approach_name, n, p, e2e.tv_sec, e2e.tv_nsec, alg.tv_sec, alg.tv_nsec);

	return 0;

}


