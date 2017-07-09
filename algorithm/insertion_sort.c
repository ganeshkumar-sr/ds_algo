//Insertion sort program
#include<stdio.h>
int main(){
	int arr[]={23,12,45,8,28,83,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	int i;
	for(i=1;i<n;i++){
		int j = i-1;
		int key = arr[i];
		while(j>=0 && arr[j] > key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	return 0;
}