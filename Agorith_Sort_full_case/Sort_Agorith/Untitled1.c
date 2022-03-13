#include<stdio.h>
#define max 5
int main(){
	int a[max];
	int i;
	for(i=0;i<max;i++){
		scanf("%d", &a[i]);
	}
	for(i=0;i<max;i++){
		printf("%d\t", a[i]);
	}
	printf("\n");
	for(i=0;i<max;i++){
		if(a[i]%3==0&&a[i]>10)
			printf("%d\t",a[i]);
	}
}
