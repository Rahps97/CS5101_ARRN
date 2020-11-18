#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../headers/db.h"
#include "../../headers/userstruct.h"

void regi(char fname[], char lname[], char username[], char password[])
{
    struct users input;
    input.id=getid("users")+1;
    strcpy(input.fname, fname);
    strcpy(input.lname, lname);
    strcpy(input.username, username);
    strcpy(input.password, password);
    strcpy(input.role, "customer");
    input.status=1;
    writeusers(input);
}
