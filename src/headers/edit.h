#ifndef EDIT_PRODUCTS_H_
#define EDIT_PRODUCTS_H_
///Authored By @ref contributorsrahul
///
///This function enables admin to edit produts in database
///@param id ID of the product to be edited
///@newData New struct data of the product
///@see readproducts() writeproducts()
///@return void
///@warning This function creates a temporary file to edit data and then removes that temp file. So this function may fail on windows system.
void editproducts(int id, struct products newData);
#endif
