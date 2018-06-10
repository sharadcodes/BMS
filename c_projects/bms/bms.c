#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/* MACRO DEFINITIONS FOR PRINTING LINENE AND TABS FOR EASE OF USE */

#define HLINE printf("\t\t\t\t\t#########################################################\n");
#define LINE printf("\n\t\t\t\t\t=========================================================\n\n");
#define NEW printf("\n\n\n\n\n\t\t\t\t\t========================================================\n\n");
#define SIDETAB printf("\t\t\t\t\t");
#define CLS system("cls");

void lists(void);
void close(void);
void acc(void);
void show(void);
void login(void);
void credits(void);

/* STRUCTURES FOR ACCOUNT DETAILS */

typedef struct
{
  int a_number;                   /* FOR STORING THE ACCOUNT NUMBER                */
  char name[30];				  /* FOR STORING THE ACCOUNT NUMBER                */
  int m_no;     		          /* FOR STORING THE HOLDER NAME                   */
  char address[100];              /* FOR STORING THE HOLDER ADDRESS                */
  int balance;         			  /* FOR STORING THE BALANCE DEPOSITED             */
}accounts;
accounts records;

/* FILE POINTER */

FILE *ptr;

/* GLOBAL VARIABLE FOR CHECKIN THE USER LOGIN */

int loginflag=0;


/* MAIN FUNCTION HAS ONLY THE INTERFACE AND THE SWITCH STATEMENTS FOR CHOOSING
   THE OPTIONS AFTER CHOOSING THE OPTIONS THE RESPECTED FUNCTIONS ARE CALLED   */

/* MAIN FUNCTION STARTS */

void main()
{
    int op;
    login();
    system("color e");
    options:
    NEW
    printf("\t\t\t\t\t\t WELCOME TO X BANK MANAGEMENT SOFTWARE\n");
    LINE
    printf("\t\t\t\t\tENTER THE CHOICE FROM THE OPTIONS BELOW AND PRESS ENTER \n");
    LINE
    printf("\t\t\t\t\t1: ADD OR REMOVE ACCOUNT\n");
    printf("\t\t\t\t\t2: DEBIT ACCOUNT OR CREDIT ACCOUNT\n");
    printf("\t\t\t\t\t3: SHOW DETAILS OF AN ACCOUNT\n");
    printf("\t\t\t\t\t4: SHOW DETAILS OF ALL ACCOUNTS\n");
    printf("\t\t\t\t\t5: MODIFY AN ACCOUNT\n\n");
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
    case 3: 	show();
        break;
    case 4:     lists();
        break;
    case 5:
		break;
    case 0: 	credits();
        break;
    }
    return 0;
}
/* END OF main() FUNCTION */


/* FUNCTION FOR SHOWING DETAILS OF AN ACCOUNT STARTS */

