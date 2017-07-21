//Merge  sort program
#include<stdio.h>
void merge(int arr[],int temp[],int l,int m,int r){
	int size = (r-l)+1;
	int i;
	int temp_pos = l;
	int left_end = m-1;
	while(l<=left_end && m<=r){
		if(arr[l]<=arr[m]){
			temp[temp_pos]=arr[l];
			temp_pos=temp_pos+1;
			l=l+1;
		}
		else{
			temp[temp_pos]=arr[m];
			temp_pos=temp_pos+1;
			m=m+1;
		}
	}
	while(l<=left_end){
		temp[temp_pos]=arr[l];
		temp_pos=temp_pos+1;
		l=l+1;
	}
	while(m<=r){
		temp[temp_pos]=arr[m];
		temp_pos+=1;
		m+=1;
	}
	for(i=0;i<size;i++){
		arr[r] = temp[r];
		r-=1;
	}
}
void mergesort(int arr[],int temp[],int l,int r){
	if(r > l){
		int m = (l + r)/2;
		mergesort(arr,temp,l,m);
		mergesort(arr,temp,m+1,r);
		merge(arr,temp,l,m+1,r);
	}
}
int main(){
	int arr[]={93,12,45,8,28,83,2,22,14,1,34};
	int n=sizeof(arr)/sizeof(arr[0]);
	int temp[n],i;
	mergesort(arr,temp,0,n-1);
	for(i=0;i<n;i++){
		printf("%d\t", arr[i]);
	}
	return 0;
}