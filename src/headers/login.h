#ifndef LOGIN_H_
#define LOGIN_H_
/// Authored By: Rahul Pratap Singh
///
/// A single login function to login both users and admins.
///@param username The uniques username exiting in database
///@param password The password matching against the username
///@returns Returns 0(customer), 1(admin) or 2(invalid credentials).
///@see readusers() writesession() users
///@note After login a file **session.dat** is generated with authenticated users details.
int login(char username[], char password[]);
#endif
