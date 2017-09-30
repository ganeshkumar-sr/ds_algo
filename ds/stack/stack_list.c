//Stack program using linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int element;
	struct node *next;
};
struct node *root = NULL;
struct node* createnewnode(int a){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->element = a;
}
void push(int a){
	struct node* new = createnewnode(a);
	new->next = root;
	root = new;
	printf("\n %d pushed into the Stack",a);
}
void pop(){
	if(root==NULL){
		printf("\nStack is empty");
	}
	else{
		struct node *temp = root;
		root = root->next;
		printf("\npopped element - %d",temp->element);
		free(temp);
	}
}
void peek(){
	if(root == NULL){
		printf("\nStack is empty");
	}
	else{
		printf("\nTop of the Stack - %d",root->element);
	}
}
int main(){
	push(1);
	push(2);
	peek();
	pop();
	pop();
	peek();
	push(5);
	push(6);
	return 0;
}