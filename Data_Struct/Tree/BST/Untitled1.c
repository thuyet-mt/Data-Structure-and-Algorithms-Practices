#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *lchild;
	int data;
	struct node *rchild;
};

struct node *root=NULL;

void insert(int key){
	struct node *t;
	t=root;
	struct node *r=NULL, *p;
	
	if(root==NULL){
		p=(struct node*)malloc(sizeof (struct node));
		p->data=key;
		p->lchild=p->rchild=NULL;
		root=p;
		return;
	}
	while(t!=NULL){
		r=t;
		if(key<t->data){
			t=t->lchild;
		}
		else if(key>t->data){
			t=t->rchild;
		}
		else{
			return;
		}
	}
	p=(struct node*)malloc(sizeof (struct node));
	p->data=key;
	p->lchild=p->rchild=NULL;
	if(key<r->data){
		r->lchild=p;
	}
	else if(key>r->data){
		r->rchild=p;
	}
}

void In_Order(struct node *p){
	if(p!=NULL){
		In_Order(p->lchild);
		printf("%d", p->data);
		In_Order(p->rchild);
	}
}

struct node *search(int key){
	struct node *t=root;
	while(t!=NULL){
		if(key==t->data){
			return t;
		}
		else if (key<t->data){
			t=t->lchild;
		}
		else{
			t=t->rchild;
		}
	}
	return NULL;
}

struct node *R_Insert(struct node *p, int key){
	struct node *t=NULL;
	if(p==NULL){
		t=(struct node*)malloc(sizeof (struct node));
		t->data=key;
		t->lchild=t->rchild=NULL;
		//p=t;
		return t;
	}
	if(key<p->data){
		p->lchild=R_Insert(p->lchild, key);
	}
	else if(key>p->data){
		p->rchild=R_Insert(p->rchild, key);
	}
	return p;
}

int main(){
	struct node *temp;
  /*insert(10);
	insert(5);
	insert(20);
	insert(8);
	insert(30);*/
	root=R_Insert(root, 10);
	R_Insert(root, 5);
	R_Insert(root, 20);
	R_Insert(root, 8);
	R_Insert(root, 30);
	
	In_Order(root);
	temp=search(20);
	if(temp!=NULL){
		printf("\n%d", temp->data);
	}
	else{
		printf("not found");
	}
	return 0;
}
