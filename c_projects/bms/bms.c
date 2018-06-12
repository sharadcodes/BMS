/******************************* BANK MANAGEMENT SOFTWARE  *********************************/

/********************************** FILE INCLUSION *****************************************/
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/******************** MACRO DEFINITIONS FOR PRINTING LINES AND TABS ************************/
#define BLOCK printf("\n\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254);
#define NBLOCK printf("\n\n\n\n\n\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254);
#define HLINE printf("\t\t\t\t\t########################################################\n");
#define LINE printf("\n\t\t\t\t\t========================================================\n\n");
#define NEW printf("\n\n\n\n\n\t\t\t\t\t========================================================\n\n");
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


/*************************** STRUCTURES FOR ACCOUNT DETAILS ********************************/

typedef struct
{
  int a_number;                   /* FOR STORING THE ACCOUNT NUMBER                */
  char name[30];				  /* FOR STORING THE ACCOUNT NUMBER                */
  int m_no;     		          /* FOR STORING THE HOLDER NAME                   */
  char address[100];              /* FOR STORING THE HOLDER ADDRESS                */
  int balance;         			  /* FOR STORING THE BALANCE DEPOSITED             */
  int a_chk;                      /* FOR STORING THE CHECKING ACCOUNT NUMBER       */
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
    NBLOCK
    printf("\t\t\t\t\t\t        BANK MANAGEMENT SOFTWARE\n");
    BLOCK
    printf("\t\t\t\t\t       | ENTER THE CHOICE FROM THE OPTIONS BELOW |\n\n");
    printf("\t\t\t\t\t1: Add or Remove account\n");
    printf("\t\t\t\t\t2: Withdraw\n");
    printf("\t\t\t\t\t3: Deposit\n");
    printf("\t\t\t\t\t4: Show details of an account\n");
    printf("\t\t\t\t\t5: Show details of all accounts\n");
    printf("\t\t\t\t\t6: Modify an account\n\n");
    HLINE
    printf("\t\t\t\t\t0: EXIT \n\n");
    printf("\n\t\t\t\t\tENTER YOUR CHOICE : ");
    scanf("%d",&op);
    switch(op)
    {
    case 1: 	acc();
        break;
	case 2:
        break;
    case 3:
        break;
    case 4:     show();
        break;
    case 5:     lists();
		break;
    case 6:
		break;
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
    NBLOCK
    printf("\t\t\t\t\t\t         ACCOUNT SEARCH WIZARD   \n");
    BLOCK
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
        LINE
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
    NBLOCK
    printf("\t\t\t\t\tENTER THE CHOICE FROM THE OPTIONS BELOW AND PRESS ENTER \n");
    BLOCK
    SIDETAB
    printf("1: ADD AN ACCOUNT\n");
    SIDETAB
    printf("2: REMOVE AN ACCOUNT\n");
    LINE
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
            NEW
            if(ptr==NULL)
            {
                CLS
                system("color c");
                NEW
                SIDETAB
                printf("          DATABASE FILE NOT FOUND EXITING !!!!!\n");
                LINE
                credits();
            }
            else
            printf("\t\t\t\t\t\tENTER THE DETAILS BELOW AND PRESS ENTER\n");
            LINE
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
                NEW
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
            HLINE
            printf("\n\t\t\t\t\t\t   ACCOUNT CREATED SUCCCESSFULLY !!!!!!\n\n");
            fclose(ptr);
            HLINE
            LINE
            SIDETAB
            printf("ENTER  0 FOR EXIT  OR  1 FOR MAIN MENU\n");
            SIDETAB
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
        NEW
                if(old_data==NULL)
                {
                        fclose(old_data);
                        fclose(new_data);
                        remove("newdata.txt");
                        system("color 0C");
                        CLS
                        NEW
                        SIDETAB
                        printf("          DATABASE FILE NOT FOUND EXITING !!!!!\n");
                        LINE
                        sleep(1);
                        credits();
                }
                else if (new_data==NULL)
                    {
                    fclose(old_data);
                    fclose(new_data);
                    remove("newdata.txt");
                    system("color 0C");
                    CLS
                    NEW
                    SIDETAB
                    printf("         NEW DATABASE FILE NOT MADE EXITING !!!!!\n");
                    LINE
                    sleep(1);
                    credits();
                }
        printf("\t\t\t\t\t\tENTER THE DETAILS BELOW AND PRESS ENTER\n");
        LINE
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
                remove("records.txt");
                rename("newdata.txt","records.txt");
                if(adeleted!=1)
                {
                        CLS
                        NEW
                        SIDETAB
                        system("color 0C");
                        printf("\t\t ACCOUNT NOT DELETED !!!!\n");
                        SIDETAB
                        printf("\t\t      TRY AGAIN\n");
                        printf("\n\n\t\t\t\t         YOU ENTERED A WRONG A/c No. OR THE A/c DOES NOT EXISTS");
                        LINE
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
                        NEW
                        SIDETAB
                        system("color 0A");
                        printf("\t   ACCOUNT DELETED SUCCESSFULLY !!!!\n");
                        LINE
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
            NBLOCK
            system("COLOR 0F");
            printf("\t\t\t\t\t\t        BANK MANAGEMENT SOFTWARE\n\n");
            printf("\t\t\t\t\t\t   MADE BY : SHARAD RAJ SINGH MAURYA\n");
            printf("\t\t\t\t\t\t    EMAIL ID : mauryablog@gmail.com \n");
            printf("\t\t\t\t\t\t    PROJECT STARTED ON : 08/06/2018 \n");
            printf("\t\t\t\t\t       CREDITS : MYSELF BEACUSE I MADE IT ALONE :)\n");
            BLOCK
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
    NBLOCK
    printf("\t\t\t\t\t\t        BANK MANAGEMENT SOFTWARE\n");
    BLOCK
    printf("\t\t\t\t\t\t\t    LOGIN WINDOW\n\n");
    printf("\n\t\t\t\t\tLOGIN PASSWORD : ");
    scanf("%s",&pass);
    if(strcmp(pass,old_pass)==0)
    {
    system("color 0A");
    CLS
    NBLOCK
    printf("\t\t\t\t\t\t            ACCESS GRANTED !!\n");
    BLOCK
    sleep(1);
    CLS
    }
    else
    {
    system("color 0C");
    CLS
    NBLOCK
    printf("\t\t\t\t\t\t             ACCESS DENIED !!\n \n");
    SIDETAB
    printf("\t       PASSWORD DID NOT MATCHED !!!!\n");
    BLOCK
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
    NBLOCK
    printf("\t\t\t\t\t\t        BANK MANAGEMENT SOFTWARE\n");
    BLOCK
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

/****************************** ENDS OF LOADING ANIMATION FUNCTION *************************/