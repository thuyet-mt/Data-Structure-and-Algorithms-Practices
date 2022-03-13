#include"queue.h"
#ifndef stack_h
#define stack_h

struct stack{
	int size;
	int top;
	struct node **S;
};

void Stackcreate(struct stack *st, int size){
	st->size=size;
	st->top=-1;
	st->S=(struct node**)malloc(st->size * sizeof(struct node*));
}

void push( struct stack *st, struct node *x){
	if(st->top==st->size-1){
		printf("Stack OVERFLOW");
	}
	else{
		st->top++;
		st->S[st->top]=x;
	}
}

struct node *pop (struct stack *st){
	struct node *x=NULL;
	if(st->top=-1){
		printf("Stack UNDERFLOW");
	}
	else{
		st->top--;
		x=st->S[st->top];	
	}
	return x;
}

int isEmptyStack(struct stack st){
	if(st.top==-1){
		return 1;
	}
	return 0;	
}

int isFullStack(struct stack st){
	return st.top==st.size-1;
}

#endif /*stack_h*/



