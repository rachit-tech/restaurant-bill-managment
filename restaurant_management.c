/* ===========Bean Me Up Cafe=============*/
#include <stdio.h>

int main() {
    int choice, quantity;
    float price = 0, subtotal = 0, total = 0;
    float gstRate = 0.18, gstAmount, grandTotal;
    char customerName[50];

    printf("--- 2026 RESTAURANT BILLING SYSTEM ---\n");
    printf("Enter Customer Name: ");
    scanf(" %[^\n]", customerName);

    while (1) {
        printf("\nMENU:\n");
        printf("1. Burger   - $5.00\n");
        printf("2. Pizza    - $12.00\n");
        printf("3. Pasta    - $8.50\n");
        printf("4. Soda     - $2.00\n");
        printf("5. Finalize Bill\n");
        printf("Select an option (1-5): ");
        scanf("%d", &choice);

        if (choice == 5)
            break;

        if (choice < 1 || choice > 5) {
            printf("Invalid choice! Try again.\n");
            continue;
        }

        printf("Enter Quantity: ");
        scanf("%d", &quantity);

        switch (choice) {
            case 1: price = 5.00; break;
            case 2: price = 12.00; break;
            case 3: price = 8.50; break;
            case 4: price = 2.00; break;
        }

        subtotal = price * quantity;
        total += subtotal;

        printf("Item Total: $%.2f\n", subtotal);
    }

    gstAmount = total * gstRate;
    grandTotal = total + gstAmount;

    // Final Bill
    printf("\n====================================");
    printf("\n       OFFICIAL INVOICE - 2026       ");
    printf("\n====================================");
    printf("\nCustomer Name : %s", customerName);
    printf("\nSubtotal      : $%.2f", total);
    printf("\nGST (18%%)     : $%.2f", gstAmount);
    printf("\n------------------------------------");
    printf("\nGRAND TOTAL   : $%.2f", grandTotal);
    printf("\n------------------------------------");
    printf("\n   Thank you for your visit!         \n");

    return 0;
}
