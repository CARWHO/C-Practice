#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    ELECTRONICS,
    GROCERIES,
    CLOTHING,
    FURNITURE
} Category_t;

typedef struct {
    Category_t category;
    char name[50];
    float price;
    uint32_t quantity;
} Product_t;

Product_t createProduct(Category_t category, const char *name, float price, uint32_t quantity)

{  
    Product_t productInfo;
    productInfo.category = category;
    strcpy(productInfo.name, name);
    productInfo.price = price;
    productInfo.quantity = quantity;
    return productInfo;
}

void printProductInfo(const Product_t *product)

{
    char* productCategoryName = NULL;
    switch (product->category) {
        case ELECTRONICS:
            productCategoryName = "ELECTRONICS";
            break;
        case CLOTHING:
            productCategoryName = "CLOTHING";
            break;
        case FURNITURE:
            productCategoryName = "FURNITURE";
            break;
        case GROCERIES:
            productCategoryName = "GROCERIES";
            break;
    }
    printf("Category: %s, Name: %s, Price: $%.2f, Quantity: %d\n", productCategoryName, product->name, product->price, product->quantity);
}


int main() 

{
    Product_t product = createProduct(CLOTHING, "YYY", 699.99, 15);
    printProductInfo(&product);
}