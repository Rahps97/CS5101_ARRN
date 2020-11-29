#include<stdio.h>
#include<string.h>
#include "../../headers/db.h"
#include "../../headers/userstruct.h"


int login(char username[], char password[])
{
    struct users data;
    int i;
    int reSt=2;
    int num=getid("users");
    for(i=1; i<num+1; i++) {
        data=readusers(i);
        //printf("Checking for user: %s\n", data.fname);
        if(strcmp(data.username, username)==0 & strcmp(data.password, password)==0 & data.status==1) {
            if(strcmp(data.role, "customer")==0) {
                //return 0;
                reSt=0;
            } else if(strcmp(data.role, "admin")==0) {
                //return 1;
                reSt=1;
            }
            writesession(data);
            break;
        } else {
            //return 2;
            reSt=2;
        }
    }
    return reSt;
}
