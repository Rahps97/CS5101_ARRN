#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#include <assert.h> 
#include "headers/userstruct.h"
#include "headers/register.h"
#include "headers/login.h"
#include "headers/db.h"
#include "headers/interface.h"
#include "headers/edit.h"

void header_interface() {
    system("clear");
	char str1[] = "Welcome To 'Cozastore'"; 
	printf("\n\n\n\n%70s\n\n\n\n\n\n\n"  ,str1); 
}

void footer_interface()
{
    printf("Enter (10) to view Cart.\nEnter (11) to go to Homepage.");
}

char getDate() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char s[64];
    assert(strftime(s, sizeof(s), "%c", tm));
    printf("%s\n", s);
    return 0;
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
	printf("  (2)\n\n\n\n\n\n", str3);
	
	
	
	int input;
	printf("Enter your option here:-");
	scanf("%d",&input);
	//printf("You have chosen option:- %d",input);
    return input;
}

int login_interface()
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
	
    int reSt=3;
    if(ynprompt(check)==0) {
        int loginSt = login(username, password);
        switch (loginSt)
        {
            case 0:
                //printf("Customer");
                reSt=0;
                break;
            case 1:
                //printf("Admin");
                reSt=1;
                break;
            default:
                //printf("Invalid");
                reSt=2;
        }
    } else {
        reSt=3;
    }
    return reSt;
	
	/*    check in string check is Login or Back*/
}

int register_interface()
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
	
    //strcpy(regiArr[1], firstname);
    //strcpy(regiArr[2], lastname);
    //strcpy(regiArr[3], username);
    //strcpy(regiArr[4], password);
    
	//printf("\n\n%100s\n\n\n" , str5 );

	
	char check[50];
	printf("Enter [yes] to Login or [no] to go back to main menu:-");
	scanf("%s", check);
	
	if(ynprompt(check)==0) {
        if(regi(firstname, lastname, username, password)==0) {
            return 0;
        } else {
            return 1;
        }
    } else {
        return 1;
    }
	
	/*    check in string check is Login or Back*/
}

int admin_interface(struct users session, int *searchId, char *searchString)
{
    int reSt;
	char str[] = "ADMIN DASHBOARD"; 
	char str1[] = "Welcome";
	char str2[] = "Products";
	char str3[] = "Add new Products"; 
	char str4[] = "Search Products";
	char str5[] = "Customer";
	char str6[] = "View All Users";  
	char str7[] = "Search For User by Name";  
	char str8[] = "Log Out"; 
	
    header_interface();
	printf("\n\n\n\n%63s\n\n" , str );
	printf("%70s %s %s\n\n\n\n\n\n\n"  ,str1, session.fname, session.lname); 
	
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
	
	
	
	
	
	
	
    /*
	printf("%68s\n\n\n" , str5 );
	
	n = 25;
	i = 0;
	for(i=1;i<=n;i=i+1){
		printf(" ");
	}
	i = 0;
	printf("%s",str6);
	for(i=1;i<=n;i=i+1){
		printf(" ");
	}
	printf("%s\n",str7);
	
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
    */
	
	
	
	
	char str9[] = "(5)";
	printf("%115s\n" , str8 );
	printf("%113s\n\n\n" , str9 );
	
	
	
	
	int input;
	printf("Enter your option here:-");
	scanf("%d", &input);
    switch (input)
    {
        case 2:
            printf("Enter Search String:- ");
            scanf("%s", searchString);
            //printf("\n\n%s", searchString);
            reSt=2;
            break;
        case 5:
            reSt=5;
            printf("Logout");
            break;
        default:
            printf("Default");
            reSt=10;
    }
    return reSt;
}

