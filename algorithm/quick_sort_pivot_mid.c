//Quick sort program with pivot as a middle element
#include<stdio.h>
void swap(int *a,int *b){
	int t = *a;
	*a = *b;
	*b = t;
}
void quicksort(int arr[],int low,int high){
	if(low>high) return;
	int pivot = (high+low)/2;
	int low_indx=low,high_indx=high;
	while(high>=low){
		while(arr[low]<arr[pivot])low++;
		while(arr[high]>arr[pivot])high--;
		if(low<=high){
			swap(&arr[low],&arr[high]);
			low++;high--;
		}
	}
	quicksort(arr,low,high_indx);
	quicksort(arr,low_indx,high);
}
int main(){
	int arr[]={23,1,43,12,53,5,65,34};
	int n=sizeof(arr)/sizeof(arr[0]),i;
	quicksort(arr,0,n-1);
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
}