//Radix sort program - LSD
#include<stdio.h>
#define BUCKET_SIZE 10
void radixsort(int arr[],int n){
	int tmp[n],max=0,div=1,i;
	for(i=0;i<n;i++){
		if(arr[i]>max)
			max = arr[i];
	}
	while(max/div > 0){
		int bucket[BUCKET_SIZE] = {0};
		for(i=0;i<n;i++){
			bucket[arr[i]/div%10]++;
		}
		for(i=1;i<BUCKET_SIZE;i++)
			bucket[i]+=bucket[i-1];
		for(i=n-1;i>=0;i--){
			tmp[--bucket[arr[i]/div%10]]=arr[i];
		}
		for(i=0;i<n;i++)
			arr[i] = tmp[i];
		div *= 10;
	}

}
int main(){
	int arr[]={23,45,21,7,354,76,97,656,3,54,6,2};
	int n = sizeof(arr)/sizeof(arr[0]),i;
	radixsort(arr,n);
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	return 0;
}