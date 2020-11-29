#ifndef INTERFACE_H_
#define INTERFACE_H_
///Authored By @ref contributorsrohit
///
///This function prints the header part of the interface
///@return Returns void
void header_interface();


///Authored By @ref contributorsrohit
///
///This function prints the header part of the interface
///@return Returns void
void footer_interface();


///Authored By @ref contributorsakash
///
///This function check users reply as yes or no
///@param input Takes user character input
///@return Returns 0 or 1
///@note Valid Input: Y, y, yes, no, n
int ynprompt(char input[]);


///Authored By @ref contributorsrohit
///
///This is the main interface of the application asking for Sign In or Sign Up
///@return Return an integer which is user's input
int main_interface();


///Authored By @ref contributorsrohit
///
/// This is login interface of the application prompting user for username and password
///@return Return an integer which is user's input
int login_interface();


///Authored By @ref contributorsrohit
///
/// This is register interface of the application prompting user to register themselves to the application
///@return Return an integer which is user's input
int register_interface();


///Authored By @ref contributorsrohit
///
/// This is the interface for admin with options such as add, editproducts
///@param session Authorised user's struct data
///@param searchId Pointer to a variable for searching products by their IDs
///@param searchString Pointer to a variable for searching products by any search string
///@return Return an integer which is user's input
int admin_interface(struct users session, int *searchId, char *searchString);


///Authored By @ref contributorsrohit
///
/// This is the interface for customer 
///@param id Authorised user's id
///@param searchId Pointer to a variable for searching products by their IDs
///@param searchString Pointer to a variable for searching products by any search string
///@return Return an integer which is user's input
int user_interface(int id, int *searchId, char *searchString);


///Authored By @ref contributorsrohit
///
/// This is the interface for to view cart data 
///@param session Authorised user's struct data
///@return Return an integer which is user's input
int cart_interface(struct users session);


///Authored By @ref contributorsrohit
///
/// This is the interface for to view bill/invoice
///@param session Authorised user's struct data
///@return Return an integer which is user's input
void bill_interface(struct users session);


///Authored By @ref contributorsrohit
///
/// This is the interface which displays the product's search result
///@param ptr A pointer variable which points to array of IDs of products which matches the user's search string
///@param size Size of static array which holds the IDs of products which match user's search string
///@return Return an integer which is user's input
///@note This function also enables users to add products to cart and allow admin to edit product's values
int product_search_result_interface(int *ptr, int size);


///Authored By @ref contributorsrohit
///
/// This is the interface which allows admin to edit products
///@param input Struct data of product which needs to be edited
int edit_product_interface(struct products input);
#endif
