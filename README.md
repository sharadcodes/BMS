# BANK MANAGEMENT SOFTWARE
# ALL RIGHTS RESERVED
## PROGRAMMING LANGUAGE USED : ANSI C
### :white_check_mark: IN FINAL TESTING STAGE :white_check_mark:
### :warning: Use `Code::Blocks` IDE for this project :warning:

```c
/******************************* BANK MANAGEMENT SOFTWARE  *********************************/

/********************************** FILE INCLUSION *****************************************/

#include<windows.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/******************** MACRO DEFINITIONS FOR PRINTING LINES AND TABS ************************/

#define SIDETAB printf("\t\t\t\t\t");
#define CLS system("cls");

void lists(void);          /* FOR DISPLAYING THE LIST OF ALL ACOUNTS */
void close(void);          /* FOR COSING AN ACCOUNT                  */
void acc(void);            /* FOR THE ADD & REMOVE ACCOUNT MENU      */
void show(void);           /* FOR DISPLAYING A SINGLE ACCOUNT DETAILS*/
void login(void);          /* FOR THE LOGIN SCREEN                   */
void credits(void);        /* FOR THE DISPLAY OF CREDITS ON EXIT     */
void loading(void);        /* FOR THE LODING ANIMATION AT THE START  */
void modify(void);         /* FOR MODIFICATION OF AN ACCOUNT DETAILS */
void withdraw(void);       /* FOR MODIFICATION OF AN ACCOUNT DETAILS */
void deposit(void);        /* FOR MODIFICATION OF AN ACCOUNT DETAILS */

/*************************** FUNCTIONS FOR PRINTING LINES **********************************/

void line(void);
void newline(void);
void solidline(void);
void newsolidline(void);
void hashline(void);

void newline()
{
    int i;
    printf("\n\n\n\n\n\t\t\t\t\t");
    for(i=1;i<=57;i++)
    {
        printf("=");
    }
    printf("\n\n");
}
void line()
{
    int i;
    printf("\n\t\t\t\t\t");
    for(i=1;i<=57;i++)
    {
        printf("=");
    }
    printf("\n\n");
}
void hashline()
{
    int i;
    printf("\t\t\t\t\t");
    for(i=1;i<=57;i++)
    {
        printf("#");
    }
    printf("\n");
}
void newsolidline()
{
    int i;
    printf("\n\n\n\n\n\t\t\t\t\t");
    for(i=1;i<=57;i++)
    {
        printf("%c",254);
    }
    printf("\n\n");
}
void solidline()
{
    int i;
    printf("\n\t\t\t\t\t");
    for(i=1;i<=57;i++)
    {
        printf("%c",254);
    }
    printf("\n\n");
}


/*************************** STRUCTURES FOR ACCOUNT DETAILS ********************************/

typedef struct
{
  int a_number;                 /* FOR STORING THE ACCOUNT NUMBER                */
  char name[30];                /* FOR STORING THE ACCOUNT NUMBER                */
  int m_no;                     /* FOR STORING THE HOLDER NAME                   */
  char address[100];            /* FOR STORING THE HOLDER ADDRESS                */
  int balance;                  /* FOR STORING THE BALANCE DEPOSITED             */
  int a_chk;                    /* FOR STORING THE CHECKING ACCOUNT NUMBER       */
}accounts;
accounts records;

/************************************ FILE POINTER *****************************************/

FILE *ptr;

/********************* GLOBAL VARIABLE FOR CHECKING THE USER LOGIN *************************/

int loginflag=0;


/** MAIN FUNCTION HAS ONLY THE INTERFACE AND THE SWITCH STATEMENTS FOR CHOOSING THE OPTIONS
  *              AFTER CHOOSING THE OPTIONS THE RESPECTED FUNCTIONS ARE CALLED             */

/********************************* MAIN FUNCTION STARTS ************************************/

int main()
{
    int op;
    loading();
    login();
    system("COLOR 0F");
    options:
    newsolidline();
    printf("\t\t\t\t\t\t        BANK MANAGEMENT SOFTWARE\n");
    solidline();
    printf("\t\t\t\t\t       | ENTER THE CHOICE FROM THE OPTIONS BELOW |\n\n");
    printf("\t\t\t\t\t1: Add or Remove account\n");
    printf("\t\t\t\t\t2: Withdraw\n");
    printf("\t\t\t\t\t3: Deposit\n");
    printf("\t\t\t\t\t4: Show details of an account\n");
    printf("\t\t\t\t\t5: Show details of all accounts\n");
    printf("\t\t\t\t\t6: Modify an account\n\n");
    hashline();
    printf("\t\t\t\t\t9: LOG OUT \n");
    printf("\t\t\t\t\t0: EXIT \n\n");
    printf("\n\t\t\t\t\tENTER YOUR CHOICE : ");
    scanf("%d",&op);
    switch(op)
    {
    case 1: 	acc();
        break;
	case 2:     withdraw();
        break;
    case 3:     deposit();
        break;
    case 4:     show();
        break;
    case 5:     lists();
		break;
    case 6:     modify();
		break;
    case 9:
         {
                loginflag=0;
                login();
                system("color 0F");
                goto options;
         }
    case 0: 	credits();
        break;
    default:
        {
        SIDETAB
        printf("ENTER A VALID OPTION !");
        sleep(1);
        CLS
        goto options;
        }
    }
    return 0;
}

/********************************** END OF main() FUNCTION ********************************/


/********************* FUNCTION FOR SHOWING DETAILS OF AN ACCOUNT : STARTS ****************/

void show()
{
    recheck:
    ptr=fopen("records.txt","r");
    int given_no,flag;
    CLS
    system("COLOR 0F");
    newsolidline();
    printf("\t\t\t\t\t\t         ACCOUNT SEARCH WIZARD   \n");
    solidline();
    SIDETAB
    printf("ENTER ACCOUNT NUMBER : ");
    scanf("%d",&given_no);
    while(fscanf(ptr,"%d %s %d %s %d",&records.a_number,&records.name,&records.m_no,&records.address,&records.balance)!=EOF)
    {
        if(given_no==records.a_number)
    {
    flag=1;
    printf("\n\t\t\t\t\tDETAILS OF ACCOUNT  : %d",records.a_number);
    printf("\n\t\t\t\t\t========================================================\n");
    SIDETAB
    printf("ACCOUNT NUMBER      : %d\n",records.a_number);
    SIDETAB
    printf("ACCOUNT HOLDER NAME : %s\n",records.name);
    SIDETAB
    printf("CONTACT NUMBER      : %d\n",records.m_no);
    SIDETAB
    printf("ADDRESS             : %s\n",records.address);
    SIDETAB
    printf("BALANCE             : %d\n",records.balance);
    printf("\t\t\t\t\t========================================================\n\n");
    fclose(ptr);
    SIDETAB
    printf("  CHOOSE THE OPTION NOW\n");
    SIDETAB
    printf("  1: MAIN MENU\n");
    SIDETAB
    printf("  2: SEARCH ANOTHER\n");
    SIDETAB
    printf("  0: EXIT\n\n");
    printf("\t\t\t\t\t  ENTER YOUR CHOICE : ");
    int x;
    scanf("%d",&x);
    if(x==1)
        { CLS
          main(); }
    else if(x==2)
        goto recheck;
    else
        credits();
    }
    else if(flag==0)
    {
        system("color C");
        line();
        SIDETAB
        printf("NO RECORD FOUND !!!!!!");
        fclose(ptr);
        credits();
    }
}
    system("color C");
    printf("\n");
    SIDETAB
    printf("\t\t NO RECORD FOUND !!!!!!");
    printf("\n\t\t\t\t\t========================================================\n\n");
    SIDETAB
    printf("  CHOOSE THE OPTION NOW\n");
    SIDETAB
    printf("  1: MAIN MENU\n");
    SIDETAB
    printf("  2: SEARCH ANOTHER\n");
    SIDETAB
    printf("  0: EXIT\n\n");
    printf("\t\t\t\t\t  ENTER YOUR CHOICE : ");
    int x;
    scanf("%d",&x);
    if(x==1)
        { CLS
          main(); }
    else if(x==2)
        goto recheck;
    else
        credits();
    }

/****************** END OF FUNCTION FOR SHOWING DETAILS OF AN ACCOUNT **********************/



/************************** ADD OR REMOVE ACCOUNT FUNCTION :STARTS *************************/

void acc()
{
    int ac_choice;
    system("cls");
    newsolidline();
    printf("\t\t\t\t\tENTER THE CHOICE FROM THE OPTIONS BELOW AND PRESS ENTER \n");
    solidline();
    SIDETAB
    printf("1: ADD AN ACCOUNT\n");
    SIDETAB
    printf("2: REMOVE AN ACCOUNT\n");
    line();
    SIDETAB
    printf("0: EXIT\n");
    SIDETAB
    printf("9: MAIN MENU\n");
    printf("\n\t\t\t\t\tENTER YOUR CHOICE : ");
    scanf("%d",&ac_choice);


/* BLOCK : FOR NEW ACCOUNT -> INSIDE ADD / REMOVE FUNCTION */

            int op;
            acc_re:
            if(ac_choice==1)
    {
            ptr=fopen("records.txt","a+");
            CLS
            newline();
            if(ptr==NULL)
            {
                CLS
                system("color c");
                newline();
                SIDETAB
                printf("          DATABASE FILE NOT FOUND EXITING !!!!!\n");
                line();
                credits();
            }
            else
            printf("\t\t\t\t\t\tENTER THE DETAILS BELOW AND PRESS ENTER\n");
            line();
            SIDETAB
            printf("ENTER ACCOUNT NUMBER       : ");
            scanf("%d",&records.a_chk);
            while(fscanf(ptr,"%d %s %d %s %d",&records.a_number,&records.name,&records.m_no,&records.address,&records.balance)!=EOF)
            {
            if(records.a_number==records.a_chk)
            {
                system("color 0C");
                SIDETAB
                printf("ACCOUNT NUMBER ALREADY EXISTS !  PLEASE WAIT !");
                sleep(1);
                CLS
                newline();
                fclose(ptr);
                system("COLOR 0F");
                goto acc_re;
            }
            }
            getchar();
            SIDETAB
            printf("ENTER ACCOUNT HOLDER NAME  : ");
            gets(records.name);
            SIDETAB
            printf("ENTER MOBILE NUMBER        : ");
            scanf("%d",&records.m_no);
            SIDETAB
            getchar();
            printf("ENTER ADDRESS              : ");
            gets(records.address);
            SIDETAB
            printf("ENTER BALANCE DEPOSITED    : ");
            scanf("%d",&records.balance);
            fprintf(ptr,"%d %s %d %s %d\n",records.a_chk,records.name,records.m_no,records.address,records.balance);
            system("color a");
            printf("\n");
            printf("\n\t\t\t\t\t\t   ACCOUNT CREATED SUCCESSFULLY !!!!!!\n\n");
            fclose(ptr);
            SIDETAB
            printf("CHOOSE THE OPTION NOW\n");
            SIDETAB
            printf("1: MAIN MENU\n");
            SIDETAB
            printf("0: EXIT\n\n");

            printf("\n\t\t\t\t\tENTER YOUR CHOICE : ");
            scanf("%d",&op);
                if(op==1)
                {
                    fclose(ptr);
                    CLS;
                    main();
                }
                else if(op==0)
                {
                    credits();
                    fclose(ptr);
                }
        fclose(ptr);
    }


/*  BLOCK : REMOVING AN ACCOUNT -> INSIDE ADD/REMOVE FUNCTION */

else if(ac_choice==2)

    {
        FILE *new_data,*old_data;
        int adeleted=0,delopt;
        redelete:
		adeleted=0;
        system("COLOR 0F");
        new_data=fopen("newdata.txt","w");
        old_data=fopen("records.txt","r");
        CLS
        newline();
                if(old_data==NULL)
                {
                        fclose(old_data);
                        fclose(new_data);
                        system("del newdata.txt");
                        system("color 0C");
                        CLS
                        newline();
                        SIDETAB
                        printf("          DATABASE FILE NOT FOUND EXITING !!!!!\n");
                        line();
                        sleep(1);
                        credits();
                }
                else if (new_data==NULL)
                    {
                    fclose(old_data);
                    fclose(new_data);
                    system("del newdata.txt");
                    system("color 0C");
                    CLS
                    newline();
                    SIDETAB
                    printf("         NEW DATABASE FILE NOT MADE EXITING !!!!!\n");
                    line();
                    sleep(1);
                    credits();
                }
        printf("\t\t\t\t\t\tENTER THE DETAILS BELOW AND PRESS ENTER\n");
        line();
        SIDETAB
        printf("ENTER ACCOUNT NUMBER       : ");
        scanf("%d",&records.a_chk);
        while(fscanf(old_data,"%d %s %d %s %d",&records.a_number,&records.name,&records.m_no,&records.address,&records.balance)!=EOF)
            {
                        if(records.a_number!=records.a_chk)
                            {
                                fprintf(new_data,"%d %s %d %s %d\n",records.a_number,records.name,records.m_no,records.address,records.balance);
                            }
                        else
                            {
                                adeleted=1;
                            }
            }

                fclose(old_data);
                fclose(new_data);
                system("del records.txt");
                system("ren newdata.txt records.txt");
                if(adeleted!=1)
                {
                        CLS
                        newline();
                        SIDETAB
                        system("color 0C");
                        printf("\t\t ACCOUNT NOT DELETED !!!!\n");
                        SIDETAB
                        printf("\t\t      TRY AGAIN\n");
                        printf("\n\n\t\t\t\t         YOU ENTERED A WRONG A/c No. OR THE A/c DOES NOT EXISTS");
                        line();
                        SIDETAB
                        printf("\t       | CHOOSE THE OPTION BELOW |\n\n");
                        SIDETAB
                        printf("1: RETRY\n");
                        SIDETAB
                        printf("2: MAIN MENU\n");
                        SIDETAB
                        printf("0: EXIT\n");
                        SIDETAB
                        printf("\n\t\t\t\t\tENTER YOUR CHOICE : ");
                        scanf("%d",&delopt);
                            if(delopt==2)
                            {
                                CLS;
                                main();
                            }
                            else if(delopt==1)
                            {
                                    goto redelete;
                            }
                            else
                            {
                                credits();
                            }

                }
                else if(adeleted!=0)
                {
                        adeleted=0;
                        CLS
                        newline();
                        SIDETAB
                        system("color 0A");
                        printf("\t   ACCOUNT DELETED SUCCESSFULLY !!!!\n");
                        line();
                        SIDETAB
                        printf("\t       | CHOOSE THE OPTION BELOW |\n\n");
                        SIDETAB
                        printf("1: DELETE ANOTHER ACCOUNT\n");
                        SIDETAB
                        printf("2: MAIN MENU\n");
                        SIDETAB
                        printf("0: EXIT\n");
                        SIDETAB
                        printf("\n\t\t\t\t\tENTER YOUR CHOICE : ");
                        scanf("%d",&delopt);
                            if(delopt==2)
                            {
                                CLS;
                                main();
                            }
                            else if(delopt==1)
                            {
                                    goto redelete;
                            }
                            else
                            {
                                credits();
                            }
                }

    }


/* BLOCK : RETURNING TO MAIN -> INSIDE ADD / REMOVE FUNCTION */

else if(ac_choice==9)
    {
    ex:
    CLS
    main();
    }

/* BLOCK : EXITING THE PROGRAM -> INSIDE ADD / REMOVE FUNCTION */
    else
    {
        credits();
    }
}
/**************************** END OF ADD / REMOVE ACCOUNT FUNCTION *************************/


/********************************* CREDITS DISPLAY FUNCTION ********************************/

void credits()
{
            CLS
            newsolidline();
            system("COLOR 0F");
            printf("\t\t\t\t\t\t        BANK MANAGEMENT SOFTWARE\n\n");
            printf("\t\t\t\t\t\t   MADE BY : SHARAD RAJ SINGH MAURYA\n");
            printf("\t\t\t\t\t\t    EMAIL ID : mauryablog@gmail.com \n");
            printf("\t\t\t\t\t\t    PROJECT STARTED ON : 08/06/2018 \n");
            printf("\t\t\t\t\t       CREDITS : MYSELF BEACUSE I MADE IT ALONE :)\n");
            solidline();
            SIDETAB
            printf("EXITING .................................................\n\n");
            sleep(3);
            exit(0);
}
/****************************** END OF CREDITS DISPLAY FUNCTION ****************************/


/********************************** LOGIN WINDOW FUNCTION **********************************/

void login()
{
    if(loginflag==0)
    {
    loginflag=1;
    char pass[10],new_pass[10],old_pass[10]="user1";
    int menu_in,sec_key=911;
    int in;
    CLS
    system("COLOR 0F");
    redo:
    newsolidline();
    printf("\t\t\t\t\t\t        BANK MANAGEMENT SOFTWARE\n");
    solidline();
    printf("\t\t\t\t\t\t\t    LOGIN WINDOW\n\n");
    printf("\n\t\t\t\t\tLOGIN PASSWORD : ");
    scanf("%s",&pass);
    if(strcmp(pass,old_pass)==0)
    {
    system("color 0A");
    CLS
    newsolidline();
    printf("\t\t\t\t\t\t            ACCESS GRANTED !!\n");
    solidline();
    sleep(1);
    CLS
    }
    else
    {
    system("color 0C");
    CLS
    newsolidline();
    printf("\t\t\t\t\t\t             ACCESS DENIED !!\n \n");
    SIDETAB
    printf("\t       PASSWORD DID NOT MATCHED !!!!\n");
    solidline();
    SIDETAB
    printf("  CHOOSE THE OPTION NOW\n");
    SIDETAB
    printf("  1: RETRY\n");
    SIDETAB
    printf("  0: EXIT\n\n");
    printf("\t\t\t\t\t  ENTER YOUR CHOICE : ");
    int log_choice;
    scanf("%d",&log_choice);
    if(log_choice==1)
        {
             CLS
             goto redo;
        }
    else
    credits();
    }
    }
    else
    CLS;
}
/******************************* END OF LOGIN WINDOW FUNCTION ******************************/


/************************ FUNCTION FOR SHOWING DETAILS OF ALL ACCOUNTS *********************/

void lists()
{
    int flag2=0;
    ptr=fopen("records.txt","r");
    int given_no,flag;
    CLS
    system("COLOR 0F");
    printf("\n\n\n\n\n\t\t\t\t   ");
    printf("=====================================================================\n\n");
    printf("\t\t\t\t\t\t          ACCOUNTS LIST WIZARD   \n\n");
    printf("\t\t\t\t   ");
    printf("=====================================================================\n\n");
    printf("\t\t\t\t   ");
    puts("A\c\t\tHOLDER\t\tMOB No. \t ADDRESS \t BALANCE\n");
    while(fscanf(ptr,"%d %s %d %s %d",&records.a_number,&records.name,&records.m_no,&records.address,&records.balance)!=EOF)
    {
    printf("\n");
    flag2=1;
    printf("\t\t\t\t   ");
    printf("%d\t%s\t%d\t%s\t%d",records.a_number,records.name,records.m_no,records.address,records.balance);
    }
    if(flag2==0)
    {
        SIDETAB
        system("color C");
        printf("NO RECORDS FOUND !\n");
    }
    fclose(ptr);
    printf("\t\t\t\t   ");
    printf("\n");
    printf("\t\t\t\t   ");
    printf("=====================================================================\n");
    printf("\n");
    SIDETAB
    printf("CHOOSE THE OPTION NOW\n");
    SIDETAB
    printf("1: MAIN MENU\n");
    SIDETAB
    printf("0: EXIT\n\n");
    SIDETAB
    printf("ENTER YOUR CHOICE : ");
    int x;
    scanf("%d",&x);
    if(x==1)
        { CLS
          main(); }
    else
        credits();
    }
/*********************END OF FUNCTION FOR SHOWING DETAILS OF ALL ACCOUNTS ******************/


/************************************* LOADING ANIMATION ***********************************/

void loading()
{
    if(loginflag==0)
    {
    int i;
    system("COLOR 09");
    CLS
    newsolidline();
    printf("\t\t\t\t\t\t        BANK MANAGEMENT SOFTWARE\n");
    solidline();
    printf("\t\t\t\t\t\t\t   LOADING ");
    for(i=5;i>=0;i--)
    {
    if(i==0)
    {
        printf("\n\n\t\t\t\t\t\t      LOADED SUCCESFULY !!!!");
        sleep(1);
    }
    else
    {
        sleep(1);
        printf("%c",254);
    }
    }
    }
    else
    CLS
}
/****************************** END OF LOADING ANIMATION FUNCTION **************************/


/********************************** START OF WITHDRAW FUNCTION *****************************/
void withdraw()
{
            FILE *newwith_data,*pwith_data;
        int awithdraw=0,withopt;
        rewithd:
		awithdraw=0;
        system("COLOR 0F");
        newwith_data=fopen("withdraw.txt","w");
        pwith_data=fopen("records.txt","r");
        CLS
        newline();
                if(pwith_data==NULL)
                {
                        fclose(pwith_data);
                        fclose(newwith_data);
                        system("del withdraw.txt");
                        system("color 0C");
                        CLS
                        newline();
                        SIDETAB
                        printf("          DATABASE FILE NOT FOUND EXITING !!!!!\n");
                        line();
                        sleep(1);
                        credits();
                }
                else if (newwith_data==NULL)
                    {
                    fclose(pwith_data);
                    fclose(newwith_data);
                    system("del withdraw.txt");
                    system("color 0C");
                    CLS
                    newline();
                    SIDETAB
                    printf("         NEW DATABASE FILE NOT MADE EXITING !!!!!\n");
                    line();
                    sleep(1);
                    credits();
                }
        printf("\t\t\t\t\t\tENTER THE DETAILS BELOW AND PRESS ENTER\n");
        line();
        SIDETAB
        int a_withdraw=0;
        printf("ENTER ACCOUNT NUMBER       : ");
        scanf("%d",&a_withdraw);
        while(fscanf(pwith_data,"%d %s %d %s %d",&records.a_number,&records.name,&records.m_no,&records.address,&records.balance)!=EOF)
            {
                        if(records.a_number!=a_withdraw)
                            {
                                fprintf(newwith_data,"%d %s %d %s %d\n",records.a_number,records.name,records.m_no,records.address,records.balance);
                            }
                        else if(records.a_number==a_withdraw)
                            {
                                int wbalance=0;
                                CLS
                                newsolidline();
                                SIDETAB
                                printf("ENTER THE AMOUNT TO BE WITHDRAWN FROM %d\n",records.a_number);
                                solidline();
                                SIDETAB
                                printf("ENTER THE AMOUNT : ");
                                scanf("%d",&wbalance);
                                records.balance=records.balance-wbalance;
                                fprintf(newwith_data,"%d %s %d %s %d\n",records.a_number,records.name,records.m_no,records.address,records.balance);
                                awithdraw=1;
                            }
            }

                fclose(pwith_data);
                fclose(newwith_data);
                system("del records.txt");
                system("ren withdraw.txt records.txt");
                if(awithdraw!=1)
                {
                        CLS
                        newline();
                        SIDETAB
                        system("color 0C");
                        printf("\t\t  AMOUNT NOT WITHDRAWN !!!!\n");
                        SIDETAB
                        printf("\t\t      TRY AGAIN\n");
                        printf("\n\n\t\t\t\t         YOU ENTERED A WRONG A/c No. OR THE A/c DOES NOT EXISTS");
                        line();
                        SIDETAB
                        printf("\t       | CHOOSE THE OPTION BELOW |\n\n");
                        SIDETAB
                        printf("1: RETRY\n");
                        SIDETAB
                        printf("2: MAIN MENU\n");
                        SIDETAB
                        printf("0: EXIT\n");
                        SIDETAB
                        printf("\n\t\t\t\t\tENTER YOUR CHOICE : ");
                        scanf("%d",&withopt);
                            if(withopt==2)
                            {
                                CLS;
                                main();
                            }
                            else if(withopt==1)
                            {
                                    goto rewithd;
                            }
                            else
                            {
                                credits();
                            }

                }
                else if(awithdraw!=0)
                {
                        awithdraw=0;
                        CLS
                        newline();
                        SIDETAB
                        system("color 0A");
                        printf("\t   AMOUNT WITHDRAWN SUCCESSFULLY !!!!\n");
                        line();
                        SIDETAB
                        printf("\t       | CHOOSE THE OPTION BELOW |\n\n");
                        SIDETAB
                        printf("1: WITHDRAW FROM ANOTHER ACCOUNT\n");
                        SIDETAB
                        printf("2: MAIN MENU\n");
                        SIDETAB
                        printf("0: EXIT\n");
                        SIDETAB
                        printf("\n\t\t\t\t\tENTER YOUR CHOICE : ");
                        scanf("%d",&withopt);
                            if(withopt==2)
                            {
                                CLS;
                                main();
                            }
                            else if(withopt==1)
                            {
                                    goto rewithd;
                            }
                            else
                            {
                                credits();
                            }
                }

}
/******************************** END OF WITHDRAW FUNCTION *********************************/



/******************************** START OF DEPOSIT FUNCTION ********************************/
void deposit()
{
        FILE *newdep_data,*pdep_data;
        int adeposit=0,depopt;
        redeposit:
		adeposit=0;
        system("COLOR 0F");
        newdep_data=fopen("newdep.txt","w");
        pdep_data=fopen("records.txt","r");
        CLS
        newline();
                if(pdep_data==NULL)
                {
                        fclose(pdep_data);
                        fclose(newdep_data);
                        system("del newdep.txt");
                        system("color 0C");
                        CLS
                        newline();
                        SIDETAB
                        printf("          DATABASE FILE NOT FOUND EXITING !!!!!\n");
                        line();
                        sleep(1);
                        credits();
                }
                else if (newdep_data==NULL)
                    {
                    fclose(pdep_data);
                    fclose(newdep_data);
                    system("del newdep.txt");
                    system("color 0C");
                    CLS
                    newline();
                    SIDETAB
                    printf("         NEW DATABASE FILE NOT MADE EXITING !!!!!\n");
                    line();
                    sleep(1);
                    credits();
                }
        printf("\t\t\t\t\t\tENTER THE DETAILS BELOW AND PRESS ENTER\n");
        line();
        SIDETAB
        int a_dep=0;
        printf("ENTER ACCOUNT NUMBER       : ");
        scanf("%d",&a_dep);
        while(fscanf(pdep_data,"%d %s %d %s %d",&records.a_number,&records.name,&records.m_no,&records.address,&records.balance)!=EOF)
            {
                        if(records.a_number!=a_dep)
                            {
                                fprintf(newdep_data,"%d %s %d %s %d\n",records.a_number,records.name,records.m_no,records.address,records.balance);
                            }
                        else if(records.a_number==a_dep)
                            {
                                int newbalance=0;
                                CLS
                                newsolidline();
                                SIDETAB
                                printf("ENTER THE AMOUNT TO BE DEPOSITED IN %d\n",records.a_number);
                                solidline();
                                SIDETAB
                                printf("ENTER THE AMOUNT : ");
                                scanf("%d",&newbalance);
                                records.balance=records.balance+newbalance;
                                fprintf(newdep_data,"%d %s %d %s %d\n",records.a_number,records.name,records.m_no,records.address,records.balance);
                                adeposit=1;
                            }
            }

                fclose(pdep_data);
                fclose(newdep_data);
                system("del records.txt");
                system("ren newdep.txt records.txt");
                if(adeposit!=1)
                {
                        CLS
                        newline();
                        SIDETAB
                        system("color 0C");
                        printf("\t\t  AMOUNT NOT DEPOSITED !!!!\n");
                        SIDETAB
                        printf("\t\t      TRY AGAIN\n");
                        printf("\n\n\t\t\t\t         YOU ENTERED A WRONG A/c No. OR THE A/c DOES NOT EXISTS");
                        line();
                        SIDETAB
                        printf("\t       | CHOOSE THE OPTION BELOW |\n\n");
                        SIDETAB
                        printf("1: RETRY\n");
                        SIDETAB
                        printf("2: MAIN MENU\n");
                        SIDETAB
                        printf("0: EXIT\n");
                        SIDETAB
                        printf("\n\t\t\t\t\tENTER YOUR CHOICE : ");
                        scanf("%d",&depopt);
                            if(depopt==2)
                            {
                                CLS;
                                main();
                            }
                            else if(depopt==1)
                            {
                                    goto redeposit;
                            }
                            else
                            {
                                credits();
                            }

                }
                else if(adeposit!=0)
                {
                        adeposit=0;
                        CLS
                        newline();
                        SIDETAB
                        system("color 0A");
                        printf("\t   AMOUNT DEPOSITED SUCCESSFULLY !!!!\n");
                        line();
                        SIDETAB
                        printf("\t       | CHOOSE THE OPTION BELOW |\n\n");
                        SIDETAB
                        printf("1: DEPOSITE TO ANOTHER ACCOUNT\n");
                        SIDETAB
                        printf("2: MAIN MENU\n");
                        SIDETAB
                        printf("0: EXIT\n");
                        SIDETAB
                        printf("\n\t\t\t\t\tENTER YOUR CHOICE : ");
                        scanf("%d",&depopt);
                            if(depopt==2)
                            {
                                CLS;
                                main();
                            }
                            else if(depopt==1)
                            {
                                    goto redeposit;
                            }
                            else
                            {
                                credits();
                            }
                }

}
/********************************** END OF DEPOSIT FUNCTION ********************************/



/********************************* START OF MODIFY FUNCTION ********************************/
void modify()
{
    FILE *mod_data,*pre_data;
        int amodified=0,modopt;
        remodify:
		amodified=0;
        system("COLOR 0F");
        mod_data=fopen("newmod.txt","w");
        pre_data=fopen("records.txt","r");
        CLS
        newline();
                if(pre_data==NULL)
                {
                        fclose(pre_data);
                        fclose(mod_data);
                        system("del newmod.txt");
                        system("color 0C");
                        CLS
                        newline();
                        SIDETAB
                        printf("          DATABASE FILE NOT FOUND EXITING !!!!!\n");
                        line();
                        sleep(1);
                        credits();
                }
                else if (mod_data==NULL)
                    {
                    fclose(pre_data);
                    fclose(mod_data);
                    system("del newmod.txt");
                    system("color 0C");
                    CLS
                    newline();
                    SIDETAB
                    printf("         NEW DATABASE FILE NOT MADE EXITING !!!!!\n");
                    line();
                    sleep(1);
                    credits();
                }
        printf("\t\t\t\t\t\tENTER THE DETAILS BELOW AND PRESS ENTER\n");
        line();
        SIDETAB
        int a_mod=0;
        printf("ENTER ACCOUNT NUMBER       : ");
        scanf("%d",&a_mod);
        while(fscanf(pre_data,"%d %s %d %s %d",&records.a_number,&records.name,&records.m_no,&records.address,&records.balance)!=EOF)
            {
                        if(records.a_number!=a_mod)
                            {
                                fprintf(mod_data,"%d %s %d %s %d\n",records.a_number,records.name,records.m_no,records.address,records.balance);
                            }
                        else if(records.a_number==a_mod)
                            {
                                CLS
                                newsolidline();
                                SIDETAB
                                printf("ENTER THE NEW DATA FOR %d\n",records.a_number);
                                solidline();
                                SIDETAB
                                fflush(stdin);
                                printf("ENTER ACCOUNT HOLDER NAME  : ");
                                gets(records.name);
                                SIDETAB
                                printf("ENTER MOBILE NUMBER        : ");
                                scanf("%d",&records.m_no);
                                SIDETAB
                                getchar();
                                printf("ENTER ADDRESS              : ");
                                gets(records.address);
                                SIDETAB
                                printf("ENTER BALANCE DEPOSITED    : ");
                                scanf("%d",&records.balance);
                                fprintf(mod_data,"%d %s %d %s %d\n",records.a_number,records.name,records.m_no,records.address,records.balance);
                                amodified=1;
                            }
            }

                fclose(pre_data);
                fclose(mod_data);
                system("del records.txt");
                system("ren newmod.txt records.txt");
                if(amodified!=1)
                {
                        CLS
                        newline();
                        SIDETAB
                        system("color 0C");
                        printf("\t\t ACCOUNT NOT MODIFIED !!!!\n");
                        SIDETAB
                        printf("\t\t      TRY AGAIN\n");
                        printf("\n\n\t\t\t\t         YOU ENTERED A WRONG A/c No. OR THE A/c DOES NOT EXISTS");
                        line();
                        SIDETAB
                        printf("\t       | CHOOSE THE OPTION BELOW |\n\n");
                        SIDETAB
                        printf("1: RETRY\n");
                        SIDETAB
                        printf("2: MAIN MENU\n");
                        SIDETAB
                        printf("0: EXIT\n");
                        SIDETAB
                        printf("\n\t\t\t\t\tENTER YOUR CHOICE : ");
                        scanf("%d",&modopt);
                            if(modopt==2)
                            {
                                CLS;
                                main();
                            }
                            else if(modopt==1)
                            {
                                    goto remodify;
                            }
                            else
                            {
                                credits();
                            }

                }
                else if(amodified!=0)
                {
                        amodified=0;
                        CLS
                        newline();
                        SIDETAB
                        system("color 0A");
                        printf("\t   ACCOUNT MODIFIED SUCCESSFULLY !!!!\n");
                        line();
                        SIDETAB
                        printf("\t       | CHOOSE THE OPTION BELOW |\n\n");
                        SIDETAB
                        printf("1: MODIFY ANOTHER ACCOUNT\n");
                        SIDETAB
                        printf("2: MAIN MENU\n");
                        SIDETAB
                        printf("0: EXIT\n");
                        SIDETAB
                        printf("\n\t\t\t\t\tENTER YOUR CHOICE : ");
                        scanf("%d",&modopt);
                            if(modopt==2)
                            {
                                CLS;
                                main();
                            }
                            else if(modopt==1)
                            {
                                    goto remodify;
                            }
                            else
                            {
                                credits();
                            }
                }

}
/********************************** END OF MODIFY FUNCTION *********************************/
```