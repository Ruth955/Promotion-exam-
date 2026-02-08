#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct user {
    char phone[20];
    char ac[20];
    char password[20];
    float balance;
};

int main() {
    struct user user, usr;
    FILE *fp;
    char filename[50], phone[20], pword[20];
    int opt, choice;
    char cont = 'y';
    float amount;

    printf("\nWhat do you want to do?");
    printf("\n1. Register an account");
    printf("\n2. Login to an existing account");
    printf("\n\nYour choice:\t");
    scanf("%d", &opt);

    if (opt == 1) {
        system("clear"); // Use "cls" for Windows
        printf("Enter your account number:\t");
        scanf("%s", user.ac);
        printf("Enter your phone number:\t");
        scanf("%s", user.phone);
        printf("Enter your new password:\t");
        scanf("%s", user.password);
        user.balance = 0;

        strcpy(filename, user.phone);
        fp = fopen(strcat(filename, ".dat"), "w");
        fwrite(&user, sizeof(struct user), 1, fp);
        if (fwrite != 0) printf("\n\nAccount successfully registered!");
        else printf("\n\nSomething went wrong. Please try again.");
        fclose(fp);
    } 
    
    // Login and Banking Logic
    if (opt == 2) {
        system("clear");
        printf("\nPhone number:\t");
        scanf("%s", phone);
        printf("Password:\t");
        scanf("%s", pword);
        strcpy(filename, phone);
        fp = fopen(strcat(filename, ".dat"), "r");
        
        if (fp == NULL) printf("\nAccount number not registered");
        else {
            fread(&usr, sizeof(struct user), 1, fp);
            fclose(fp);
            if (!strcmp(pword, usr.password)) {
                while (cont == 'y') {
                    system("clear");
                    printf("\nPress 1 for balance inquiry");
                    printf("\nPress 2 for depositing cash");
                    printf("\nPress 3 for cash withdrawal");
                    printf("\nPress 4 for online transfer");
                    printf("\nPress 5 for changing password");
                    printf("\n\nYour choice:\t");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("\nYour current balance is Rs. %.2f", usr.balance);
                            break;
                        case 2:
                            printf("\nEnter the amount:\t");
                            scanf("%f", &amount);
                            usr.balance += amount;
                            fp = fopen(filename, "w");
                            fwrite(&usr, sizeof(struct user), 1, fp);
                            fclose(fp);
                            printf("\nSuccessfully deposited.");
                            break;
                        case 3:
                            printf("\nEnter the amount:\t");
                            scanf("%f", &amount);
                            if (amount > usr.balance) printf("\nInsufficient balance");
                            else {
                                usr.balance -= amount;
                                fp = fopen(filename, "w");
                                fwrite(&usr, sizeof(struct user), 1, fp);
                                fclose(fp);
                                printf("\nSuccessfully withdrawn.");
                            }
                            break;
                        // Case 4 (Transfer) and 5 (Password) would follow similar logic
                   }
                    printf("\nDo you want to continue the transaction? [y/n]:\t");
                    scanf(" %c", &cont);
                }
            } else {
                printf("\nInvalid password");
            }
        }
    }
    return 0;
}
