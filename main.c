//
//  main.c
//  XBANKX
//
//  Created by Jude Willis on 04/03/2020.
//  Copyright © 2020 Jude Willis. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool checkCharacter(bool);
void createAccount(void);
void showAccountInfo(char[20]);
void deleteAccount(void);
void withdrawMoney(void);
void depositMoney(char[20]);
void exit(int status);


int main(int argc, const char * argv[]) {

    printf("Welcome to Bank2Moi \n");
    printf("Please press c to create an account \n");
    printf("Please press i to show account information \n");
    printf("Please press d to delete an account \n");
    printf("Please press w to withdraw money from an account \n");
    printf("Please press g to deposit money to an account \n");
    printf("Please press e to exit Bank2Moi \n");
    
    bool isCorrect = false;
    
    while(isCorrect == false){
        isCorrect = checkCharacter(isCorrect);
    }
    
    return 0;
}

bool checkCharacter(bool isCorrect){
    char inputLetter[1];
    char accountNumber[20];
    scanf("%s", inputLetter);
    isCorrect = true;
    switch (*inputLetter) {
        case 'c':
            isCorrect = true;
            printf("You have selected create an account \n");
            createAccount();
            break;
        case 'i':
            isCorrect = true;
            printf("You have selected show account information \n");
            printf("Please enter your account number \n");
            scanf("%s", accountNumber);
            showAccountInfo(accountNumber);
            break;
        case 'd':
            isCorrect = true;
            printf("You have selected delete account \n");
            break;
        case 'w':
            isCorrect = true;
            printf("You have selected withdraw money from an account \n");
            break;
        case 'g':
            isCorrect = true;
            printf("You have selected deposit money to an account \n");
            printf("Please enter your account number \n");
            scanf("%s", accountNumber);
            depositMoney(accountNumber);
            break;
        case 'e':
            isCorrect = true;
            printf("Enjoy your day!");
            exit(0);
            break;
        default:
            isCorrect = false;
            printf("Please enter a valid character to continue \n");
            break;
    }
    return isCorrect;
}

void createAccount(){
    char accountNumber[10];
    char sortCode[10] = "234689";
    char firstName[20];
    char lastName[20];
    char emailAddress[20];
    char balance[20];
    
    printf("Please enter your first name \n");
    scanf("%s", firstName);
    printf("Please enter your last name \n");
    scanf("%s", lastName);
    printf("Please enter your email address \n");
    scanf("%s", emailAddress);
    
    int r = rand() % 100;
    sprintf(accountNumber, "%d", r);
    
    char *accountData[6];
    accountData[0] = accountNumber;
    accountData[1] = sortCode;
    accountData[2] = firstName;
    accountData[3] = lastName;
    accountData[4] = emailAddress;
    accountData[5] = balance;
    
    FILE *file = fopen("bankDetails.txt", "a");
    for (int z = 0; z < 6; z++) {
        fprintf(file, "%s \n", accountData[z]);
    }
    fclose(file);
}

void showAccountInfo(char accountNumber[20]){
    FILE *file = fopen("bankDetails.txt", "r");
    char line[250];
    char checkingNumber[20];
    strcpy(checkingNumber, accountNumber);
    char addSpace[20] = " \n";
    strcat(checkingNumber, addSpace);
    while(fgets(line, 250, file) != NULL){
        if(strcmp(line, checkingNumber) == 0){
            for(int d = 0; d < 5; d++){
                fgets(line, 250, file);
                printf("%s", line);
            }
        }
    }
    fclose(file);
}

void deleteAccount(){
  //File *file = fopen("bankDetails.txt", "w")
}

void withdrawMoney(){
    
}

void depositMoney(char accountNumber[20]){
    FILE *file = fopen("bankDetails.txt", "w");
    char balance[20] = "200";
    char line[250];
    char checkingNumber[20];
    strcpy(checkingNumber, accountNumber);
    char addSpace[20] = " \n";
    strcat(checkingNumber, addSpace);
    while(fgets(line, 250, file) != NULL){
        if(strcmp(line, checkingNumber) == 0){
            for(int d = 0; d < 6; d++){
                if(d == 5){
                    fprintf(file, "%s", balance);
                }
            }
        }
    }
}

