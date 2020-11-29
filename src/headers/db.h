#ifndef DB_H_
#define DB_H_
///Authored By: @ref contributorsniku
///
///This function takes an integer as an argument and returns struct users data of user of given id.
///@param id Id of the user
///@return Returns strut data of the user of given id.
///@see users getid()
struct users readusers(int id);


///Authored By: @ref contributorsniku
///
///This function takes an integer as an argument and returns struct products data of user of given id.
///@param id Id of the product
///@return Returns strut data of the product of given id.
///@see products getid()
struct products readproducts(int id);


///Authored By: @ref contributorsniku
///
///This function takes an user structure data as an argument and write this data in database.
///@param input User struture to write in database
///@return Returns 0 or 1.
///@see users 
int writeusers(struct users input);


///Authored By: @ref contributorsniku
///
///This function takes a product structure data as an argument and write this data in database.
///@param input Product struture to write in database
///@return Returns 0 or 1.
///@see products 
int writeproducts(struct products input);


///Authored By: @ref contributorsniku
///
///This function generates dummy users data for application testing. Dummy data can be view here @ref data
///@return Returns void
///@see users @ref data
void usersdata();


///Authored By: @ref contributorsniku
///
///This function generates dummy products data for application testing. Dummy data can be view here @ref data
///@return Returns void
///@see products @ref data
void productsdata();


///Authored By: @ref contributorsniku
///
///This function returns the no of entries in a database
///@param target Database table name
///@return Returns integer count of number of entries
int getid(char target[]);


///Authored By: @ref contributorsrohit
///
///This function writes authorised user's data in database
///@param input authorised user's struct data
///@return Returns 0 or 1.
///@see users
int writesession(struct users input);


///Authored By: @ref contributorsrohit
///
///This function reads session data from database
///@return Returns authorized user's struct data
///@see users
struct users readsession();


///Authored By: @contributorsrohit
///
///This function writes product's data to cart
///@param input product's struct data to be added in cart
///@return Returns 0 or 1.
///@see products
int writecart(struct products input);


///Authored By: @contributorsrohit
///
///This function reads cart data from database
///@param id of product whose data is saved in cart
///@return Returns product struct data
///@see products
struct products readcart(int id);


///Authored By: @contributorsrahul
///
/// This function takes a keyword as input and returns matching entries from product database
///@param keyword Search products database against the keyword for a match
//@param p A pointer variable to first element of an array which will save matched products
///@see getid() users products toLower()
///@note The second argument is the pointer variable to the array which will store the matched product's ids.
///@warning The pointer variable points to a static array whose size is hardcoded in source code and should be greater than total products count in database
int searchproducts(char keyword[], int *p);


///Authored By: @contributorsrahul
///
/// This function takes a character pointer as input and coverts it whole string to lowercase
///@param s character pointer
///@return Returns pointer variable of the string
char *toLower(char *s);
#endif
