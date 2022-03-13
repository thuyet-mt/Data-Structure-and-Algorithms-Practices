#include<stdio.h>
void Insert(int A[], int n);
int Delete(int A[], int n);
void swap(int *x, int *y);
int main(){
	//Remember, the first element in H, means H[0] always stand for 0 and it isn't used!!!
	int H[]={0, 20, 60, 19, 8, 71, 94, 25, 36, 89, 17, 69, 34};
//	int H[]={0, 10, 20, 30, 25, 5, 40, 35};
//	int H[]={0, 45, 36, 54, 27, 63, 72, 61, 18};
	int i;
	for(i=2;i<=12;i++){
		Insert(H, i);
	}
	for(i=1;i<=12;i++){
		printf("%d ", H[i]);
	}
	printf("\n");
	for(i=12;i>1;i--){
		Delete(H, i);
	}
	for(i=1;i<=12;i++){
		printf("%d ", H[i]);
	}
}
void Insert(int A[], int n){
	int i=n, temp;
	temp=A[i];
	while(i>1 && temp>A[i/2]){
		A[i]=A[i/2];
		i=i/2;
	}
	A[i]=temp;
}
int Delete(int A[], int n){
	int i, j, x, val;
	val=A[1];
	x=A[n];
	A[1]=A[n];
	A[n]=val;
	i=1;                 // Ex: suppose that a node has index i=2; so it's left children has index j=2*i=4
	j=i*2;			                       	   //    and it's right children has index j=2*i+1=5
	// compare left children & right children of node!!!
	while(j<n-1){            
		if(A[j+1]>A[j]){  
			j=j+1;
		}
		if(A[i]<A[j]){
			swap(&A[i], &A[j]);
			i=j;
			j=2*j;
		}
		else break;	
	}
	return val;
}

void swap(int *x, int *y) {   //Luu ý *
    int swapInt;
    
    swapInt = *x;     //Luu ý *
    *x = *y;            //Luu ý *
    *y = swapInt;    //Luu ý *
} 
