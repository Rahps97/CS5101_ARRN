#include <stdio.h>
#include <stdlib.h>
#include "../../headers/userstruct.h"
#include "../../headers/db.h"
#include "../../headers/edit.h"

void editproducts(int id, struct products newData)
{
    int i=1, productscount=getid("products");
    int out;
    FILE *infile;
    FILE *temp;
    struct products productsArr[100];
    struct products input;

    infile=fopen("products.dat", "r");
    if(infile==NULL)
    {
        fprintf(stderr, "\nError. Cannot open file\n");
        exit(1);
    }
    temp=fopen("temp", "w");
    if(temp==NULL)
    {
        fprintf(stderr, "\nError. Cannot open file\n");
        exit(1);
    }
    while(i<productscount) {
        if(i==id) {
            fseek(infile, (i-1)*sizeof(struct products), 0);
            fwrite(&newData, sizeof(struct products), 1, temp);
        } else {
            fseek(infile, (i-1)*sizeof(struct products), 0);
            fread(&input, sizeof(struct products), 1, infile);
            fwrite(&input, sizeof(struct products), 1, temp);
        }
        i++;
    }
    //out=rename("temp", "products.dat");
    system("mv temp products.dat");
    //printf("Out: %d", out);
    fclose(infile);
    fclose(temp);
}

/*
int main()
{
    struct products product7 = {7, "Plastic New Hanger ", "Home essentials", "Cloudtail India", 339.0, 100, 1};
    editproducts(7, product7);
    printf("%d", getid("products"));
}
*/
