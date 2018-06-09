#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>

/* MACRO DEFINITIONS FOR PRINTING LINENE AND TABS FOR EASE OF USE */

#define HLINE printf("\t\t\t\t\t#########################################################\n");
#define LINE printf("\n\t\t\t\t\t=========================================================\n\n");
#define NEW printf("\n\n\n\n\n\t\t\t\t\t========================================================\n\n");
#define SIDETAB printf("\t\t\t\t\t");
#define CLS system("cls");

/* FILE POINTER */

int new_ac(void);         /*     FOR ADDING A NEW ACCOUNT           */
int clo_ac(void);         /*     FOR CLOSING AN ACCOUNT             */
int dr(void);             /*     FOR DEBITING AN ACCOUNT            */
int cr(void);             /*     FOR CREDITING AN ACCOUNT           */
int sd(long double);      /*     FOR SHOWING DETAINS OF AN ACCOUNT  */

// GLOBAL VARIABLES

long double sub_bal;           /* FOR STORING THE BALANCE DEPOSITED             */
char h_name[30],h_ads[100];    /* FOR STORING THE HOLDER NAME AND ADDRESS       */
long double ac_no;             /* FOR STORING THE ACCOUNT NUMBER                */
static int flag=0;             /*  TO TEST THE CONITION THAT THE FUNCTION sd()
                                  IS CALLED FROM THE new_ac() FUNCTION OR NOT   */


/* MAIN FUNCTION HAS ONLY THE INTERFACE AND THE SWITCH STATEMENTS FOR CHOOSING
   THE OPTIONS AFTER CHOOSING THE OPTIONS THE RESPECTED FUNCTIONS ARE CALLED   */

/* MAIN FUNCTION STARTS */

int main()
{
    flag=0;
    system("color a");
    int op;
    options:
    NEW
    printf("\t\t\t\t\t\t WELCOME TO X BANK MANAGEMENT SOFTWARE\n");
    LINE
    printf("\t\t\t\t\tENTER THE CHOICE FROM THE OPTIONS BELOW AND PRESS ENTER \n");
    LINE
    printf("\t\t\t\t\t1: ADD OR REMOVE ACCOUNT\n");
    printf("\t\t\t\t\t2: DEBIT ACCOUNT OR CREDIT ACCOUNT\n");
    printf("\t\t\t\t\t3: SHOW DETAILS OF ACCOUNT\n");
    printf("\t\t\t\t\t4: MODIFY AN ACCOUNT\n\n");
    HLINE
    printf("\t\t\t\t\t0: EXIT \n\n");
    printf("\n\t\t\t\t\tENTER YOUR CHOICE : ");
    scanf("%d",&op);
    switch(op)
    {
    case 1:
        {
            int ac_choice;
            system("cls");
            NEW
            printf("\t\t\t\t\tENTER THE CHOICE FROM THE OPTIONS BELOW AND PRESS ENTER \n");
            LINE
            SIDETAB
            printf("1: ADD AN ACCOUNT\n");
            SIDETAB
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
            NEW
            printf("\t\t\t\t\tENTER THE CHOICE FROM THE OPTIONS BELOW AND PRESS ENTER \n");
            LINE
            SIDETAB
            printf("1: DEBIT AN ACCOUNT\n");
            SIDETAB
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
            NEW
            printf("\t\t\t\t\tENTER THE ACCOUNT NUMBER BELOW AND PRESS ENTER\n");
            LINE
            SIDETAB
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
            NEW
            printf("\t\t\t\t\t     ENTER THE ACCOUNT NUMBER BELOW AND PRESS ENTER\n");
            LINE
            SIDETAB
            printf("\n\t\t\t\t\tENTER ACCOUNT NUMBER TO MODIFY : ");
            scanf("%lf",&mod_ac);
            sd(mod_ac);
            CLS
            goto options;
        }
    case 0:
        {
            CLS
            NEW
            printf("\t\t\t\t\t\t     X  BANK MANAGEMENT SOFTWARE\n\n");
            printf("\t\t\t\t\t\t   MADE BY : SHARAD RAJ SINGH MAURYA\n");
            printf("\t\t\t\t\t       CREDITS : MYSELF BEACUSE I MADE IT ALONE :)\n");
            LINE
            SIDETAB
            printf("EXITING .................................................\n\n");
            exit(0);
        }

    }
    return 0;
}
/* END OF main() FUNCTION */


/* FUNCTION FOR MAKING NEW ACCOUNT STARTS */

int new_ac(void)
{
    system("cls");
    NEW
    printf("\t\t\t\t\t\tENTER THE DETAILS BELOW AND PRESS ENTER\n");
    LINE
    SIDETAB
    getchar();
    printf("ENTER ACCOUNT HOLDER NAME : ");
    gets(h_name);
    SIDETAB
    printf("ENTER ACCOUNT NUMBER : ");
    scanf("%lf",&ac_no);
    SIDETAB
    getchar();
    printf("ENTER ADDRESS : ");
    gets(h_ads);
    SIDETAB
    printf("ENTER BALANCE : ");
    scanf("%lf",&sub_bal);
    flag=1;
    sd(ac_no);
}
/* FUNCTION FOR MAKING NEW ACCOUNT  ENDS */


/* FUNCTION FOR DELETING AN ACCOUNT STARTS */

int clos_ac(void)
{
    system("cls");
    NEW
}
/* FUNCTION FOR DELETING AN ACCOUNT ENDS */


/* FUNCTION FOR DEBITING AN ACCOUNT STARTS */

int dr(void)
{
    system("cls");
    NEW
}
/* FUNCTION FOR DEBITING AN ACCOUNT ENDS */


/* FUNCTION FOR CREDITING AN ACCOUNT  STARTS */

int cr(void)
{
    system("cls");
    NEW
}
/* FUNCTION FOR CREDITING AN ACCOUNT ENDS */


/* FUNCTION FOR SHOWING DETAILS OF AN ACCOUNT STARTS */

int sd(long double search_ac)
{
    system("cls");
    NEW
    if(flag==1)
        {SIDETAB
        printf("\t   ACCOUNT MADE SUCCESSFULLY !!! \n");
        ac_no=search_ac;
        }
    if(flag==2)
        {SIDETAB
        printf("\\  ACCOUNT MODIFIED SUCCESSFULLY !!! \n");
        ac_no=search_ac;
        }
    else if(flag==0)
    printf("\t\t\t\t\tDETAILS OF ACCOUNT : %.0lf \n",ac_no);
    LINE
    HLINE
    SIDETAB
    printf("ACCOUNT HOLDER NAME : %s\n",h_name);
    SIDETAB
    printf("ACCOUNT NUMBER : %.0lf\n",ac_no);
    SIDETAB
    printf("ADDRESS : %s\n",h_ads);
    SIDETAB
    printf("BALANCE : %f\n",sub_bal);
    HLINE
    getchar();
    getchar();
    CLS
    main();
}
/* FUNCTION FOR SHOWING DETAILS OF AN ACCOUNT ENDS */
