# BANK MANAGEMENT SOFTWARE
## PROGRAMMING LANGUAGE USED : ANSI C
### :red_circle: CURRENTLY UNDER DEVELOPMEMT :red_circle: 
### :warning: Use `Code::Blocks` IDE for this project :warning:

```c
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>

#define LI printf("\n\t\t\t\t\t*********************************************************\n\n");
#define NLI printf("\n\n\n\n\n\t\t\t\t\t********************************************************\n\n");
#define SSP printf("\t\t\t\t\t");
#define CLS system("cls");


int new_ac(void);  /*     FOR ADDING A NEW ACCOUNT             */
int clo_ac(void);  /*     FOR CLOSING AN ACCOUNT               */
int dr(void);      /*     FOR DEBITING AN ACCOUNT              */
int cr(void);      /*     FOR CREDITING AN ACCOUNT             */
int sd(void);      /*     FOR SHOWING DETAINS OF AN ACCOUNT    */

// UNIVERSAL VARIABLES

long double sub_bal;
char h_name[30],h_ads[100];
long double ac_no;
int flag=0;


/* MAIN FUNCTION HAS ONLY THE INTERFACE AND THE SWITCH STATEMENTS FOR CHOOSING
   THE OPTIONS AFTER CHOOSING THE OPTIONS THE RESPECTED FUNCTIONS ARE CALLED   */

int main()
{
    int op;
    NLI
    printf("\t\t\t\t\t\t WELCOME TO X BANK MANAGEMENT SOFTWARE\n\n");
    LI
    printf("\t\t\t\t\tENTER THE CHOICE FROM THE OPTIONS BELOW AND PRESS ENTER \n");
    LI
    printf("\t\t\t\t\t1: ADD OR REMOVE Account\n");
    printf("\t\t\t\t\t2: DEBIT A/c OR CREDIR A/c\n");
    printf("\t\t\t\t\t3: CHECK BALANCE\n");
    printf("\t\t\t\t\t4: SHOW DETAILS OF A\n\n");
    printf("\n\t\t\t\t\tENTER YOUR CHOICE : ");
    scanf("%d",&op);
    switch(op)
    {
    case 1:
        {
            int ac_choice;
            system("cls");
            NLI
            printf("\t\t\t\t\tENTER THE CHOICE FROM THE OPTIONS BELOW AND PRESS ENTER \n");
            LI
            SSP
            printf("1: ADD AN A/c\n");
            SSP
            printf("2: REMOVE AN A/c\n");
            printf("\n\t\t\t\t\tENTER YOUR CHOICE : ");
            scanf("%d",&ac_choice);
            if(ac_choice=1)
                new_ac();
            else if(ac_choice=2)
                clo_ac();
            else
                exit(0);
            break;
        }
    case 2:
        {
            int drcr_choice;
            system("cls");
            NLI
            printf("\t\t\t\t\tENTER THE CHOICE FROM THE OPTIONS BELOW AND PRESS ENTER \n");
            LI
            SSP
            printf("1: DEBIT AN A/c\n");
            SSP
            printf("2: CREDIT AN A/c\n");
            printf("\n\t\t\t\t\tENTER YOUR CHOICE : ");
            scanf("%d",&drcr_choice);
            if(drcr_choice=1)
                dr();
            else if(drcr_choice=2)
                cr();
            else
                exit(0);
            break;

        }

    }
    return 0;
}
int new_ac(void)
{
    system("cls");
    NLI
    printf("\t\t\t\t\t\tENTER THE DETAILS BELOW AND PRESS ENTER\n");
    LI
    SSP
    getchar();
    printf("ENTER ACCOUNT HOLDER NAME : ");
    gets(h_name);
    SSP
    printf("ENTER ACCOUNT NUMBER : ");
    scanf("%lf",&ac_no);
    SSP
    getchar();
    printf("ENTER ADDRESS : ");
    gets(h_ads);
    SSP
    printf("ENTER BALANCE : ");
    scanf("%lf",&sub_bal);
    CLS
    NLI
    SSP
    printf("\t    ACCOUNT MADE SUCCESSFULLY !!!!\n");
    SSP
    puts("\t    PRESS ENTER TO SEE DETAILS OF ACCOUNT\n");
    flag=1;
    sd();
}
int clos_ac(void)
{
    system("cls");
    NLI
}
int dr(void)
{
    system("cls");
    NLI
}
int cr(void)
{
    system("cls");
    NLI
}
int sd(void)
{
    system("cls");
    NLI
    if(flag=1)
        {SSP
        printf("\t   ACCOUNT MADE SUCCESSFULLY !!! \n");
        LI
        goto a;
        }
    else
        goto a;
    a:
    printf("\t\t\t\t\tDETAILS OF A\c %d \n",ac_no);
    LI
    SSP
    printf("ACCOUNT HOLDER NAME : %s\n",h_name);
    SSP
    printf("ACCOUNT NUMBER : %.0lf\n",ac_no);
    SSP
    printf("ADDRESS : %s\n",h_ads);
    SSP
    printf("BALANCE : %f\n",sub_bal);
    LI
    getchar();
    exit(0);
}
```