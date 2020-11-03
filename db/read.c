#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void read()
{
    FILE *infile;
    struct users input;

    infile=fopen("users.dat", "r");
    if(infile==NULL)
    {
        fprintf(stderr, "\nError. Cannot open file\n");
        exit(1);
    } else {
        printf("Reading file.");
    }

    while(fread(&input, sizeof(struct users), 1, infile))
    {
        printf("name=%s %s\n", input.fname, input.lname);
    }
    fclose(infile);
    printf("Read Success");
}
