#include <stdio.h>
#include <stdlib.h>
#include "headers/colors.h"
#include "headers/register.h"
#include "headers/login.h"
#include "headers/db.h"
#include "headers/addproducts.h"
#include "headers/interface.h"

int main(void)
{
    //regi();
    //login("nick", "nick");
    //usersdata();
    //system("clear");
    //addProducts();
    //printf("Here\n");
    //int id;
    //id=getid("products");
    //printf("From main: %d\n", id);
    if(main_interface()==1) {
        login_interface();
        //login("akash", "akash");
    } else if(main_interface()==2) {
        //regi();
        register_interface();
    } else {
        printf("Invalid input.");
        exit(1);
    }
    return 1;
}
