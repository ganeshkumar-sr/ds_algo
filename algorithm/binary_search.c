//Binary search program
#include<stdio.h>
int binarysearch(int *arr,int l,int r,int element){
	if(l>r)
		return -1;
	int mid = l+(r-1)/2;
	if(arr[mid]==element)
		return mid+1;
	else if(arr[mid]>element)
		return binarysearch(arr,l,mid-1,element);
	else
		return binarysearch(arr,mid+1,r,element);
}
int main(){
	int arr[] = {12,34,55,56,76,78,98,99};
	int n = sizeof(arr)/sizeof(arr[0]);
	int index = binarysearch(arr,0,n-1,99);
	if(index==-1)
		printf("Element not found");
	else
		printf("Element found at position- %d",index);
	return 0;
}