#ifndef DB_H_
#define DB_H_
struct users readusers(int id);
struct products readproducts(int id);
void writeusers(struct users input);
void writeproducts(struct products input);
void usersdata();
void productsdata();
int getid(char target[]);
#endif
