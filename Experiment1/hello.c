#include<stdio.h>
#include<omp.h>
int main(){

#pragma omp parallel
	
	{
		omp_num_threads(6);
	printf("Hello\t Thread id : %d\n",omp_get_thread_num());
}
	return 0;
}
