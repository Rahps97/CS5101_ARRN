#include<stdio.h> 
#include <stdlib.h>
int main() 
{ 
	char str1[] = "Welcome To 'Store name'"; 
	char str2[] = "Sign Up"; 
	char strName[] = "Name";
	char strUsername[] = "Username";
	char strPassword[] = "Password"; 
	char str5[] = "Enter [Back] to return to Main Page";
	
	




			/*  Taking firstName                     */ 

	
	printf("\n\n\n\n%70s\n\n\n\n\n\n\n"  ,str1); 
	int n = 35;
	int i;

	printf("%63s\n\n\n",str2);
	
	printf("%58s:_____ _____\n",strName );
	printf("%58s :___________\n", strUsername);
	printf("%58s :___________\n\n\n\n\n\n", strPassword);
	
	
	char firstname[50];
	printf("Enter Your First Name:-");
	scanf("%s",&firstname);
	
	
			/*  taking last name*/
			
	system("cls");
	
	
	
	printf("\n\n\n\n%70s\n\n\n\n\n\n\n"  ,str1); 
	n = 35;


	printf("%63s\n\n\n",str2);
	
	printf("%58s:",strName );
	printf("%s _____\n",firstname);
	printf("%58s :___________\n", strUsername);
	printf("%58s :___________\n\n\n\n\n\n", strPassword);
	
	char lastname[50];
	printf("Enter Your Last Name:-");
	scanf("%s",&lastname);
	
	
	
	
	
			/*  Taking Username                     */ 	
	
	
	system("cls");
	
	
	
	printf("\n\n\n\n%70s\n\n\n\n\n\n\n"  ,str1); 
	n = 35;


	printf("%63s\n\n\n",str2);
	
	printf("%58s:",strName );
	printf("%s ",firstname);
	printf("%s\n", lastname);
	printf("%58s :___________\n", strUsername);
	printf("%58s :___________\n\n\n\n\n\n", strPassword);
	
	char username[50];
	printf("Enter Your Username:-");
	scanf("%s",&username);
	
	
	
	
	
			/*  Taking Password                     */ 
	
	system("cls");
	
	
	
	printf("\n\n\n\n%70s\n\n\n\n\n\n\n"  ,str1); 
	n = 35;


	printf("%63s\n\n\n",str2);
	
	printf("%58s:",strName );
	printf("%s ",firstname);
	printf("%s\n", lastname);
	printf("%58s :", strUsername);
	printf("%s\n",username);
	printf("%58s :___________\n\n\n\n\n\n", strPassword);
	
	
	
	
	
	
	
	//printf("\n\n%100s\n\n\n" , str5 );
	
	
	char password[50];
	printf("Enter Your Password:-");
	scanf("%s",&password);
	
	
	
	



			/*  Taking input "yes" to Login or "no" to back to main menu                      */ 
	
	
	
	
	system("cls");
	
	
	
	printf("\n\n\n\n%70s\n\n\n\n\n\n\n"  ,str1); 
	n = 35;


	printf("%63s\n\n\n",str2);
	
	printf("%58s:",strName );
	printf("%s ",firstname);
	printf("%s\n", lastname);
	printf("%58s :", strUsername);
	printf("%s\n",username);
	printf("%58s :", strPassword);
	printf("%s\n\n\n\n\n\n",password);
	
	
	
	
	
	
	
	//printf("\n\n%100s\n\n\n" , str5 );
	
	char check[50];
	printf("Enter [yes] to Login or [no] to go back to main menu:-");
	scanf("%s",&check);
	
	
	
	/*    check in string check is Login or Back*/
	
	
}
