//Selection sort program
#include<stdio.h>
void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main(){
	int arr[] = {23,12,45,8,28,83,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	int i,j,min;
	for(i=0;i<n-1;i++){
		min = i;
		for(j=i+1;j<n;j++){
			if(arr[min] > arr[j])
				min = j;
		}
		if(i!=min)
			swap(&arr[i],&arr[min]);
	}
	for(i=0;i<n;i++){
		printf("%d\t", arr[i]);
	}
	return 0;
}