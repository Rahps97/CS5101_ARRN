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

void write(char fname[], char lname[], char username[], char password[], char role[])
{
    FILE *outfile;

    outfile=fopen("users.dat", "w");
    if(outfile==NULL)
    {
        fprintf(stderr, "\nError. Cannot open file\n");
        exit(1);
    }
    //printf("%s %s %s %s %s\n", fname, lname, username, password, role);

    //struct users input = {1, fname, lname, username, password, role, 1};
    //struct users input = {1, "Niku", "Nitin", "nick", "nick", "admin", 1};
    //struct users input1 = {1, "Niku", "Nitin", "nick", "nick", "admin", 1};

    struct users input;

    input.id=1;
    printf("\nFirst Name: ");
    scanf("%s", input.fname);

    printf("\nLast Name: ");
    scanf("%s", input.lname);

    printf("\nUsername: ");
    scanf("%s", input.username);

    printf("\nPassword: ");
    scanf("%s", input.password);

    strcpy(input.role, "admin");

    fwrite (&input, sizeof(struct users), 1, outfile);
    //fwrite (&input1, sizeof(struct users), 1, outfile);
    if(fwrite != 0)
    {
        fclose(outfile);
        printf("Success\n");
    } else {
        fclose(outfile);
        printf("Fail\n");
    }

}
