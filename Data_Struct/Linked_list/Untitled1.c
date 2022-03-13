#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int ID;
	char Name[20];
	struct node *next;
};
struct node *start=NULL;
struct node *create_linkedlist(struct node *start){
	struct node *new_node, *ptr;
	int ID;
	char Nam[20];
	printf("\nEnter ID = -1 to end");
	printf("\nEnter ID = ");
	scanf("%d", &ID);
	printf("\nEnter Name = ");
	scanf("%s", &Nam);
	while(new_node->ID!=-1){		
		new_node=(struct node*)malloc(sizeof (struct node));
		new_node->ID=ID;
		strcpy(new_node->Name[20],Nam[20]);
		if(start==NULL){
			new_node->next=NULL;
			start=new_node;
		}
		else{
			ptr=start;
			while(ptr->next!=NULL){
				ptr=ptr->next;	
			}
			ptr->next=new_node;
			new_node->next=NULL;
		}
		printf("\nEnter -1 to end");
		printf("\nEnter ID = ");
		scanf("%d", &new_node->ID);
		printf("\nEnter Name = ");
		scanf("%s", &new_node->Name);
	}
	return start;
}
int main(){
	create_linkedlist(start);
	printf("\n LINKED LIST CREATED");
}
