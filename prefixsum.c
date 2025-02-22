#include<stdio.h>
#include<omp.h>
int main(){
	int sum=0;
	int arr[] = {1,2,3,4,5};
	#pragma omp parallel for reduction(+:sum) ordered
	for(int i=0;i<5;i++){
		
		int threadid = omp_get_thread_num();
		
		sum += arr[i];
#pragma ordered
		{
		
	printf("Thread id  = %d for sum = %d\n",threadid,sum);	
}	
	}
printf("Sum = %d", sum);


	return 0;
}
