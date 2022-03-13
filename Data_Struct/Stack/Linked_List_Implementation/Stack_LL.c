#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node *top = NULL;

void push(int x){
	struct node *t;
	t=(struct node*)malloc(sizeof(struct node));
	if(t==NULL){
		printf("Stack OVERFLOW");
	}
	else{
		t->data=x;
		t->next=top;
		top=t;
	}
}

int pop(){
	struct node *p;
	int x=-1;
	if(top==NULL){
		printf("Stack UNDERFLOW");
	}
	else{
		p=top;
		top=top->next;
		x=p->data;
		free(p);
	}
	return x;
}

int peek(int pos){
	int i;
	struct node *p;
	p=top;
	for(i=0;p!=NULL&&i<pos-1;i++){
		p=p->next;
	}
	if(p!=NULL){
		return p->data;
	}
	else{
		return -1;
	}
}

int stack_top(){
	if (top){   //top!=NULL;
		return top->data;
	}
	else{
		return -1;
	}
}

void display(){
	struct node *p;
	p=(struct node*)malloc(sizeof(struct node));
	p=top;
	while(p!=NULL){
		printf("%d\n", p->data);
		p=p->next;
	}
	free(p);
}

int main(){
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	display();
	
	printf("\n");
	pop();
	pop();
	display();


	
}
