//Counting sort program
#include<stdio.h>
#define MAX 50
void countingsort(int *arr,int n){
	int b[n],c[MAX],i;
	for(i=0;i<MAX;i++)
		c[i]=0;
	for(i=0;i<n;i++)
		c[arr[i]]++;
	for(i=1;i<MAX;i++){
		c[i]+=c[i-1];
	}
	for(i=0;i<n;i++){
		b[c[arr[i]]-1] = arr[i];
		c[arr[i]]--;
	}
	for(i=0;i<n;i++)
		arr[i]=b[i];
}
int main(){
	int arr[]={12,43,12,45,23,34,23,5,23,5};
	int n = sizeof(arr)/sizeof(arr[0]),i;
	countingsort(arr,n);
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
	return 0;
}