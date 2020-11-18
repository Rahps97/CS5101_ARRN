#include<stdio.h> 
int main() 
{ 	
	char str[] = "USER"; 
	char str1[] = "Welcome 'User name'";
	char str2[] = "Book Search";
	char str3[] = "Search For Customer by ID"; 
	char str4[] = "Search For Customer by Name";
	char str5[] = "Enter [Back] to return to Main Page";
	
	printf("\n\n\n\n%62s\n\n" , str );
	printf("%70s\n\n\n\n\n\n\n"  ,str1); 
	
	printf("%66s\n\n\n" , str2 );
	
	int n = 23;
	int i;
	for(i=1;i<=n;i=i+1){
		printf(" ");
	}
	i = 0;
	printf("%s",str3);
	for(i=1;i<=n;i=i+1){
		printf(" ");
	}
	printf("%s\n",str4);
	
	n = 32;
	i = 0 ;
	for(i=1;i<=n;i=i+1){
		printf(" ");
	}
	i = 0;
	printf("");
	for(i=1;i<=n;i=i+1){
		printf(" ");
	}
	printf("               [Active]\n\n\n\n\n\n");
	
	
	
	
	printf("%100s\n\n\n" , str5 );
	
	char input[50];
	printf("Enter Customer Name:-");
	scanf("%s",&input);
	printf("You have searched for: %s",input);
} 

