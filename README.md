## BANK MANAGEMENT SYATEM

```markdown
Syntax highlighted code block

**Bold** and _Italic_ and `Code` text

'
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct
{
    char name[30];
    char ac_no[15];
    float balance;
    float amt;
    int date;
}bank;
bank clients[100];
void main()
{
    int option;
    printf("\n\n\n\n\n\t\t\t\t\t***************************************\n");
    printf("\t\t\t\t\tWELCOME TO MY BANK MANAGEMENT SOFTWARE\n\n");
    printf("\t\t\t\t\t*************************************************\n");
    printf("\t\t\t\t\tENTER THE CHOICE FROM THE OPTIONS BELOW AND PRESS ENTER \n");
    printf("\t\t\t\t\t*************************************************\n\n");
    printf("\t\t\t\t\t1: ADD/REMOVE Account(s)\n");
    printf("\t\t\t\t\t2: Debit/Credit Account\n");
    printf("\t\t\t\t\t3: Make a new Account\n");
    printf("\t\t\t\t\t4: CHECK BALANCE in Account\n");
    printf("\t\t\t\t\t5: CHECK DETAILS\n");
    printf("\n\t\t\t\t\tENTER YOUR CHOICE : ");
    scanf("%d",&option);
    switch(option)
    {
case 1:
    {
    system("cls");
    printf("\n\n\n\n\n\t\t\t\t\t*********************\n");
    printf("\t\t\t\t\tADD/REMOVE Account(s)\n");
    printf("\t\t\t\t\t*********************\n");
    printf("\t\t\t\t\t1: ADD ACCOUNT\n");
    printf("\t\t\t\t\t2: REMOVE ACCOUNT\n");
    break;
    }
case 2:
    {
    system("cls");
    printf("\n\n\n\n\n\t\t\t\t\t*********************\n");
    printf("\t\t\t\t\tDebit/Credit Account \n");
    printf("\t\t\t\t\t*********************\n");
    printf("\t\t\t\t\t1: DEBIT\n");
    printf("\t\t\t\t\t2: CREDIT\n");
    break;
    }
case 3:
    {
    system("cls");
    printf("\n\n\n\n\n\t\t\t\t\t*********************\n");
    printf("\t\t\t\t\t Make a new Account \n");
    printf("\t\t\t\t\t*********************\n");
    printf("\t\t\t\t\t1: SAVINGS\n");
    printf("\t\t\t\t\t1: CURRENT\n");
    scanf("%d",&option);
    switch(option)
    {
    case 1:
        {
        printf("Enter the ACCOUNT NUMBER : ");
        scanf("%s",ac_no);
        printf("Enter the NAME OF HOLDER: ");
        scanf("%s",name);
        printf("Enter the BALANCE : ");
        scanf("%f",&balance);
        }
    }
    break;
    }
case 4:
    {
    system("cls");
    printf("\n\n\n\n\n\t\t\t\t\t*********************\n");
    printf("\t\t\t\t\tCHECK BALANCE in Account\n");
    printf("\t\t\t\t\t*********************\n");
    printf("\t\t\t\t\t1: ADD ACCOUNT\n");
    printf("\t\t\t\t\t2: REMOVE ACCOUNT\n");
    break;
    }
case 5:
    {
    system("cls");
    printf("\n\n\n\n\n\t\t\t\t\t*********************\n");
    printf("\t\t\t\t\t CHECK DETAILS \n");
    printf("\t\t\t\t\t*********************\n");
    printf("\t\t\t\t\t1: ADD ACCOUNT\n");
    printf("\t\t\t\t\t2: REMOVE ACCOUNT\n");
    break;
    }
}
}
'

[Link](url) and ![Image](src)
```