//Bubble sort program
#include<stdio.h>
void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main(){
	int arr[] = {23,12,45,8,28,83,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(arr[j] > arr[j+1])
				swap(&arr[j],&arr[j+1]);
		}
	}
	for(i=0;i<n;i++){
		printf("%d\t", arr[i]);
	}
	return 0;
}