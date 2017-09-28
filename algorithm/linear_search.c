//Linear search program
#include<stdio.h>
int linearsearch(int *arr,int size,int element){
	int i;
	for(i=0;i<size;i++){
		if(arr[i] == element){
			return i+1;
			break;
		}
	}
	return -1;
}
int main(){
	int arr[]={23,44,54,34,22,75,3,5};
	int size = sizeof(arr)/sizeof(arr[0]);
	int index= linearsearch(arr,size,34);
	if(index == -1)
		printf("Element not found");
	else
		printf("Element found at position- %d",index);
	return 0;
}