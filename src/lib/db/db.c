#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../headers/userstruct.h" //struct datatype for users and products
#include "../../headers/db.h" //struct datatype for users and products



/*
 * function to read users data from users.dat file
 * usage: refer documentation
 */

struct users readusers(int id)
{
    FILE *infile;
    int userscount=getid("users");

    infile=fopen("users.dat", "r");
    if(infile==NULL)
    {
        fprintf(stderr, "\nError. Cannot open file\n");
        exit(1);
    }

    struct users input;

    if(id<=userscount) {
        fseek(infile, (id-1)*sizeof(struct users), 0);
        fread(&input, sizeof(struct users), 1, infile);
    }
    //printf("Users: %s %s\n", input.role, input.fname);
    fclose(infile);
    return input;
}


/*
 * function to read products data from products.dat file
 * usage: refer documentation
 */

struct products readproducts(int id)
{
    FILE *infile;
    int productscount=getid("products");

    infile=fopen("products.dat", "r");
    if(infile==NULL)
    {
        fprintf(stderr, "\nError. Cannot open file\n");
        exit(1);
    }

    struct products input;

    if(id<=productscount) {
        fseek(infile, (id-1)*sizeof(struct products), 0);
        fread(&input, sizeof(struct products), 1, infile);
    }
    //printf("dfsdf: %s\n", input.pname);
    fclose(infile);
    return input;
}


/*
 * function to write users data to users.dat file
 * usage: refer documentation
 */

int writeusers(struct users input)
{
    FILE *outfile;

    outfile=fopen("users.dat", "a+");
    if(outfile==NULL)
    {
        fprintf(stderr, "\nError. Cannot open file\n");
        exit(1);
    }

    fwrite (&input, sizeof(struct users), 1, outfile);
    if(fwrite != 0)
    {
        fclose(outfile);
        return 0;
    } else {
        fclose(outfile);
        return 1;
    }
}


/*
 * function to write products data to products.dat file
 * usage: refer documentation
 */

int writeproducts(struct products input)
{
    FILE *outfile;

    outfile=fopen("products.dat", "a+");
    if(outfile==NULL)
    {
        fprintf(stderr, "\nError. Cannot open file\n");
        exit(1);
    }

    fwrite (&input, sizeof(struct products), 1, outfile);
    if(fwrite != 0)
    {
        fclose(outfile);
        return 0;
    } else {
        fclose(outfile);
        return 1;
    }
}

void usersdata()
{
    FILE *outfile;
    outfile=fopen("users.dat", "w");
    if(outfile==NULL) {
        fprintf(stderr, "\nError. Cannot open file.\n");
        exit(1);
    }

    struct users admin = {1, "Niku", "Nitin", "nick", "nick", "admin", 1};
    struct users customer1 = {2, "Nitin", "Niku", "nitin", "nitin", "customer", 1};
    struct users customer2 = {3, "Akash", "Nigam", "akash", "akash", "customer", 1};
    struct users customer3 = {4, "Rahul", "Pratap", "rahul", "rahul", "customer", 1};
    struct users customer4 = {5, "Rohit", "Prasad", "rohit", "rohit", "customer", 1};

    fwrite(&admin, sizeof(struct users), 1, outfile);
    fwrite(&customer1, sizeof(struct users), 1, outfile);
    fwrite(&customer2, sizeof(struct users), 1, outfile);
    fwrite(&customer3, sizeof(struct users), 1, outfile);
    fwrite(&customer4, sizeof(struct users), 1, outfile);

    if(fwrite != 0) {
        printf("User Data added successfully\n");
    } else {
        printf("Error. Cannot write to file\n");
    }

    fclose(outfile);
}


void productsdata()
{
    FILE *outfile;
    outfile=fopen("products.dat", "w");
    if(outfile==NULL) {
        fprintf(stderr, "\nError. Cannot open file.\n");
        exit(1);
    }

    struct products product1 = {1, "Riding Jacket", "Automotive essentials", "ETraders", 4500.0, 200, 1};
    struct products product2 = {2, "Studds Helmet Black", "Automotive essentials", "RS Wholesalers", 860.0, 100, 1};
    struct products product3 = {3, "Shower Curtain", "Home essentials", "Cloudtail India", 600.0, 100, 1};
    struct products product4 = {4, "Wax Tealight Candles", "Home essentials", "Cloudtail India", 299.0, 100, 1};
    struct products product5 = {5, "12-inch Wall Clock", "Home essentials", "Cloudtail India", 629.0, 100, 1};
    struct products product6 = {6, "Collage Photo Frames", "Home essentials", "Cloudtail India", 629.0, 100, 1};
    struct products product7 = {7, "Plastic Clothes Hanger ", "Home essentials", "Cloudtail India", 339.0, 100, 1};
    struct products product8 = {8, "Foldable Step Ladder", "Home essentials", "Cloudtail India", 1699.0, 100, 1};
    struct products product9 = {9, "Blankets", "Home essentials", "Cloudtail India", 1699.0, 100, 1};
    struct products product10 = {10, "Tubeless Scooter Tyre", "Automotive essentials", "RS Wholesalers", 1149.0, 100, 1};

    fwrite(&product1, sizeof(struct products), 1, outfile);
    fwrite(&product2, sizeof(struct products), 1, outfile);
    fwrite(&product3, sizeof(struct products), 1, outfile);
    fwrite(&product4, sizeof(struct products), 1, outfile);
    fwrite(&product5, sizeof(struct products), 1, outfile);
    fwrite(&product6, sizeof(struct products), 1, outfile);
    fwrite(&product7, sizeof(struct products), 1, outfile);
    fwrite(&product8, sizeof(struct products), 1, outfile);
    fwrite(&product9, sizeof(struct products), 1, outfile);
    fwrite(&product10, sizeof(struct products), 1, outfile);

    if(fwrite != 0) {
        printf("Products Data added successfully\n");
    } else {
        printf("Error. Cannot write to file\n");
    }

    fclose(outfile);
}

