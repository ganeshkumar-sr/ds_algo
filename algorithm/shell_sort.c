//Shell sort program with gap sequence N/2 power K
#include<stdio.h>
void shellsort(int arr[],int n){
	int gap,i,j;
	for(gap=n/2;gap>0;gap/=2){
		for(i=gap;i<n;i++){
			int temp = arr[i];
			for(j=i;j>=gap && arr[j-gap]>temp;j-=gap){
				arr[j] = arr[j-gap];
			}
			arr[j]=temp;
		}
	}
}
int main(){
	int arr[]={93,12,45,8,28,83,2,22,14,1,34};
	int n=sizeof(arr)/sizeof(arr[0]),i;
	shellsort(arr,n);
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	return 0;
}