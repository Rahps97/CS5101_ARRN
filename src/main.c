
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/register.h"
#include "headers/login.h"
#include "headers/db.h"
#include "headers/interface.h"
#include "headers/userstruct.h"


//Prototype
int reset_productsid_arr(int *ptr, int size);
void logout();

///Authored By: @ref contributorsakash
///
/// This is main function defining the flow of the application.
///@param void No parameters required
int main(void)
{

    logout(); //Starts with logging out any user

    int i, loginSt, userInterfaceSt, searchId, searchResultIdsSize, productSearchInterfaceSt, adminInterfaceSt;

    struct users session;
    int searchResultIds[100]={0};
    char searchString[100];

    mainInterface: //label for main interface
    if(main_interface()==1) { //user has chosen Sign In

        //Login Interface Starts
        loginInterface: //label for login interface
        loginSt=login_interface(); 
        switch (loginSt)
        {
            
            // Customer Login Success
            case 0:
                session=readsession(); //reading current logged in user data
                userInterface: // label for user interface

                userInterfaceSt=user_interface(session.id, &searchId, searchString);
                switch (userInterfaceSt)
                {
                    
                    //Search Product
                    case 1:

                        // Search product by ID
                        searchResultIds[0]=searchId;
                        searchproducts(searchString, &searchResultIds[0]);
                        reset_productsid_arr(&searchResultIds[0], searchResultIdsSize); // Reset previous search result

                        searchResultIdsSize=sizeof(searchResultIds)/sizeof(searchResultIds[0]);
                        productSearchInterfaceSt=product_search_result_interface(&searchResultIds[0], searchResultIdsSize);
                        if(productSearchInterfaceSt==0) {
                            goto userInterface;
                        }
                        break;

                    case 2:
                        
                        // Search product by input string
                        searchResultIdsSize=sizeof(searchResultIds)/sizeof(searchResultIds[0]);
                        reset_productsid_arr(&searchResultIds[0], searchResultIdsSize); // Reset previous search results
                        searchproducts(searchString, &searchResultIds[0]);

                        productSearchInterfaceSt=product_search_result_interface(&searchResultIds[0], searchResultIdsSize);

                        // User escapes
                        if(productSearchInterfaceSt==0) {
                            goto userInterface;
                        }
                        break;
                    case 3:

                        //Cart
                        if(cart_interface(session)==0) {
                            bill_interface(session);
                        } else {

                            // User escapes
                            goto userInterface;
                        }
                        break;
                    case 4:

                        //Bill/Checkout
                        bill_interface(session);
                        break;
                    case 5:
                        //Logout
                        logout();
                        goto loginInterface;
                        break;
                    default:

                        //Default
                        goto userInterface;
                }
                break;


            // Admin Login Success
            case 1:
                adminInterface: // label for admin interface
                session=readsession(); // reading session data for logged in user
                adminInterfaceSt=admin_interface(session, &searchId, searchString);
                switch(adminInterfaceSt)
                {
                    case 1:
                        //Add New Products
                        printf("Add new products");
                        printf("\nName: ");
                        struct products newProduct;
                        newProduct.id=getid("products")+1;
                        scanf("%s", newProduct.pname);
                        printf("\nCategory: ");
                        scanf("%s", newProduct.category);
                        printf("\nSeller: ");
                        scanf("%s", newProduct.seller);
                        printf("\nPrice: ");
                        scanf("%f", &newProduct.price);
                        printf("\nStock: ");
                        scanf("%d", &newProduct.stock);
                        writeproducts(newProduct);
                        break;
                    case 2:
                        SearchProducts:
                        //Search Products
                        searchResultIdsSize=sizeof(searchResultIds)/sizeof(searchResultIds[0]);
                        reset_productsid_arr(&searchResultIds[0], searchResultIdsSize);
                        searchproducts(searchString, &searchResultIds[0]);

                        productSearchInterfaceSt=product_search_result_interface(&searchResultIds[0], searchResultIdsSize);

                        // user escapes
                        if(productSearchInterfaceSt==0) {
                            goto adminInterface;
                        } else {

                            //Edit Products
                            int editProductInterfaceSt=edit_product_interface(readproducts(productSearchInterfaceSt));
                            if(editProductInterfaceSt==0) {
                                printf("Task Succesfull.\nPress 0 to continue.");
                                int enter;
                                scanf("%d", &enter);
                                goto adminInterface;
                            } else {
                                printf("Task Failed.\nPress 1 to try again or 0 to Escape.");
                                int enter;
                                scanf("%d", &enter);
                                if(enter==1) {
                                    goto SearchProducts;
                                } else {
                                    goto adminInterface;
                                }
                            }
                        }
                        break;
                    case 5:
                        logout();
                        goto loginInterface;
                        break;
                    default:
                        goto adminInterface;
                }
                break;
            //Invalid Credentials
            case 2:
                goto loginInterface;
                break;
            //Default
            default:
                goto loginInterface;
        }
    } else if(main_interface()==2) { // user has chosen Sign Up

        regiLabel: // label for register interface
        if(register_interface()==0) {
            printf("user registered successfully.\n");
            printf("Enter 0 to contine.");
            int enter;
            scanf("%d", &enter);
            goto mainInterface;
        } else {
            goto regiLabel;
        }

    } else {
        printf("Invalid input.");
        printf("Enter 0 to contine.");
        int enter;
        scanf("%d", &enter);
        goto mainInterface;
    }
    return 1;
}



// function to clean previous search results
///Authored By: @ref contributorsakash
///
///This function resets the searchResultIds Array
///@param ptr Pointer avriable to searchResultIds Array
///@param size Size of static array searchResultIds Array
///@return Returns 0
int reset_productsid_arr(int *ptr, int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        *(ptr+i)=0;
    }
    return 0;
}

///Authored By: @ref contributorsakash
///
/// function to logout users: simply deletes and create new session file
///@return Returns void
void logout()
{
    system("rm cart.dat session.dat");
    system("touch cart.dat session.dat");
}
