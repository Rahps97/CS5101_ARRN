#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../headers/db.h"
#include "../../headers/userstruct.h"

void regi()
{
    struct users input;
    input.id=getid("users")+1;
    printf("\nFirst Name: ");
    scanf("%s", input.fname);

    printf("\nLast Name: ");
    scanf("%s", input.lname);

    printf("\nUsername: ");
    scanf("%s", input.username);

    printf("\nPassword: ");
    scanf("%s", input.password);
    strcpy(input.role, "customer");
    writeusers(input);
}
