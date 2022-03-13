#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct element{
	int year;
	int people;
};
struct element A[MAX];
void Create_Array(struct element A[]){   
	int i, m;
	printf("\n number index (start from 0, =last year-first year)= ");
	scanf("%d", &m);
	for(i=0;i<=m;i++){
		printf("\nEnter informaton of element %d", i);
		printf("\nYear= "); scanf("%d", &A[i].year);
		printf("People=");scanf("%d", &A[i].people);
	}
}
void Display_Array(struct element A[]){ 
	int i,m, sum=0;
	printf("\n number index (start from 0, =last year-first year)= ");
	scanf("%d", &m);
	for(i=0;i<=m;i++){
		if(A[i].year<2015)
			sum=sum+A[i].people;
	}
	printf("Sum= %d", sum);
}
int main(){
	int i, n, f, l;
	printf("Enter first year=");
	scanf("%d", &f);
	printf("Enter last year=");
	scanf("%d", &l);
	printf("This proceed will go through %d years, from %d to %d",n=l-f+1, f, l);
	Create_Array(A);
	Display_Array(A);
}
