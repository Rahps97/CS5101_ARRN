#ifndef INTERFACE_H_
#define INTERFACE_H_
void header_interface();
void footer_interface();
int ynprompt();
int main_interface();
int login_interface();
int register_interface();
int admin_interface(struct users session, int *searchId, char *searchString);
int user_interface(int id, int *searchId, char *searchString);
int cart_interface(struct users session);
void bill_interface(struct users session);
int product_search_result_interface(int *ptr, int size);
int edit_product_interface(struct products input);
#endif
