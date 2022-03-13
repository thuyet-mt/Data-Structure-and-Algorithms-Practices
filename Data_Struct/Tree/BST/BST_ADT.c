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
		printf("%d\t", p->data);
		In_Order(p->rchild);
	}
}
void Pre_order(struct node *p){
	if(p!=NULL){
		printf("%d\t", p->data);
		Pre_order(p->lchild);
		Pre_order(p->rchild);
	}
}
void Post_order(struct node *p){
	if(p){
		Post_order(p->lchild);
		Post_order(p->rchild);
		printf("%d\t", p->data);
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
int height(struct node *p){
	int x, y;
	if(p==NULL){
		return 0;
	}
	x=height(p->lchild);
	y=height(p->rchild);
	return x>y?x+1:y+1;
}

struct node *InPre(struct node *p){
	while(p!=NULL&&p->rchild!=NULL){
		p=p->rchild;
	}
	return p;	
}

struct node *InSucc(struct node *p){
	while(p!=NULL&&p->lchild!=NULL){
		p=p->lchild;
	}
	return p;	
}
struct node *delete(struct node *p, int key){
	struct node *q;
	if(p==NULL){
		return NULL;
	}
	if(p->lchild==NULL && p->rchild==NULL ){
		if(p==root){
			root=NULL;
		}
		free(p);
		return NULL;
	}
	
	if(key<p->data){
		p->lchild=delete(p->lchild, key);
	}
	else if(key>p->data){
		p->rchild=delete(p->rchild, key);
	}
	else{
		if(height(p->lchild)>height(p->rchild)){
			q=InPre(p->lchild);
			p->data=q->data;
			p->lchild=delete(p->lchild, q->data);
		}
		else{
			q=InSucc(p->rchild);
			p->data=q->data;
			p->rchild=delete(p->rchild, q->data);
		}
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
//	40, 30, 65, 25, 50, 76, 35, 10, 28, 27, 73, 36, 34
	root=R_Insert(root, 40);
	R_Insert(root, 30);
	R_Insert(root, 65);
	R_Insert(root, 25);
	R_Insert(root, 50);
	R_Insert(root, 76);
	R_Insert(root, 35);
	R_Insert(root, 10);
	R_Insert(root, 28);
	R_Insert(root, 27);
	R_Insert(root, 73);
	R_Insert(root, 36);
	R_Insert(root, 34);
	delete(root, 30);
	printf("In_Order\n");
	In_Order(root);
	printf("\n");
	printf("Post_Order\n");
	Post_order(root);
	printf("\n\n");
	printf("Pre_order\n");
	Pre_order(root);
	printf("\n\n");
	temp=search(20);
	if(temp!=NULL){
		printf("\nelement %d is found!", temp->data);
	}
	else{
		printf("\nelement is not found!");
	}
	return 0;
}
