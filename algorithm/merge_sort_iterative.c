//Merge sort program with bottom-up approach using itaration
#include<stdio.h>
void merge(int arr[],int n,int left,int mid,int right){
	int leftend = mid-1;
	int t = left;
	int size = right-left+1;
	int temp[n],i;
	while(leftend>=left && right>=mid){
		if(arr[left]<=arr[mid]){
			temp[t]=arr[left];
			t++;left++;
		}
		else{
			temp[t]=arr[mid];
			t++;mid++;
		}
	}
	while(leftend>=left){
		temp[t]=arr[left];
		t++;left++;
	}
	while(right>=mid){
		temp[t]=arr[mid];
		t++;mid++;
	}
	for(i=0;i<size;i++){
		arr[right]=temp[right];
		right--;
	}

}
int min(int a,int b){
	return a<b?a:b;
}
void mergesort(int arr[],int n){
	int gap,leftstart,mid,right;
	for(gap=1;gap<=n-1;gap*=2){
		for(leftstart=0;leftstart<=n-1;leftstart+=2*gap){
			mid=leftstart+gap;
			right=min(n,leftstart+2*gap-1);
			merge(arr,n,leftstart,mid,right);
		}
	}
}
int main(){
	int arr[] = {34,12,4,35,75,1,46,84,17};
	int n = sizeof(arr)/sizeof(arr[0]),i;
	mergesort(arr,n);
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	return 0;
}