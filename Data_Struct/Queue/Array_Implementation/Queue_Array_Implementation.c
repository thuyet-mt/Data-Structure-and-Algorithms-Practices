#include<stdio.h>
#include<stdlib.h>

struct queue{
	int size, front, rear;
	int *p;
};
void create( struct queue *q, int size){
	q->size=size;
	q->front=q->rear=-1;
	q->p=(int*)malloc(q->size*sizeof(int));
}
void enqueue( struct queue *q, int x){
	if(q->rear==q->size-1)
		printf("Queue is FULL");
	else{
		q->rear++;
		q->p[q->rear]=x;
	}		
}
int dequeue(struct queue *q){
	int x=-1;
	if(q->front==q->rear)
		printf("Queue is EMPTY");
	else{
		q->front++;
		x=q->p[q->front];
	}
	return x;
}
void display(struct queue q){
	int i;
	for(i=q.front+1;i<=q.rear;i++){
		printf("%d\t", q.p[i]);
	}
}

// CIRCULAR QUEUE
 
void Circular_enqueue (struct queue *q, int x){
	if( (q->rear+1)%(q->size) == q->front ){
		//Neu buoc tiep theo cua rear=front
		printf("Queue is FULL");
	}
	else{
		q->rear=(q->rear+1)%(q->size);
		q->p[q->rear]=x;
	}
} 

void Circular_dequeue (struct queue *q){
	int x=-1;
	if(q->front==q->rear){
		printf("Queue is EMPTY");
	}
	else{
		q->front=(q->front+1)%(q->size);
		x=q->p[q->front];
	}
}

int main(){
	struct queue q;
	create(&q, 5);
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	enqueue(&q, 40);
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	display(q);
}
