#include<stdio.h>
#include<string.h>
void Get_Length_of_String( char *s){
	int i;
	for(i=0;s[i]!='\0';i++);
	printf("Length of String= %d", i);
}
void Change_Case(char *s){
	int i;
	for(i=0;s[i]!='\0';i++)
		s[i]=s[i]-32;
	printf("%s", s);
}
int main(){
	char *s="welcome";
	Get_Length_of_String(s);
	int i;
	for(i=0;s[i]!='\0';i++)
		s[i]=s[i]-32;
	printf("%s", s);
}