int getid(char target[])
{
    FILE *infile;
    int i;
    i=0;
    if(strcmp(target, "users")==0) {
        infile=fopen("users.dat", "r");
        if(infile==NULL)
        {
            fprintf(stderr, "\nError. Cannot open file\n");
            exit(1);
        }

        fseek(infile, 0L, SEEK_END);
        int sz;
        sz=ftell(infile);
        i=sz/sizeof(struct users);
        return i;

    } else if(strcmp(target, "products")==0) {
        infile=fopen("products.dat", "r");
        if(infile==NULL)
        {
            fprintf(stderr, "\nError. Cannot open file\n");
            exit(1);
        }

        fseek(infile, 0L, SEEK_END);
        int sz;
        sz=ftell(infile);
        i=sz/sizeof(struct products);
        return i;
    } else {
        infile=fopen("cart.dat", "r");
        if(infile==NULL)
        {
            fprintf(stderr, "\nError. Cannot open file\n");
            exit(1);
        }

        fseek(infile, 0L, SEEK_END);
        int sz;
        sz=ftell(infile);
        i=sz/sizeof(struct products);
        return i;
    }
}

int writesession(struct users input)
{
    FILE *outfile;

    outfile=fopen("session.dat", "w");
    if(outfile==NULL)
    {
        fprintf(stderr, "\nError. Cannot open file\n");
        exit(1);
    }

    fwrite (&input, sizeof(struct users), 1, outfile);
    if(fwrite != 0)
    {
        fclose(outfile);
        return 0;
    } else {
        fclose(outfile);
        return 1;
    }
}

struct users readsession()
{
    FILE *infile;

    int id=1;
    infile=fopen("session.dat", "r");
    if(infile==NULL)
    {
        fprintf(stderr, "\nError. Cannot open file\n");
        exit(1);
    }

    struct users input;

    fseek(infile, (id-1)*sizeof(struct users), 0);
    fread(&input, sizeof(struct users), 1, infile);
    return input;
}

int writecart(struct products input)
{
    FILE *outfile;
    //printf("Name: %s\nCategory: %s\nPrice: %f\nStock: %d\n", input.pname, input.category, input.price, input.stock);

    outfile=fopen("cart.dat", "a+");
    if(outfile==NULL)
    {
        fprintf(stderr, "\nError. Cannot open file\n");
        exit(1);
    }

    int out=fwrite(&input, sizeof(struct products), 1, outfile);
    //printf("Write Cart St: %d\n", out);
    if(fwrite != 0)
    {
        fclose(outfile);
        //printf("Data Success\n");
        return 0;
    } else {
        fclose(outfile);
        //printf("Data Fail\n");
        return 1;
    }
}

struct products readcart(int id)
{
    //printf("%d", id);
    int out;
    FILE *infile;

    int cartcount=getid("cart");
    infile=fopen("cart.dat", "r");
    if(infile==NULL)
    {
        fprintf(stderr, "\nError. Cannot open file\n");
        exit(1);
    }

    struct products input;

    if(id<=cartcount) {
        fseek(infile, (id-1)*sizeof(struct products), 0);
        fread(&input, sizeof(struct products), 1, infile);
        //while(fread(&input, sizeof(struct products), 1, infile)) {

        //    printf("Func: %s\n", input.pname);
        //    printf("fseek: %d\n", out);
        //}
    }

    //printf("Func: %s", input.pname);
    fclose(infile);
    return input;
}

int searchproducts(char keyword[], int *p)
{
    int i, count=0, productscount=getid("products");

    struct products outstruct;

    char listone[productscount][150], listtwo[productscount][120];

    for(i=0; i<productscount; i++) {
        outstruct=readproducts(i+1);
        strcpy(listone[i], outstruct.pname);
        strcpy(listtwo[i], outstruct.category);
    }
    // Search function for 1st list
    for (int i = 0; i < productscount; i++) {
        char *source = listone[i];
        // compare strings
        char *found = strstr(toLower(source), toLower(keyword));
        // if something is common in both string print the term
        if (found != NULL) {
            *(p+i)=i+1;
            count++;
        }
    }
    // Search function for 2nd list
    for (int i = 0; i < productscount; i++) {
        char *source = listtwo[i];
        // compare strings
        char *found = strstr(toLower(source), toLower(keyword));
        // if something is common in both string print the term
        if (found != NULL) {
            *(p+i)=i+1;
            count++;
        }
    }
    return 0;
}


char *toLower(char *s) {
    for (char *p = s; *p; p++)
    *p = tolower(*p);
    return s;
}
