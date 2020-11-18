#include <stdio.h>
#include <stdlib.h>
#include "headers/login.h"
#include "headers/register.h"
#include "headers/interface.h"
#include <string.h>

void header_interface() {
    system("clear");
	char str1[] = "Welcome To 'Cozastore'"; 
	printf("\n\n\n\n%70s\n\n\n\n\n\n\n"  ,str1); 
}

int ynprompt(char input[])
{
    if(strcmp(input, "yes")==0 | strcmp(input, "y")==0 | strcmp(input, "Y")==0 | strcmp(input, "")==0 | strcmp(input, "Yes")==0) {
        return 0;
    } else {
        return 1;
    }
}

int main_interface()
{
	char str2[] = "Sign In"; 
	char str3[] = "Sign Up"; 
	
    header_interface();
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
	//printf("You have chosen option:- %d",input);
    return input;
}

void login_interface()
{
	char str2[] = "Sign In"; 
	char strUsername[] = "Username"; 
	char strPassword[] = "Password"; 
	char str5[] = "Enter [Back] to return to Main Page";
	
	


			/*  Taking Username                     */ 

	
    header_interface();
	int n = 35;
	int i;

	printf("%63s\n\n\n",str2);
	
	
	printf("%58s :__________\n", strUsername);
	printf("%58s :__________\n\n\n\n\n\n", strPassword);
	
	
	
	
	
	
	
	//printf("\n\n%100s\n\n\n" , str5 );
	
	
	char username[50];
	printf("Enter Your Username:-");
	scanf("%s", username);
	
	
	
	
	
			/*  Taking Password                     */ 
	
	
	
	
    header_interface();
	n = 35;


	printf("%63s\n\n\n",str2);
	
	
	printf("%58s :", strUsername);
	printf("%s\n",username);
	printf("%58s :__________\n\n\n\n\n\n", strPassword);
	
	
	
	
	
	
	
	//printf("\n\n%100s\n\n\n" , str5 );
	
	
	char password[50];
	printf("Enter Your Password:-");
	scanf("%s", password);
	
	
	
	



			/*  Taking input "yes" to Login or "no" to back to main menu                      */ 
	
	
	
	
	
	
	
    header_interface();
	n = 35;


	printf("%63s\n\n\n",str2);
	
	
	printf("%58s :", strUsername);
	printf("%s\n",username);
	printf("%58s :", strPassword);
	printf("%s\n",password);
	
	
	
	
	
	
	
	printf("\n\n%100s\n\n\n" , str5 );
	
	char check[50];
	printf("Enter [yes] to Login or [no] to go back to main menu:-");
	scanf("%s", check);
	
    if(ynprompt(check)==0) {
        login(username, password);
    } else {
        login_interface();
    }
	
	/*    check in string check is Login or Back*/
	
	
}
void register_interface()
{
	char str2[] = "Sign Up"; 
	char strName[] = "Name";
	char strUsername[] = "Username";
	char strPassword[] = "Password"; 
	char str5[] = "Enter [Back] to return to Main Page";
	
	




			/*  Taking firstName                     */ 

	
    header_interface();
	int n = 35;
	int i;

	printf("%63s\n\n\n",str2);
	
	printf("%58s:_____ _____\n",strName );
	printf("%58s :___________\n", strUsername);
	printf("%58s :___________\n\n\n\n\n\n", strPassword);
	
	
	char firstname[50];
	printf("Enter Your First Name:-");
	scanf("%s", firstname);
	
	
			/*  taking last name*/
			
	
	
    header_interface();
	n = 35;


	printf("%63s\n\n\n",str2);
	
	printf("%58s:",strName );
	printf("%s _____\n",firstname);
	printf("%58s :___________\n", strUsername);
	printf("%58s :___________\n\n\n\n\n\n", strPassword);
	
	char lastname[50];
	printf("Enter Your Last Name:-");
	scanf("%s", lastname);
	
	
	
	
	
			/*  Taking Username                     */ 	
	
	
	
	
    header_interface();
	n = 35;


	printf("%63s\n\n\n",str2);
	
	printf("%58s:",strName );
	printf("%s ",firstname);
	printf("%s\n", lastname);
	printf("%58s :___________\n", strUsername);
	printf("%58s :___________\n\n\n\n\n\n", strPassword);
	
	char username[50];
	printf("Enter Your Username:-");
	scanf("%s", username);
	
	
	
	
	
			/*  Taking Password                     */ 
	
	
	
    header_interface();
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
	scanf("%s", password);
	
	
	
	



			/*  Taking input "yes" to Login or "no" to back to main menu                      */ 
	
	
	
	
	
	
    header_interface();
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
	scanf("%s", check);
	
	if(ynprompt(check)==0) {
        regi();
    } else {
        register_interface();
    }
	
	/*    check in string check is Login or Back*/
}
