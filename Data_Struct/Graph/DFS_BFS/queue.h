#ifndef queue_h
#define queue_h

#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int x){
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));
	if(t==NULL){
		printf("Queue is FULL\n");
	}
	else{
		t->data=x;
		t->next=NULL;
		if(front==NULL){
			front=rear=t;
		}
		else{
			rear->next=t;
			rear=t;
		}
	}
}

int dequeue(){
	int x=-1;
	struct node *t;
	if(front==NULL){
		printf("Queue is EMPTY\n");
	}
	else{
		x=front->data;
		t=front;
		front=front->next;
		free(t);
	}
	return x;
}

int isEmpty(){
	return front==NULL;
}

#endif /*queue_h*/


#include <stdio.h>
int fact(int n);
int main() {
	int x, i;
	printf("Enter a value for x: \n");
	scanf("%d", &x);
	i = fact(x);
	printf("\nFactorial of %d is %d", x, i);
	return 0;
}
int fact(int n) {
	/* n=0 indicates a terminating condition */
	if (n <= 0) {
		return (1);
	} 
	else {
		/* function calling itself */
		return (n * fact(n - 1));
		/*n*fact(n-1) is a recursive expression */
	}
}