#include <stdio.h>
#include <string.h>

#define MAX_CUSTOMERS 100

// Structure to store customer details
typedef struct {
    int customerId;
    char name[50];
    int age;
    char roomType;
    int duration;
    float totalBill;
} Customer;

Customer customers[MAX_CUSTOMERS];
int customerCount = 0;
float totalAmount = 0;

// Function declarations
void readDetails(Customer *cust);
float calculateBill(Customer *cust);
void printDetails(Customer *cust);
void searchCustomer(char *name);
void displayMenu();
void nine_eleven();
void printBill(Customer *cust);

int main() {
    int option;
    char searchName[50];

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 2:
                if (customerCount < MAX_CUSTOMERS) {
                    readDetails(&customers[customerCount]);
                    customers[customerCount].totalBill = calculateBill(&customers[customerCount]);
                    customerCount++;
                } else {
                    printf("Max customer limit reached!\n");
                }
                break;
            case 1:
                nine_eleven();
                break;

            case 3:
                printf("Enter customer name to search: ");
                scanf("%s", searchName);
                searchCustomer(searchName);
                break;
            case 4:
                for (int i = 0; i < customerCount; i++) {
                    printBill(&customers[i]);
                }
                break;
            case 5:
                printf("Total Amount Received by Hotel: %.2f\n", totalAmount);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    } while (option != 6);

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n\t  Empire State of Mind");
    printf("\n----- Hotel Management Menu -----\n");
    printf("1. Hotel Rooms info\n");
    printf("2. Add Customer Details\n");
    printf("3. Search Customer by Name\n");
    printf("4. Display All Bills\n");
    printf("5. Show Total Amount Received\n");
    printf("6. Exit\n");
}

// Function to display hotel room info
void nine_eleven() {
    printf("Types of Rooms in the Hotel and Their Details:\n");

    printf("\n1. Single Room (S):\n");
    printf("   - Description: A room with a single bed meant for one person.\n");
    printf("   - Price: 7,500\n");

    printf("\n2. Double Room (D):\n");
    printf("   - Description: A room with one large bed or two single beds for two people.\n");
    printf("   - Price: 15,000\n");

    printf("\n3. Twin Room (T):\n");
    printf("   - Description: A room with two separate beds meant for two people.\n");
    printf("   - Price: 15,000\n");

    printf("\n4. Suite (U):\n");
    printf("   - Description: A large room with a separate living area, designed for luxurious stays.\n");
    printf("   - Price: 30,000\n");

    printf("\n5. Executive Room (E):\n");
    printf("   - Description: A premium room located on a higher floor with additional amenities.\n");
    printf("   - Price: 40,000\n");

    printf("\n6. Deluxe Room (X):\n");
    printf("   - Description: A larger and more luxurious room than standard doubles.\n");
    printf("   - Price: 45,000\n");

    printf("\n7. Presidential Suite (P):\n");
    printf("   - Description: The most luxurious room, often occupying an entire floor.\n");
    printf("   - Price: 50,000\n");
}

// Function to read customer details
void readDetails(Customer *cust) {
    printf("\nEnter Customer ID: ");
    scanf("%d", &cust->customerId);
    printf("Enter Customer Name: ");
    scanf("%s", cust->name);
    printf("Enter Age: ");
    scanf("%d", &cust->age);
    printf("Enter Room Type (S, D, T, U, E, X, P): ");
    scanf(" %c", &cust->roomType);
    printf("Enter Number of Nights of Stay: ");
    scanf("%d", &cust->duration);
}

// Function to calculate the bill
float calculateBill(Customer *cust) {
    float roomRate = 0;
    float totalBill;
    float gst;

    // Assign room rates based on room type
    if (cust->roomType == 'S') {
        roomRate = 7500;
    } else if (cust->roomType == 'D') {
        roomRate = 15000;
    } else if (cust->roomType == 'T') {
        roomRate = 15000;
    } else if (cust->roomType == 'U') {
        roomRate = 30000;
    } else if (cust->roomType == 'E') {
        roomRate = 40000;
    } else if (cust->roomType == 'X') {
        roomRate = 45000;
    } else if (cust->roomType == 'P') {
        roomRate = 50000;
    }

    // Calculate total room rent
    totalBill = roomRate * cust->duration;

    // Add GST (15%)
    gst = 0.15 * totalBill;
    totalBill += gst;

    // Update total amount received by the hotel
    totalAmount += totalBill;

    return totalBill;
}

// Function to print customer details
void printDetails(Customer *cust) {
    printf("Customer ID: %d\n", cust->customerId);
    printf("Name: %s\n", cust->name);
    printf("Age: %d\n", cust->age);
    printf("Room Type: %c\n", cust->roomType);
    printf("Duration of Stay: %d\n", cust->duration);
    printf("Total Bill: %.2f\n", cust->totalBill);
}

// Function to search for a customer by name
void searchCustomer(char *name) {
    int found = 0;
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].name, name) == 0) {
            printDetails(&customers[i]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Customer with name %s not found.\n", name);
    }
}

// Function to print the bill for a customer
void printBill(Customer *cust) {
    printf("\n--- Hotel Bill for %s ---\n", cust->name);
    printDetails(cust);
    printf("--------------------------\n");
}
