#include<stdio.h>
#include<stdlib.h>
#define BUCKET 6
#define INTER 10
struct node{
	int data;
	struct node *next;
};
struct node **bucket;
struct node * sort(struct node* list){
	if(list == 0 || list->next == 0){
		return list;
	}
	struct node *nodelist,*k;
	nodelist = list;
	k = list->next;
	nodelist->next = 0;
	while(k!=0){
		struct node *ptr;
		if(nodelist->data > k->data){
			struct node *tmp = k;
			k=k->next;
			tmp->next = nodelist;
			nodelist = tmp;
			continue;
		}
		for(ptr = nodelist;ptr->next!=0;ptr=ptr->next){
			if(ptr->next->data > k->data)break;
		}
		printf("\ncon");
		if(ptr->next!=0){
			struct node *tmp = k;
			k=k->next;
			tmp->next = ptr->next;
			ptr->next = tmp;
			continue;
		}
		else{
			ptr->next = k;
			k = k->next;
			ptr->next->next = 0;
			continue;
		}
	}
	return nodelist;
}
void printBuckets(struct node *list)
{
	struct node *cur = list;
	while(cur) {
		printf("%d\t",cur->data );
		cur = cur->next;
	}
}
void bucketsort(int arr[],int n){
	bucket = (struct node **)malloc(sizeof(struct node*) * BUCKET); 
	int i,j=0;
	for(i=0;i<BUCKET;i++)
		bucket[i] = NULL;
	for(i=0;i<n;i++){
		int pos = arr[i]/INTER;
		struct node* current = (struct node*)malloc(sizeof(struct node *));
		current->data = arr[i];
		current->next = bucket[pos];
		bucket[pos] = current;
	}
	for(i = 0; i < BUCKET; i++) {
		printf("Bucket[%d]", i);
	        printBuckets(bucket[i]);
		printf("\n");
	}
	for(i=0;i<BUCKET;i++){
		bucket[i] = sort(bucket[i]);
	}
	for(i=0;i<BUCKET;i++){
		if(bucket[i]){
			struct node * buc = bucket[i];
			do{
				arr[j++] = buc->data;
				buc = buc->next;
			}while(buc);
		}
	}
	for(i = 0; i < BUCKET; i++) {
		printf("Bucket[%d]", i);
	        printBuckets(bucket[i]);
		printf("\n");
	}
}

int main(){
	int arr[]={23,4,25,56,35,2,42,45,1};
	int n = sizeof(arr)/sizeof(arr[0]),i;
	bucketsort(arr,n);
	for(i=0;i<n;i++){
		printf("%d\n", arr[i]);
	}
	for(i = 0; i < BUCKET;++i) {	
		struct node *node;
		node = bucket[i];
		while(node) {
			struct node *tmp;
			tmp = node; 
			node = node->next; 
			free(tmp);
		}
	}
	free(bucket); 
	return 0;
}