int user_interface(int id, int *searchId, char *searchString)
{
    int reSt=0, cartNum=0;
    cartNum=getid("cart");
	char str[] = "USER"; 
    struct users userdat;
    userdat=readusers(id);
	char str1[] = "Welcome";
	char str2[] = "Product Search";
	char str3[] = "Search For Product by ID"; 
	char str4[] = "What are you going to buy today?";
	char str5[] = "Your Cart";
	char str6[] = "View Cart";  
	char str7[] = "Check Out";  
	char str8[] = "Log Out"; 
	
    header_interface();
	printf("\n\n\n\n%62s\n\n" , str );
	printf("%60s %s %s\n\n\n\n\n\n\n"  ,str1, userdat.fname, userdat.lname); 
	
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
	
	
	
	
	
	
	
	printf("%65s (%d items)\n\n\n" , str5, cartNum);
	
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
	//printf("You have chosen option:- %d",input);
    switch (input)
    {
        case 1:
            printf("Enter Product ID:- ");
            scanf("%d", &*searchId);
            reSt=1;
            break;
        case 2:
            printf("Enter Search String:- ");
            scanf("%s", searchString);
            //printf("\n\n%s", searchString);
            reSt=2;
            break;
        case 3:
            printf("View Cart");
            reSt=3;
            break;
        case 4:
            printf("checkout");
            reSt=4;
            break;
        case 5:
            reSt=5;
            printf("Logout");
            break;
        default:
            printf("Default");
    }
    return reSt;
}

int cart_interface(struct users session)
{
    struct products cart_items;
    int total_cost=0, cartNum=getid("cart");
	char str[] = "User"; 
	char str1[] = "Welcome 'User name'";
	char str2[] = "Cart";
	char str3[] = "Your Cart"; 
	char str4[] = "Checkout";
	char str5[] = "Enter [Back] to return to Main Page";
	char str6[] = "______________________________________________________________________________________________";

	
    header_interface();
	//printf("\n\n\n\n%63s\n\n" , str);
	//printf("%70s %s %s\n\n\n\n"  ,str1, session.fname, session.lname); 
	
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
	printf("         \n\n");
	
	
	
	
	
	
	
	
	/*     List of Items            */
	
	
	char Product[] = "Products Name";
	char Quantity[] = "Quantity";
	char Price[] = "Price Per Unit($)";
	char Cost[] = "Cost($)" ;
	char Total[] = "Total ";
	
	n=120;
	for(i=1;i<=n;i=i+1){ 
		printf("_");

	}
	printf("\n");
	
	
	
	n = 15;
	for(i=1;i<=n;i=i+1){
		printf(" ");
	}
	i = 0;
	printf("%s",Product);
	for(i=1;i<=n;i=i+1){
		printf(" ");
	}
	printf("%s",Quantity);
	for(i=1;i<=n;i=i+1){
		printf(" ");
	}
	printf("%s",Price);

	for(i=1;i<=n;i=i+1){
		printf(" ");
	}
	printf("%s\n",Cost);
	
	
	
	printf("%108s\n\n",str6);
	
    for(i=1; i<cartNum+1; i++) {
	    printf("%27s",readcart(i).pname);
	    printf("%21d", 1);
	    printf("%28f",readcart(i).price);
	    printf("%27f",readcart(i).price);
        total_cost += readcart(i).price;
	    printf("\n");
    }

	
	
	
	
	printf("%108s",str6);
	
	
	printf("\n\n%80s",Total);	
	printf("%23d",total_cost);
	
	n=120;
	printf("\n");
	for(i=1;i<=n;i=i+1){ 
		printf("_");
	}
	
	

	
	
	
	
	
	
	
	
	
	printf("\n%100s\n\n\n" , str5 );
	
	
	char input[50];
	printf(" Enter 0 to checkout your order:-");
	scanf("%d", &input);
    return 0;
}