void show()
{
    recheck:
    ptr=fopen("records.txt","r");
    int given_no,flag;
    CLS
    system("color B");
    NEW
    printf("\t\t\t\t\t\t   WELCOME TO ACCOUNT SEARCH WIZARD   \n");
    LINE
    printf("\t\t\t\t\tENTER THE ACCOUNT NUMBER BELOW AND PRESS THE ENTER KEY  \n");
    LINE
    printf("\t\t\t\t\tENTER ACCOUNT NUMBER HERE : ");
    scanf("%d",&given_no);
    while(fscanf(ptr,"%d %s %d %s %d",&records.a_number,&records.name,&records.m_no,&records.address,&records.balance)!=EOF)
    {
        if(given_no==records.a_number)
    {
    flag=1;
    printf("\t\t\t\t\tDETAILS OF ACCOUNT : %d \n",records.a_number);
    HLINE
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
    HLINE
    fclose(ptr);
    SIDETAB
    printf("1: MAIN MENU\n");
    SIDETAB
    printf("2: SEARCH ANOTHER\n");
    SIDETAB
    printf("0: EXIT\n\n");
    printf("\t\t\t\t\tENTER YOUR CHOICE : ");
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
        LINE
        SIDETAB
        printf("NO RECORD FOUND !!!!!!");
        fclose(ptr);
        credits();
    }
}
    SIDETAB
    printf("NO RECORD FOUND !!!!!!");
    LINE
    SIDETAB
    printf("CHOOSE THE OPTIONS NOW\n");
    SIDETAB
    printf("1: MAIN MENU\n");
    SIDETAB
    printf("2: SEARCH ANOTHER\n");
    SIDETAB
    printf("0: EXIT\n\n");
    printf("\t\t\t\t\tENTER YOUR CHOICE : ");
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

/* FUNCTION FOR SHOWING DETAILS OF AN ACCOUNT ENDS */



/* ADD OR REMOVE FUNCTION */

void acc()
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
    LINE
    SIDETAB
    printf("0: EXIT\n");
    SIDETAB
    printf("9: MAIN MENU\n");
    printf("\n\t\t\t\t\tENTER YOUR CHOICE : ");
    scanf("%d",&ac_choice);


 /* NEW ACC CHOICE BLOCK */

            int op;
            if(ac_choice==1)
    {
            ptr=fopen("records.txt","a+");
            CLS
            NEW
            if(ptr==NULL)
            {
                CLS
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
            getchar();
            printf("ENTER ACCOUNT NUMBER       : ");
            scanf("%d",&records.a_number);
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
            fprintf(ptr,"%d %s %d %s %d\n",records.a_number,records.name,records.m_no,records.address,records.balance);
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


/* REMOVING AN ACCOUNT BLOCK */

else if(ac_choice==2)

    {

    }


/* RETURNING TO MAIN BLOCK */

else if(ac_choice==9)
    {
    ex:
    CLS
    main();
    }

/*  EXITING THE PROGRAM */
    else
    {
        credits();
    }
}




/* CREDITS */

void credits()
{
            CLS
            NEW
            system("color 0F");
            printf("\t\t\t\t\t\t     X  BANK MANAGEMENT SOFTWARE\n\n");
            printf("\t\t\t\t\t\t   MADE BY : SHARAD RAJ SINGH MAURYA\n");
            printf("\t\t\t\t\t\t    EMAIL ID : mauryablog@gmail.com \n");
            printf("\t\t\t\t\t\t    PROJECT STARTED ON : 08/06/2018 \n");
            printf("\t\t\t\t\t       CREDITS : MYSELF BEACUSE I MADE IT ALONE :)\n");
            LINE
            SIDETAB
            printf("EXITING .................................................\n\n");
            getchar();
            getchar();
            exit(0);
}



/* LOGIN WINDOWS FUNCTION */

void login()
{
    if(loginflag==0)
    {
    loginflag=1;
    char pass[10],new_pass[10],old_pass[10]="user1";
    int menu_in,sec_key=911;
    int in;
    CLS
    system("color 0F");
    redo:
    NEW
    printf("\t\t\t\t\t\t WELCOME TO X BANK MANAGEMENT SOFTWARE\n");
    printf("\n\t\t\t\t\tENTER THE LOGIN PASSWORD AND PRESS ENTER \n");
    LINE
    printf("\n\t\t\t\t\tENTER YOUR PASSWORD : ");
    scanf("%s",&pass);
    if(strcmp(pass,old_pass)==0)
    CLS
    else
    {
    system("color 0C");
    CLS
    NEW
    SIDETAB
    printf("          PASSWORD DID NOT MATCHED !!!!  EXITING\n\n");
    printf("\t\t\t\t\t\t     X  BANK MANAGEMENT SOFTWARE\n\n");
    printf("\t\t\t\t\t\t   MADE BY : SHARAD RAJ SINGH MAURYA\n");
    printf("\t\t\t\t\t\t    EMAIL ID : mauryablog@gmail.com \n");
    printf("\t\t\t\t\t\t    PROJECT STARTED ON : 08/06/2018 \n");
    printf("\t\t\t\t\t       CREDITS : MYSELF BEACUSE I MADE IT ALONE :)\n");
    LINE
    SIDETAB
    printf("EXITING .................................................\n\n");
    getchar();
    getchar();
    exit(0);
    }
    }
    else
    CLS;
}




/* FOR SHOWING ALL ACCOUNTS */
void lists()
{
    recheck:
    ptr=fopen("records.txt","r");
    int given_no,flag;
    CLS
    system("color B");
    NEW
    printf("\t\t\t\t\t\t   WELCOME TO ACCOUNTS LIST WIZARD   \n");
    LINE
    while(fscanf(ptr,"%d %s %d %s %d",&records.a_number,&records.name,&records.m_no,&records.address,&records.balance)!=EOF)
    {
    flag=1;
    LINE
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
    }
    fclose(ptr);
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
/* ALL ACC FUN ENDS */