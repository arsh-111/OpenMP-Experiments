#include<stdio.h>
#include<omp.h>

int main(){
	
	int arr[5]={1,2,3,4,5};
	int rankarr[5];
	int thread_num[5];
#pragma omp parallel
	{
		
	#pragma omp for
	for(int i=0;i<5;i++)
	{
		int rank = 0;
		int thread_id = omp_get_thread_num();
		for(int j=0;j<5;j++){
			if(arr[j]<arr[i] || arr[j] == arr[i] && j<i){
				rank++;
			}
			rankarr[i] = rank;
			thread_num[i] = thread_id;
		}	
	}
	}

	for(int i = 0;i<5;i++){
		printf("Thread ID %d Element %d  and rank %d\n",thread_num[i],arr[i],rankarr[i]);
	}
	
	return 0;
}
