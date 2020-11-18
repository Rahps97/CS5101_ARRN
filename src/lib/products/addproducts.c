#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../headers/db.h"
#include "../../headers/userstruct.h"


void addProducts()
{
    struct products input;
    input.id=getid("products")+1;

    printf("\nProduct Name: ");
    scanf("%s", input.pname);

    printf("\nCategory: ");
    scanf("%s", input.category);

    printf("\nSeller Name: ");
    scanf("%s", input.seller);

    printf("\nPrice: ");
    scanf("%f", &input.price);

    printf("\nStock: ");
    scanf("%d", &input.stock);

    input.status=1;
    writeproducts(input);
}
