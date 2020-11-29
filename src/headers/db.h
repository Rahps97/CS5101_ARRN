#ifndef DB_H_
#define DB_H_
struct users readusers(int id);
struct products readproducts(int id);
int writeusers(struct users input);
void writeproducts(struct products input);
void usersdata();
void productsdata();
int getid(char target[]);
int writesession(struct users input);
struct users readsession();
int writecart(struct products input);
struct products readcart(int id);
int searchproducts(char keyword[], int *p);
#endif
