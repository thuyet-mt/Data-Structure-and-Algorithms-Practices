#include <stdio.h>
#include <conio.h>
#define size 100
void swap(int *x, int *y);
int partition(int a[], int beg, int end);
void quick_sort(int a[], int beg, int end);
void main(){
	int arr[size], i, n;
	printf("\n Enter the number of elements in the array: ");
	scanf("%d", &n);
	printf("\n Enter the elements of the array: ");
	for(i=0;i<n;i++){
 		scanf("%d", &arr[i]);
	}
	quick_sort(arr, 0, n-1);
	printf("\n The sorted array is: \n");
	for(i=0;i<n;i++)
	printf(" %d\t", arr[i]);
	getch();
}
int partition(int a[], int beg, int end){
	int left, right, temp, pivot, flag;
	pivot = left = beg;
	right = end;
	flag = 0;
	while(flag != 1){
		while((a[pivot] <= a[right]) && (pivot!=right))
			right--;
		if(pivot==right)
 			flag =1;
 		else if(a[pivot]>a[right]){
 			swap(&a[pivot], &a[right]);
 			pivot = right;
 		}
		if(flag!=1){
				while((a[pivot] >= a[left]) && (pivot!=left))
				left++;
			if(pivot==left)
				flag =1;
			else if(a[pivot] <a[left]){
			 	swap(&a[pivot], &a[left]);
				pivot = left;
			}
		}
	}
	return pivot;
}
void quick_sort(int a[], int beg, int end){
	int pivot;
	if(beg<end){
		pivot = partition(a, beg, end);
		quick_sort(a, beg, pivot-1);
		quick_sort(a, pivot+1, end);
	}
}
void swap(int *x, int *y) {   
    int temp;

    temp = *x;     
    *x = *y;           
    *y = temp;    
}

