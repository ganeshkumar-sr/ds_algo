//Binary insertion sort
#include<stdio.h>
int binarysearch(int arr[],int key,int low,int high);
int main(){
	int arr[] = {23,12,45,8,28,83,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	int i,loc;
	for(i=1;i<n;i++){
		int j = i-1;
		int key = arr[i];
		loc = binarysearch(arr,key,0,j);
		while(j >= loc){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
	for(i=0;i<n;i++){
		printf("%d\t", arr[i]);
	}
	return 0;
}
int binarysearch(int arr[],int key,int low,int high){
	if(high <= low)
		return key > arr[low] ? low+1 : low;
	int mid = (low +high) / 2;
	if( key == arr[mid])
		return mid;
	if( key > arr[mid])
		return binarysearch(arr,key,mid+1,high);
	return binarysearch(arr,key,low,mid-1);
}