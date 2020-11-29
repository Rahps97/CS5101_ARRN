#ifndef REGISTER_H_
#define REGISTER_H_
///Authored By: Rahul Pratap Singh
///
///This function adds a new user to the database and automatically granting access to application.
///@param fname First Name of the user
///@param lname Last Name of the user
///@param username Uniques username for the registration
///@param password A strong pasword that can be later used for logging in application
///@return Returns an integer i.e. 0 or 1.
///@see users getid() writeusers()
///@attention This function cannot be used for registering an Admin. Admin credentials are hard coded in the source file.
int regi(char fname[], char lname[], char username[], char password[]);
#endif
