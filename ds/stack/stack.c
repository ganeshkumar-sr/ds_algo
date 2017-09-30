//Stack using array
#include<stdio.h>
#define MAX 5
int top=-1;
int stack[MAX];
void push(int n){
	if(top >= MAX-1){
		printf("\nstack is full");
	}
	else{
		stack[++top]=n;
		printf("\n %d pushed into the stack",n);
	}
}
void pop(){
	if(top == -1)
		printf("\nStack is empty");
	else
		printf("\nPopped element - %d", stack[top--]);
}
void peek(){
	if(top == -1)
		printf("\nStack is empty");
	else
		printf("\nTop of the stack - %d",stack[top]);
}
int main(){
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	peek();
	pop();
	peek();
	push(5);
	push(6);
	return 0;
}