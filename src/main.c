#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/colors.h"
#include "headers/register.h"
#include "headers/login.h"
#include "headers/db.h"
#include "headers/addproducts.h"
#include "headers/interface.h"
#include "headers/userstruct.h"


int reset_productsid_arr(int *ptr, int size);

int main(void)
{
    //printf("Size: %d\n", getid("cart"));
    //printf("Here: %s\n", readcart(1).pname);

    int i, loginSt, userInterfaceSt, searchId, searchResultIdsSize, productSearchInterfaceSt, adminInterfaceSt;
    struct users session;
    int searchResultIds[100]={0};
    char searchString[100];

    mainInterface:
    if(main_interface()==1) {

        //Login Interface Starts
        loginInterface:
        loginSt=login_interface();
        switch (loginSt)
        {
            
            // Customer Login Success
            case 0:
                printf("Customer\n");
                session=readsession();
                userInterface:
                userInterfaceSt=user_interface(session.id, &searchId, searchString);
                switch (userInterfaceSt)
                {
                    
                    //Search Product
                    case 1:

                        searchResultIds[0]=searchId;
                        searchproducts(searchString, &searchResultIds[0]);

                        searchResultIdsSize=sizeof(searchResultIds)/sizeof(searchResultIds[0]);
                        productSearchInterfaceSt=product_search_result_interface(&searchResultIds[0], searchResultIdsSize);
                        if(productSearchInterfaceSt==0) {
                            goto userInterface;
                        }
                        break;

                    // Search By ID
                    case 2:
                        searchResultIdsSize=sizeof(searchResultIds)/sizeof(searchResultIds[0]);
                        reset_productsid_arr(&searchResultIds[0], searchResultIdsSize);
                        searchproducts(searchString, &searchResultIds[0]);

                        productSearchInterfaceSt=product_search_result_interface(&searchResultIds[0], searchResultIdsSize);
                        if(productSearchInterfaceSt==0) {
                            goto userInterface;
                        }
                        break;
                    case 3:

                        //Cart
                        if(cart_interface(session)==0) {
                            bill_interface(session);
                        } else {
                            goto userInterface;
                        }
                        break;
                    case 4:

                        //Bill/Checkout
                        bill_interface(session);
                        break;
                    default:

                        //Default
                        printf("Invalid option");
                        goto userInterface;
                }
                break;


            // Admin Login Success
            case 1:
                adminInterface:
                printf("Admin");
                session=readsession();
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
                    case 3:
                        printf("All users");
                        break;
                    case 4:
                        printf("Search Users");
                        searchResultIds[0]=searchId;
                        searchproducts(searchString, &searchResultIds[0]);

                        searchResultIdsSize=sizeof(searchResultIds)/sizeof(searchResultIds[0]);
                        productSearchInterfaceSt=product_search_result_interface(&searchResultIds[0], searchResultIdsSize);
                        if(productSearchInterfaceSt==0) {
                            goto userInterface;
                        }
                        break;
                    case 5:
                        goto mainInterface;
                        break;
                    default:
                        printf("Default");
                }
                break;
            //Invalid Credentials
            case 2:
                printf("Invalid Credentials");
                break;
            //Default
            default:
                goto loginInterface;
        }
    } else if(main_interface()==2) {

        regiLabel:
        if(register_interface()==0) {
            printf("user registered successfully");
        } else {
            goto regiLabel;
        }

    } else {
        printf("Invalid input.");
        exit(1);
    }
    return 1;
}

int reset_productsid_arr(int *ptr, int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        *(ptr+i)=0;
    }
    return 0;
}
