#include <stdio.h>
#include <string.h>
#define SIZE 50


typedef enum
{
    Clothing,
    FootWear,
    Electronic,
}Type;

typedef struct 
{
    char name[30];
    float price;
    int size;
    float Weight;
}Item;

void Type1(Type type){
    switch (type)
    {
    case Clothing:
        printf("\n Type: Clothing");
        break;
    case FootWear:
        printf("\n Type: FootWear");
        break;
    case Electronic:
        printf("\n Type: Electronic");
        break;
    default:
        printf("\n Item cannot be Identified!");
        break;
    }
}

int main(){
    int i,j,n;
    Type type[SIZE];
    Item item[SIZE];
    char search[SIZE];

    do
    {
        printf("Enter number of Items: ");
        scanf("%d",&n);
    } while (n <= 0);
    
    for(i = 1;i <= n; i++)
    {
        printf("Enter information for product %d \n",i);
        printf(" Name: ");
        scanf("%s",&item[i].name);
        printf(" Price: ");
        scanf("%f",&item[i].price);
        while (1) {
            printf(" Type (0: clothing, 1: FootWear, 2: Electronic): ");
            if (scanf("%d", &type[i]) == 1 && (type[i] >= 0 && type[i] <= 2)) {
                break;
            } else {
                printf("Invalid input. Please enter a valid type.\n");
                // Clear the input buffer
                scanf("%*[^\n]");
            }
        }
        if(type[i] ==  2){
            printf(" Weight: ");
            scanf("%f",&item[i].Weight); 
        } 
        else
        {
            printf(" size: ");
            scanf("%d",&item[i].size); 
        }
    }
    printf("Enter the name of the Product to retrive information: ");
    scanf("%s", search);
    for(i = 1;i <= n; i++)
    {
        if(strcmp(search,item[i].name) == 0){
            printf("\n Name: %s", item[i].name);
            printf("\n price: %.2f", item[i].price);
            Type1(type[i]);
            // if(type[i] ==  2){
            //     printf("\n Weight: %.2f",item[i].Weight);
            // } 
            // else
            // {
            //     printf("\n size: %d", item[i].size);
            // }
            printf((type[i] == 2) ? "\n Weight: %.2f" : "\n size: %d", (type[i] == 2) ? item[i].Weight : item[i].size);
        }
    }
    return 0;
}