void bill_interface(struct users session)
{
    int i, cartNum, total=0;
	char str[] = "User: "; 
	char str1[] = "Thank you for your ORDER!";
	char str2[] = "Company Name";
	char str3[] = "Bill Statement"; 
	char str4[] = "Date : ";
	char str5[] = "Enter [Back] to return to Main Page:-";
	char str6[] = "______________________________________________________________________________________________";
	char mode[] = "Mode of Payment";
	char payment[] = "Cash on Delivery";
	char info[] = "You will revieve the BILL on your Email and it will be attached with your product as well.\n Thankyou for shopping with us.";


    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char date[64];
    assert(strftime(date, sizeof(date), "%c", tm));

	
    header_interface();
	//printf("\n\n\n\n%63s\n\n" , str );
	printf("%75s\n\n\n\n"  ,str1); 
	
	printf("%68s\n\n\n" , str2 );
	
	int n = 32;
	for(i=1;i<=n;i=i+1){
		printf(" ");
	}
	i = 0;
	printf("%s",str3);
	for(i=1;i<=n;i=i+1){
		printf(" ");
	}
	printf("%s%s\n", str4, date);
	
	n = 32;
	i = 0 ;
	printf("\n");
	for(i=1;i<=n;i=i+1){
		printf(" ");
	}
	i = 0;
	printf("Name: ");
	
	printf("%s %s", session.fname, session.lname );
	for(i=1;i<=n;i=i+1){
		printf(" ");
	}
	printf("         \n\n");
	
	
	
	
	
	
	
	
	/*     List of Items            */
	
	
	char Product[] = "Products Name";
	char Quantity[] = "Quantity";
	char Price[] = "Price Per Unit($)";
	char Cost[] = "Cost($)" ;
	char Total[] = "Total";
	char Net_Cost[]= "Net Cost";
	char gst[] = "GST";
	
	char item1[] = "Item_1"; int qitem1 = 2; int price1 = 50;
	char item2[] = "Item_2"; int qitem2 = 1; int price2 = 30;
	char item3[] = "Item_3"; int qitem3 = 5; int price3 = 20;
	
	
	n=120;
	for(i=1;i<=n;i=i+1){ 
		printf("_");

	}
	printf("\n");
	
	
	
	n = 15;
	for(i=1;i<=n;i=i+1){
		printf(" ");
	}
	i = 0;
	printf("%s",Product);
	for(i=1;i<=n;i=i+1){
		printf(" ");
	}
	printf("%s",Quantity);
	for(i=1;i<=n;i=i+1){
		printf(" ");
	}
	printf("%s",Price);

	for(i=1;i<=n;i=i+1){
		printf(" ");
	}
	printf("%s\n",Cost);
	
	
	
	printf("%108s\n\n",str6);
	
    cartNum=getid("cart");
    for(i=1; i<cartNum+1; i++) {
        printf("%27s",readcart(i).pname);
        printf("%21d", 1);
        printf("%28f", readcart(i).price);
        printf("%27f", readcart(i).price);
        printf("\n");
        total+=readcart(i).price;
    }

	
	
	int tax = total*0.17;
	int net_cost = total+tax;
	
	printf("%108s",str6);
	
	
	printf("\n\n%80s",Total);	
	printf("%23d",total);
	
	printf("\n\n%80s",gst);	
	printf("%23d",tax);
	
	
	printf("\n\n%80s",Net_Cost);	
	printf("%23d",net_cost);	
	
	
	
	n=120;
	printf("\n");
	for(i=1;i<=n;i=i+1){ 
		printf("_");
	}
	
	

	
	
	
	
	
	
	
	
	
	printf("\n%56s:-      %s\n\n\n " , mode,payment );
	
	printf("%s",info);
	char input[50];
	printf(" \n\n%s",str5);
	
	scanf("%s",&input);
	printf("You have selected for: %s",input);
}

