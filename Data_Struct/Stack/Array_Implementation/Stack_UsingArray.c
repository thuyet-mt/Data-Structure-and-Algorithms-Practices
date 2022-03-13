#include<stdio.h>
#include<stdlib.h>
struct stack{
	int size;
	int top;
	int *S;
};
struct stack st;
void create(struct stack *st){
	printf("Enter size = ");
	scanf("%d", &st->size);
	st->top=-1;
	st->S=(int*)malloc(st->size*sizeof(int));
}

void display(struct stack st){
	int i;
	for(i=st.top;i>=0;i--){
		printf("%d\n", st.S[i]);
	}
	printf("\n");
}

void push(struct stack *st, int x){
	if(st->top==st->size-1){
		printf("Stack OVERFLOW");
	}
	else{
		st->top++;
		st->S[st->top]=x;
	}
}

int pop(struct stack *st){
	int x=-1;
	if(st->top==-1){
		printf("Stack UNDERFLOW");
	}
	else{
		x=st->S[st->top--];
	}
	return x;
}

int main(){
	create(&st);
	push(&st, 10);
	push(&st, 20);
	push(&st, 30);
	push(&st, 40);
	pop(&st);
	display(st);
}
