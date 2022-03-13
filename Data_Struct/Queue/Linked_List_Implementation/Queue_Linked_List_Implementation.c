#include<stdio.h>
#include<stdlib.h>

struct queue{
	int data;
	struct queue *next;
};

struct queue *front=NULL;
struct queue *rear=NULL;

void enqueue(int x){
	struct queue *t;
	t=(struct queue*)malloc(sizeof(struct queue));
	if(t==NULL){
		printf("Queue is FULL");
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
	struct queue *t;
	if(front==NULL){
		printf("Queue is EMPTY");
	}
	else{
		x=front->data;
		t=front;
		front=front->next;
		free(t);
	}
	return x;
}

void display(){
	struct queue *p;
	p=front;
	while(p!=NULL){
		printf("%d\n", p->data);
		p=p->next;
	}
}
int isEmpty(){
	return front==NULL;
}
int main(){
	int a;
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	//display();
	printf("\n");
	while(!isEmpty()){
	a=dequeue();
	}
	
	return 0;
}
