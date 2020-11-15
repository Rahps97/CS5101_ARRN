#include<stdio.h>
#include<string.h>
#include "../../headers/db.h"
#include "../../headers/userstruct.h"

int login(char username[], char password[])
{
    struct users data;
    int i;
    for(i=0; i<6; i++) {
        if(i<5) {
            data=readusers(i);
            //printf("Checking for user: %s\n", data.fname);
            if(strcmp(data.username, username)==0) {
                if(strcmp(data.password, password)==0) {
                    printf("Login Success for user: %s.\n", data.fname);
                    break;
                }
            }
        } else {
            printf("Invalid Credentials.\n");
        }
    }
    /*
    if(data.password == password) {
        printf("Success");
        return 0;
    } else {
        printf("Fail");
        return 1;
    }
    */
    return 0;
}
