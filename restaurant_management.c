#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h> 


struct MenuItem {
    int id;
    char name[50];
    float price;
};

struct OrderItem {
    int id;
    int quantity;
    float subtotal;
};

void displayMenu();
float placeOrder();

int main() {
    float totalBill = placeOrder();
    printf("\n\n--------------------------------------\n");
    printf("   Total Amount Payable: $%.2f\n", totalBill);
    printf("--------------------------------------\n");
    getch();
    return 0;
}

void displayMenu() {
    
    struct MenuItem menu[3] = {
        {1, "Burger", 5.99},
        {2, "Pizza", 12.50},
        {3, "Soda", 1.99}
    };

    printf("\n--- RESTAURANT MENU ---\n");
    printf("ID\tName\t\tPrice\n");
    for (int i = 0; i < 3; i++) {
        printf("%d\t%s\t\t$%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
    printf("-----------------------\n");
}

float placeOrder() {
    int choice, quantity;
    float total = 0;
    char addMore = 'y';
    FILE *fp;
    time_t t;
    time(&t); 


    fp = fopen("receipt.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 0;
    }

    fprintf(fp, "--- Restaurant Receipt ---\n");
    fprintf(fp, "Date: %s\n", ctime(&t));
    fprintf(fp, "Item\tQty\tAmount\n");

    while (addMore == 'y' || addMore == 'Y') {
        displayMenu();
        printf("Enter the ID of the item you want to order: ");
        scanf("%d", &choice);
        printf("Enter quantity: ");
        scanf("%d", &quantity);


        float itemPrice = 0;
        if (choice == 1) itemPrice = 5.99;
        else if (choice == 2) itemPrice = 12.50;
        else if (choice == 3) itemPrice = 1.99;

        float itemTotal = itemPrice * quantity;
        total += itemTotal;

        
        fprintf(fp, "%d\t%d\t$%.2f\n", choice, quantity, itemTotal);

        printf("Do you want to add more items? (y/n): ");
        scanf(" %c", &addMore);
    }

    fprintf(fp, "--------------------------\n");
    fprintf(fp, "Total: $%.2f\n", total);
    fclose(fp);

    printf("\nOrder placed successfully. Receipt generated in receipt.txt\n");
    return total;
}