int product_search_result_interface(int *ptr, int size)
{
    int i, reSt, input;
    struct products productStruct;
	char str1[] = "Product Search ";
	char str2[] = "Search Result";
	char str3[] = "Product ID"; 
	char str4[] = "Product Name";
	char str6[] = "Product Price";
	char str7[] = "Product Category";
	char str5[] = "Enter [Back] to return to Main Page";

	
    header_interface();
	//printf("\n\n\n\n%63s\n\n" , str );
	printf("%69s\n\n\n\n"  ,str1); 
	
	printf("%68s\n\n\n" , str2 );
	
	printf("%30s",str3);
	printf("%25s",str4);
	printf("%25s",str6);
	printf("%25s",str7);
	printf("\n\n");

	
	for(i=0; i<size; i++) {
        if(*(ptr+i)!=0) {
            productStruct=readproducts(*(ptr+i));
	        printf("%30d",productStruct.id);
	        printf("%25s",productStruct.pname);
	        printf("%25f",productStruct.price);
	        printf("%25s",productStruct.category);
	        printf("\n");
        }
    }
	
	
	
	printf("\n\n\n%100s\n\n\n" , str5 );

	
	struct users session=readsession();
    if(strcmp(session.role, "customer")==0) {
        addCart:
        printf("Enter product ID to add to cart or 0 to Escape:-");
        scanf("%d", &input);
        if(input>0 & input<=getid("products")) {
            productStruct=readproducts(input);
            writecart(readproducts(input));
            printf("%s Added to cart Successfully.\n", productStruct.pname);
            goto addCart;
        } else if(input==0) {
            reSt=0;
        } else {
            printf("Invalid Input.");
            goto addCart;
        }
    } else {
        printf("Enter 0 to Escape or Product ID to edit Product Details:-");
        scanf("%d", &input);
        reSt = input;
    }
    return reSt;
}

int edit_product_interface(struct products input)
{
	char str[] = "ADMIN"; 
	char str1[] = "Product EDIT ";
	//char str2[] = "Search Result";
	char str3[] = "Product ID"; 
	char productid[] = "Id of the product";
	char str4[] = "Product Name";
	char str6[] = "Product Price";
	char str7[] = "Product Stock";
	char str8[] = "Product Status";
	char str5[] = "Confirm Edit <Y/n>?";
	//char productedit[] = "Enter Product ID to edit it's Status";

	
    header_interface();
	printf("\n\n\n\n%63s\n\n" , str );
	printf("%67s\n\n\n\n"  ,str1); 
	
	printf("%60s : " , str3 );
	printf("%s", productid);
	
	
	printf("\n\n\n");
	
	printf("%30s",str4);
	printf("%25s",str6);
	printf("%25s",str7);
	printf("%25s",str8);
	printf("\n\n");
	
	
	//char item[] = "Item"; int qitem = 2; int price = 50; int status = 1;
	
	
	
	
	printf("%30s",input.pname);
	printf("%25f",input.price);
	printf("%25d",input.stock);
	printf("%25d",input.status);
	printf("\n");
	
	
	//printf("\n\n\n%100s\n" , str5 );
	
	
	int input_price;
	printf("\n\n\nEnter New Price:-");
	scanf("%d",&input_price);
	input.price = input_price;
	
	
	int input_qitem;
	printf("\n\nEnter New Quantity:-");
	scanf("%d",&input_qitem);
	input.stock = input_qitem;
	
	
	int input_status;
	printf("\n\nEnter Product's status[0,1]:-");
	scanf("%d",&input_status);
	input.status = input_status;
	
	
	
	system("clear");
	
	
	
	printf("\n\n\n\n%63s\n\n" , str );
	printf("%67s\n\n\n\n"  ,str1); 
	
	printf("%60s : " , str3 );
	printf("%s", productid);
	
	
	printf("\n\n\n");
	
	printf("%30s",str4);
	printf("%25s",str6);
	printf("%25s",str7);
	printf("%25s",str8);
	printf("\n\n");


	
	printf("%30s",input.pname);
	printf("%25f",input.price);
	printf("%25d",input.stock);
	printf("%25d",input.status);
	printf("\n");
	
	
	char input_back[3];
	printf("\n\n\n%s:-" , str5 );
	scanf("%s", input_back);
    if(ynprompt(input_back)==0) {
        editproducts(input.id, input);
    } else {
        return 0;
    }
}
