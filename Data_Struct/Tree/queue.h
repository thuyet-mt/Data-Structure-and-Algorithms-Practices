#ifndef queue_h
#define queue_h

struct node{
	struct node *lchild;
	int data;
	struct node *rchild;
};

struct queue{
	int size;
	int front;
	int rear;
	struct node **Q;
	// struct node * for pointer to struct node
	// *Q for dynamic array
};

void create(struct queue *q, int size){
	q->size=size;
	q->front=q->rear=0;
	q->Q=(struct node**)malloc(q->size * sizeof(struct node*));
}

void enqueue(struct queue *q, struct node *x){
	if((q->rear+1)%q->size==q->front){
		printf("Queue is FULL");
	}		
	else{
		q->rear=(q->rear+1)%q->size;
		q->Q[q->rear]=x;
	}
}


struct node *dequeue(struct queue *q){
	struct node *x=NULL;
	if(q->front==q->rear){
		printf("Queue is EMPTY");
	}		
	else{
		q->front=(q->front+1)%q->size;
		x=q->Q[q->front];
	}
	return x;
}

int isEmpty(struct queue q){
	return q.front==q.rear;
}

#endif /*queue_h*/

