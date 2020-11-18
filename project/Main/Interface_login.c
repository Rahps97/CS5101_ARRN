#include<stdio.h> 
int main() 
{ 
	char str1[] = "Welcome To 'Cozastore'"; 
	char str2[] = "Sign In"; 
	char str3[] = "Sign Up"; 
	
	printf("\n\n\n\n%70s\n\n\n\n\n\n\n"  ,str1); 
	int n = 35;
	int i;
	for(i=1;i<=n;i=i+1){
		printf(" ");
	}
	i = 0;
	printf("%s",str2);
	for(i=1;i<=n;i=i+1){
		printf(" ");
	}
	printf("%s\n",str3);
	
	n = 37;
	i = 0 ;
	for(i=1;i<=n;i=i+1){
		printf(" ");
	}
	i = 0;
	printf("(1)");
	for(i=1;i<=n;i=i+1){
		printf(" ");
	}
	printf("  (2)\n\n\n\n\n\n",str3);
	
	
	
	int input;
	printf("Enter your option here:-");
	scanf("%d",&input);
	printf("You have chosen option:- %d",input);
} 

