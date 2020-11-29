#ifndef READ_H_
#define READ_H_

// structure data for users
///Authored By: @contributorsakash
///
///Structure data for all users
struct users
{
    ///id of the user
    int id;
    ///First Name of the user
    char fname[20];
    ///Last Name of the user
    char lname[20];
    ///Unique username of the user
    char username[10];
    ///Password matching to a uniques username
    char password[20];
    ///Role of the user i.e. Customer or Admin
    char role[8];
    ///Status i.e. Active account=1 or Deleted account=0
    int status;
};

// structure data for products
///Authored By: @contributorsakash
///
///Structure data for all products
struct products
{
    ///id of the product
    int id;
    ///Product Name
    char pname[150];
    ///Category for the product
    char category[120];
    ///Seller of the product
    char seller[100];
    ///Selling Price of the product
    float price;
    ///Number of products in stock
    int stock;
    ///Status i.e. Active=1 or Deleted=0
    int status;
};

#endif
