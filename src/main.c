#include <stdio.h>
#include <stdlib.h>
#include "headers/colors.h"
#include "headers/register.h"
#include "headers/login.h"
#include "headers/db.h"
#include "headers/addproducts.h"

int main(void)
{
    //regi();
    //login("nick", "nick");
    //usersdata();
    //system("clear");
    addProducts();
    printf("Here\n");
    int id;
    id=getid("products");
    printf("From main: %d\n", id);
    return 1;
}
