//Quick sort program with last element as pivot
#include<stdio.h>
void swap(int *a,int *b){
	int temp = *a;
	*a=*b;
	*b=temp;
}
int partition(int arr[],int low,int high){
	int pivot = arr[high];
	int i=low,j;
	for(j=low;j<=high-1;j++){
		if(arr[j]<pivot){
			swap(&arr[j],&arr[i]);
			i++;
		}
	}
	swap(&arr[i],&arr[high]);
	return i;
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