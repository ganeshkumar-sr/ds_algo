//Heap sort program
#include<stdio.h>
void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void heapify(int *arr,int k,int n){
	while(2*k+1<n){
		int child = 2*k+1;
		if(child+1 < n && arr[child]<arr[child+1]){
			child++;
		}
		if(arr[k]<arr[child]){
			swap(&arr[k],&arr[child]);
			k=child;
		}
		else{
			return;
		}
	}
}
void heapsort(int *arr,int n){
	int i;
	for(i=n/2;i>=0;i--){
		heapify(arr,i,n);
	}
	while(n-1>0){
		swap(&arr[0],&arr[n-1]);
		heapify(arr,0,n-1);
		n--;
	}
}
int main(){
	int arr[]={23,45,26,3,65,12,43,78,4,54};
	int n = sizeof(arr)/sizeof(arr[0]),i;
	heapsort(arr,n);
	for(i=0;i<n;i++)
		printf("%d\t", arr[i]);
	return 0;
}