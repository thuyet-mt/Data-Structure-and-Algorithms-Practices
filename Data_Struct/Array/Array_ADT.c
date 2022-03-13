#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct Array{
	int *A;
	int size;
	int length;  
};

void Create_Array( struct Array *arr);
void Display(struct Array *arr);
void Insert(struct Array *arr);
void Delete(struct Array *arr);
void Search(struct Array *arr);
void Get(struct Array *arr);
void Get_Max(struct Array *arr);
void Get_Min(struct Array *arr);
void Sum_All_Elements(struct Array *arr);
void Reverse_Array(struct Array *arr);
void R_BS(struct Array *arr, int key);
void bubble_sort(struct Array *arr);

int main(int argc, char *argv[]) {
    int option;
    struct Array arr;
        do{
            printf("\n\n *****MAIN MENU *****");
            printf("\n 1:  Create Array");
            printf("\n 2:  Display Array");
            printf("\n 3:  Add a value");
            printf("\n 4:  Delete a value");
            printf("\n 5:  Search a value");
            printf("\n 6:  Search a value using R_BS");
            printf("\n 7:  Get a value");
            printf("\n 8:  Get value of max element");
            printf("\n 9:  Get value of min element");
            printf("\n 10:  Get sum of all element");
            printf("\n\n Enter your option: ");
            scanf("%d", &option);
            switch(option){
                
				case 1: Create_Array(&arr);
                        break;
               
			    case 2: Display(&arr);
                        break; 
               
			    case 3: Insert(&arr);
                        break;
                        
                case 4: Delete(&arr);
                		break;
                		
        		case 5: Search(&arr);
        				break;

				case 6: Get(&arr); //PROBLEM!!!!!!!!!!
        				break;	
							
        		case 7: Get_Max(&arr);
        				break;	
        				
        		case 8: Get_Min(&arr);
        				break;	
        				
        		case 9: Sum_All_Elements(&arr);
        				break;	
				case 10: Reverse_Array(&arr);
        				break;	
        		//case 11: R_BS(&arr, int key);	
				//		break;	
				case 13: Sort_Array(&arr);
						break;
            } 
        }
    while(option !=12);
    getchar();
    return 0;
}
void Create_Array( struct Array *arr){
	printf("Enter size of array\n");
	scanf("%d", &arr ->size);
	arr->A=(int*)malloc( (arr->size)*sizeof(int));
	arr->length=0;
	int n,i;
	printf("Enter number of element\n");
	scanf("%d", &n);
	if( n> arr->size){
		printf("Stack_Over_Flow");
	}
	else{
		printf("Enter element of array\n");
		for(i=0;i<n;i++){
			scanf("%d", &arr->A[i]);
		}
		arr->length=n;
		printf("Array created!\n");
	}	
}
void Display(struct Array *arr){
	int i;
	printf("All elements are\n");
	for(i=0;i<arr->length;i++){
		printf("%d\n", arr->A[i]);
	}
}
void Insert(struct Array *arr){
	int index, value;
	printf("Enter index you want to insert: ");
	scanf("%d",&index);
	printf("Enter value you want: ");
	scanf("%d",&value);
	if( index > (arr->length-1)){
		arr->A[index]=value;
		arr->length=index+1;
	}
	else{
		int i;
		for(i=arr->length;i>index;i--){
			arr->A[i]=arr->A[i-1];
		}
		arr->A[index]=value;
		arr->length++;
	}
}
void Delete(struct Array *arr){
	int i, index;
	printf("Enter index you want to delete: ");
	scanf("%d",&index);
	for(i=index; i<=arr->length;i++){
		arr->A[i]=arr->A[i+1];
	}
	arr->length--;
}
void Search(struct Array *arr){	

	int i, value;
	
	int count = 0;
	
	printf("Enter value of element you want to seach: ");
	scanf("%d", &value);
	
	for (i=0; i<=arr->size;i++){
		
		if(arr->A[i]==value){
			printf("The element you need is %d has index = %d\n", arr->A[i], i);
			count++;			
		}
	}
	if(count == 0)
		printf("there is no element you need!");		
}
/*void R_BS(struct Array *arr, int key){
	int l, mid, h;
	l=0;
	h=arr->length-1;
	if(l<=h){
		mid=((l+h)/2;
		if(key=arr->A[mid]){
			printf("\n %d is present in the array at index %d", key, mid);
		}
		else if (key<arr->A[mid]){
			l=0;
			h=mid-1;
			R_BS(arr, key);
		}	
		else{
			l=mid+1;
			h=arr->length-1;
			R_BS(arr, key);
		} 		
	}
	else
		printf("There is no element you need!");
}*/


// For example, I initialize my array has size=5 and 4 elements ={1, 2, 3, 4}

void Get(struct Array *arr){
	int index, index_max=arr->length-1;
	if(arr->length>2)
		printf("Now, your array has size: %d  and %d elements \n", arr->size, arr->length);
	else 
		printf("Now, your array has size: %d  and %d element \n", arr->size, arr->length);

	printf("Enter index: ");
	scanf("%d", &index);
	if(index>arr->size){
		printf("Index= %d has bigger than array's size=%d , please enter smaller index!" , index, arr->size ); //index=
		Get(arr);   
	}

	else if((index>=arr->length)&&(index<=arr->size))
		printf("There is no element in this index");							//index=4
	else
		printf("The element in index %d has value %d", index, arr->A[index]);	//index=3, 5
}

void Get_Max(struct Array *arr){
	int i, j, Max = arr->A[0];
	for(i=0;i<arr->length;i++){
		if(Max<arr->A[i]){
			Max=arr->A[i];
		}
	}
	for(j=0;j<arr->length;j++){
		if(Max==arr->A[j]){
			printf("Max element = %d has index = %d", Max, j);
		}
	}
}
void Get_Min(struct Array *arr){
	int i, j, Min = arr->A[0];
	for(i=0;i<arr->length;i++){
		if(Min>arr->A[i]){
			Min=arr->A[i];
		}
	}
	for(j=0;j<arr->length;j++){
		if(Min==arr->A[j]){
			printf("Min element = %d has index = %d", Min, j);
		}
	}
}
void Sum_All_Elements(struct Array *arr){
	int i,s=0;
	for(i=0;i<arr->length;i++){
		s=s+arr->A[i];
	}
	printf("Sum of all elements in array = %d", s);
}
void Reverse_Array(struct Array *arr){
	struct Array *brr;
	brr->size=arr->size;
	brr->A=(int*)malloc((brr->size)*sizeof(int));
	int i, j, m, n;
	for(i=arr->length-1,j=0;i>=0;j<brr->length,j++){
		brr->A[j]=arr->A[i];
	}
	for(m=0;m<brr->length;m++){
		arr->A[m]=brr->A[m];
	}
	for(n=0;n<brr->length;n++){
		printf("%d\n", arr->A[n]);
	}
}

void Sort_Array(struct Array *arr){
	int i,j, temp;
	for(i=0;i<=arr->length;i++){
		for(j=0;j<(arr->length-i-1);j++){
			if(arr->A[j] > arr->A[j+1]){
				temp = arr->A[j];
				arr->A[j] = arr->A[j+1];
				arr->A[j+1] = temp;
			}
		}
	}
}





