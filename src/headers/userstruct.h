#ifndef READ_H_
#define READ_H_

struct users
{
    int id;
    char fname[20];
    char lname[20];
    char username[10];
    char password[20];
    char role[8];
    int status;
};

struct products
{
    int id;
    char pname[150];
    char category[120];
    char seller[100];
    float price;
    int stock;
    int status;
};

#endif
