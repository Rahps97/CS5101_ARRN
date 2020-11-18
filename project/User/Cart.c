#include<stdio.h> 
int main() 
{ 	
	char str[] = "ADMIN"; 
	char str1[] = "Welcome 'User name'";
	char str2[] = "Cart";
	char str3[] = "Your Cart"; 
	char str4[] = "Checkout";
	char str5[] = "Enter [Back] to return to Main Page";

	
	printf("\n\n\n\n%63s\n\n" , str );
	printf("%70s\n\n\n\n\n\n\n"  ,str1); 
	
	printf("%62s\n\n\n" , str2 );
	
	int n = 32;
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
	printf("[Active]");
	for(i=1;i<=n;i=i+1){
		printf(" ");
	}
	printf("         \n\n\n\n\n\n");
	
	
	
	printf("%100s\n\n\n" , str5 );
	
	
	char input[50];
	printf("Enter Checkout to checkout your order:-");
	scanf("%s",&input);
	printf("You have selected for: %s",input);
} 

