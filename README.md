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

#define HS printf("\t\t\t\t\t#########################################################\n");
#define LI printf("\n\t\t\t\t\t=========================================================\n\n");
#define NLI printf("\n\n\n\n\n\t\t\t\t\t========================================================\n\n");
#define SSP printf("\t\t\t\t\t");
#define CLS system("cls");


int new_ac(void);         //     FOR ADDING A NEW ACCOUNT          
int clo_ac(void);         //     FOR CLOSING AN ACCOUNT            
int dr(void);             //     FOR DEBITING AN ACCOUNT           
int cr(void);  		      //     FOR CREDITING AN ACCOUNT          
int sd(long double);      //     FOR SHOWING DETAINS OF AN ACCOUNT 

// GLOBAL VARIABLES

long double sub_bal;           // FOR STORING THE BALANCE DEPOSITED
char h_name[30],h_ads[100];    // FOR STORING THE HOLDER NAME AND ADDRESS
long double ac_no;             // FOR STORING THE ACCOUNT NUMBER
static int flag=0;             // TO TEST THE CONITION THAT THE FUNCTION sd() IS CALLED FROM THE new_ac() FUNCTION OR NOT


/* MAIN FUNCTION HAS ONLY THE INTERFACE AND THE SWITCH STATEMENTS FOR CHOOSING
   THE OPTIONS AFTER CHOOSING THE OPTIONS THE RESPECTED FUNCTIONS ARE CALLED   */

// MAIN FUNCTION STARTS

int main()
{
    flag=0;
    system("color F0");
    int op;
    options:
    NLI
    printf("\t\t\t\t\t\t WELCOME TO X BANK MANAGEMENT SOFTWARE\n");
    LI
    printf("\t\t\t\t\tENTER THE CHOICE FROM THE OPTIONS BELOW AND PRESS ENTER \n");
    LI
    printf("\t\t\t\t\t1: ADD OR REMOVE ACCOUNT\n");
    printf("\t\t\t\t\t2: DEBIT ACCOUNT OR CREDIR ACCOUNT\n");
    printf("\t\t\t\t\t3: SHOW DETAILS OF ACCOUNT\n");
    printf("\t\t\t\t\t4: MODIFY AN ACCOUNT\n\n");
    HS
    printf("\t\t\t\t\t0: EXIT \n\n");
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
            printf("1: ADD AN ACCOUNT\n");
            SSP
            printf("2: REMOVE AN ACCOUNT\n");
            printf("\n\t\t\t\t\tENTER YOUR CHOICE : ");
            scanf("%d",&ac_choice);
            if(ac_choice=1)
                new_ac();
            else if(ac_choice=2)
                clo_ac();
            CLS
            goto options;
        }
    case 2:
        {
            int drcr_choice;
            system("cls");
            NLI
            printf("\t\t\t\t\tENTER THE CHOICE FROM THE OPTIONS BELOW AND PRESS ENTER \n");
            LI
            SSP
            printf("1: DEBIT AN ACCOUNT\n");
            SSP
            printf("2: CREDIT AN ACCOUNT\n");
            printf("\n\t\t\t\t\tENTER YOUR CHOICE : ");
            scanf("%d",&drcr_choice);
            if(drcr_choice=1)
                dr();
            else if(drcr_choice=2)
                cr();
            else
                exit(0);
            CLS
            goto options;
        }
    case 3:
        {
            long double srch_ac;
            system("cls");
            NLI
            printf("\t\t\t\t\tENTER THE ACCOUNT NUMBER BELOW AND PRESS ENTER\n");
            LI
            SSP
            printf("\n\t\t\t\t\tENTER ACCOUNT NUMBER : ");
            scanf("%lf",&srch_ac);
            sd(srch_ac);
            CLS
            goto options;
        }
    case 4:
        {
            long double mod_ac;
            system("cls");
            NLI
            printf("\t\t\t\t\t     ENTER THE ACCOUNT NUMBER BELOW AND PRESS ENTER\n");
            LI
            SSP
            printf("\n\t\t\t\t\tENTER ACCOUNT NUMBER TO MODIFY : ");
            scanf("%lf",&mod_ac);
            sd(mod_ac);
            CLS
            goto options;
        }
    case 0:
        {
            CLS
            NLI
            printf("\t\t\t\t\t\t     X  BANK MANAGEMENT SOFTWARE\n\n");
            printf("\t\t\t\t\t\t   MADE BY : SHARAD RAJ SINGH MAURYA\n");
            printf("\t\t\t\t\t       CREDITS : MYSELF BEACUSE I MADE IT ALONE :)\n");
            LI
            SSP
            printf("EXITING .................................................\n\n");
            exit(0);
        }

    }
    return 0;
}
// END OF main() FUNCTION


//FUNCTION FOR MAKING NEW ACCOUNT STARTS

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
    flag=1;
    sd(ac_no);
}
//FUNCTION FOR MAKING NEW ACCOUNT  ENDS


// FUNCTION FOR DELETING AN ACCOUNT STARTS

int clos_ac(void)
{
    system("cls");
    NLI
}								
// FUNCTION FOR DELETING AN ACCOUNT ENDS


// FUNCTION FOR DEBITING AN ACCOUNT STARTS

int dr(void)
{
    system("cls");
    NLI
}
// FUNCTION FOR DEBITING AN ACCOUNT ENDS


//FUNCTION FOR CREDITING AN ACCOUNT  STARTS

int cr(void)
{
    system("cls");
    NLI
}
//FUNCTION FOR CREDITING AN ACCOUNT ENDS 


//FUNCTION FOR SHOWING DETAILS OF AN ACCOUNT STARTS

int sd(long double search_ac)
{
    system("cls");
    NLI
    if(flag==1)
        {SSP
        printf("\t   ACCOUNT MADE SUCCESSFULLY !!! \n");
        ac_no=search_ac;
        }
    if(flag==2)
        {SSP
        printf("\   ACCOUNT MODIFIED SUCCESSFULLY !!! \n");
        ac_no=search_ac;
        }
    else if(flag==0)
    printf("\t\t\t\t\tDETAILS OF ACCOUNT : %.0lf \n",ac_no);
    LI
    HS
    SSP
    printf("ACCOUNT HOLDER NAME : %s\n",h_name);
    SSP
    printf("ACCOUNT NUMBER : %.0lf\n",ac_no);
    SSP
    printf("ADDRESS : %s\n",h_ads);
    SSP
    printf("BALANCE : %f\n",sub_bal);
    HS
    getchar();
    getchar();
    CLS
    main();
}
	//FUNCTION FOR SHOWING DETAILS OF AN ACCOUNT ENDS
```