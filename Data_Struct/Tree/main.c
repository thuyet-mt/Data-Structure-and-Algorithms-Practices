#include <stdio.h>
#include <stdlib.h>
#include"queue.h"
#include"stack.h"

struct node *root=NULL;
void Treecreate();
void Pre_order(struct node *p);
void In_order(struct node *p);
void Post_order(struct node *p);
void Iterative_Pre_Order(struct node *p);
void Iterative_In_Order(struct node *p);
void Level_order(struct node *p);
int main(int argc, char *argv[]) {
	Treecreate();
	Level_order(root);
	Iterative_In_Order(root);
	return 0;
}
void Treecreate(){
	struct node *p, *t;
	int x;
	struct queue q;
	create(&q, 100);
	printf("Enter root value = ");
	scanf("%d", &x);
	root=(struct node*)malloc(sizeof (struct node));
	root->data=x;
	root->lchild=root->rchild=NULL;
	enqueue(&q, root);
	
	while(!isEmpty(q)){
		p=dequeue(&q);
		printf("Enter left child of %d = ", p->data);
		scanf("%d", &x);
		if(x!=-1){
			t=(struct node*)malloc(sizeof (struct node));
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->lchild=t;
			enqueue(&q, t);
		}
		printf("Enter right child of %d = ", p->data);
		scanf("%d", &x);
		if(x!=-1){
			t=(struct node*)malloc(sizeof (struct node));
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->rchild=t;
			enqueue(&q, t);
		}
	}
}

void Pre_order(struct node *p){
	if(p){
		printf("%d\t", p->data);
		Pre_order(p->lchild);
		Pre_order(p->rchild);
	}
}

void In_order(struct node *p){
	if(p){
		In_order(p->lchild);
		printf("%d\t", p->data);
		In_order(p->rchild);
	}
}

void Post_order(struct node *p){
	if(p){
		Post_order(p->lchild);
		Post_order(p->rchild);
		printf("%d\t", p->data);
	}
}

void Iterative_Pre_Order(struct node *p){
	struct stack stk;
	Stackcreate(&stk, 100);
	while (p||!isEmptyStack(stk)){
		if(p){
			printf("%d\t", p->data);
			push(&stk, p);
			p=p->lchild;
		}
		else{
			p=pop(&stk);
			p=p->rchild;
		}
	}
}

void Iterative_In_Order(struct node *p){
	struct stack stk;
	Stackcreate(&stk, 100);
	while (p||!isEmptyStack(stk)){
		if(p){
			push(&stk, p);
			p=p->lchild;
		}
		else{
			p=pop(&stk);
			printf("%d\t", p->data);
			p=p->rchild;
		}
	}
}

void Level_order(struct node *p){
	struct queue q;
	create(&q, 100);
	printf("%d\t", root->data);
	enqueue(&q, root);
	while(!isEmpty(q)){
		root=dequeue(&q);
		if(root->lchild){
			printf("%d\t", root->lchild->data);
			enqueue(&q, root->lchild);
		}
		if(root->rchild){
			printf("%d\t", root->rchild->data);
			enqueue(&q, root->rchild);
		}
	}
}


