#include<stdio.h> 
int main() 
{ 	
	char str[] = "USER"; 
	char str1[] = "Welcome 'User name'";
	char str2[] = "Book Search";
	char str3[] = "Search For Book by ID"; 
	char str4[] = "Search For Book by Name";
	char str5[] = "Your Cart";
	char str6[] = "Open Cart";  
	char str7[] = "Check Out";  
	char str8[] = "Log Out"; 
	
	printf("\n\n\n\n%62s\n\n" , str );
	printf("%70s\n\n\n\n\n\n\n"  ,str1); 
	
	printf("%66s\n\n\n" , str2 );
	
	int n = 25;
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
	
	n = 34;
	i = 0 ;
	for(i=1;i<=n;i=i+1){
		printf(" ");
	}
	i = 0;
	printf("(1)");
	for(i=1;i<=n;i=i+1){
		printf(" ");
	}
	printf("         (2)\n\n\n\n\n\n");
	
	
	
	
	
	
	
	printf("%65s\n\n\n" , str5 );
	
	n = 31;
	i = 0;
	for(i=1;i<=n;i=i+1){
		printf(" ");
	}
	i = 0;
	printf("%s",str6);
	for(i=1;i<=n;i=i+1){
		printf(" ");
	}
	printf("     %s\n",str7);
	
	n = 34;
	i = 0 ;
	for(i=1;i<=n;i=i+1){
		printf(" ");
	}
	i = 0;
	printf("(3)");
	for(i=1;i<=n;i=i+1){
		printf(" ");
	}
	printf("         (4)\n\n\n\n\n\n");
	
	
	
	
	char str9[] = "(5)";
	printf("%115s\n" , str8 );
	printf("%113s\n\n\n" , str9 );
	
	
	
	
	int input;
	printf("Enter your option here:-");
	scanf("%d",&input);
	printf("You have chosen option:- %d",input);
} 

