//Quick sort program with first element as pivot
#include<stdio.h>
int swap(int *a,int *b){
	int temp =*a;
	*a=*b;
	*b=temp;
}
int partition(int arr[],int low,int high){
	int pivot=arr[low];
	int i=low+1,j;
	for(j=low+1;j<=high;j++){
		if(arr[j]<pivot){
			swap(&arr[i],&arr[j]);
			i++;
		}
	}
	swap(&arr[i-1],&arr[low]);
	return i-1;
}
void quicksort(int arr[],int low,int high){
	if(low<high){
		int pi = partition(arr,low,high);
		quicksort(arr,low,pi-1);
		quicksort(arr,pi+1,high);
	}
}
int main(){
	int arr[]={43,23,12,53,2,67,11,56,43,22};
	int n=sizeof(arr)/sizeof(arr[0]),i;
	quicksort(arr,0,n-1);
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
	return 0;
}