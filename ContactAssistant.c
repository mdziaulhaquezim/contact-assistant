#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

void menu();
void add();
void list();
void edit();
void del();
void search();

void setcolor(int ForgC)
{ WORD wColor;
HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbi;

if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
{
	wColor=(csbi.wAttributes & 0xF0)+(ForgC & 0x0F);
//	SetConsoleTextAttributes(hStdOut,wColor);
	SetConsoleTextAttribute(hStdOut,wColor);

}
}

void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{

    printf("\n  **************************  LOGIN FORM  **************************  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword);
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\n       WELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();//holds the screen

	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
}


struct contact{
    char name[15];
    char org[15];
    char phone[16];
    char add[200];
    char bldgrp[3];
    struct contact *next;
}*contact;

int main()
{
	int i=0;
	time_t t;
	time(&t);
	system("cls");
	setcolor(13);
	printf(" ----------------------------------------------------------------------------------\n");
	printf("|                                                                                 |\n");
	printf("|                                                                                 |\n");
	printf("|       OOOOOO   OOOOOO OOOOOO OOOOOO OOOOOO OOOOOO O      O OOOOOOO  OOOOOO      |\n");
	printf("|       O        O    O O      O        O      O    O O    O O        O           |\n");
	printf("|       O  OOOOO OOOOOO OOOOO  OOOOO    O      O    O  O   O O  OOOOO OOOOOO      |\n");
	printf("|       O    O   O  O   O      O        O      O    O   O  O O    O        O      |\n");
	printf("|       OOOOOO   O   O  OOOOOO OOOOOO   O    OOOOOO O    O O OOOOOO   OOOOOO      |\n");
	printf("|                                                                                 |\n");
	printf(" --------------------------------------------------------------------------------\n");
 	printf("\t\t***********************************************************\n");
	printf("\t\t*                                                         *\n");
	printf("\t\t*           ------------------------------                *\n");
	printf("\t\t*            WELCOME TO Contact Assistant                 *\n");
	printf("\t\t*           ------------------------------                *\n");
	printf("\t\t*                                                         *\n");
	printf("\t\t*                                                         *\n");
	printf("\t\t*                                                         *\n");
	printf("\t\t*         181-15-11333    Md. Ziaul Haque Zim             *\n");
    printf("\t\t*         181-15-10684    Md. Rony Howlader               *\n");
    printf("\t\t*         181-15-10650    Md. Atiquzzaman Snigdho         *\n");
    printf("\t\t*         181-15-10669    Reshad Ahamed Rownok            *\n");
	printf("\t\t*                                                         *\n");
	printf("\t\t*         Prepare for,                                    *\n");
	printf("\t\t*                  Moushumi Zaman Bonny                   *\n");
	printf("\t\t*                  Senior Lecturer                        *\n");
    printf("\t\t*    Department of Computer Science and Engineering       *\n");
    printf("\t\t*                                                         *\n");
	printf("\t\t***********************************************************\n");

		for(i=0; i<80; i++)	printf("-");
	    printf("\nCurrent date and time : %s",ctime(&t));

	    for(i=0; i<80; i++) printf("-");
        printf(" \n Press any key to continue:");

	getch();
    system("cls");
    login();
    menu();
}

void menu()
{
	int i=0;

	time_t t;
	time(&t);
	char customername;
	char choice;
    system("cls");
	while (1)      // INFINITE LOOP
	{
		system("cls");
		setcolor(55);
		 for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("   ******************************  |MAIN MENU|  ***************************** \n");
		for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		setcolor(45);
		printf("\t\t *Please enter your choice for menu*:");
		printf("\n\n");
		printf(" \n Enter 1 -> Save a Contact");
		printf("\n-----------------------------------------");
		printf(" \n Enter 2 -> View Contact Record");
		printf("\n-----------------------------------------");
		printf(" \n Enter 3 -> Delete a Contact from Record");
		printf("\n-----------------------------------------");
		printf(" \n Enter 4 -> Search a Contact from Record");
		printf("\n-----------------------------------------");
		printf(" \n Enter 5 -> Edit Contact Record");
		printf("\n-----------------------------------------");
		printf(" \n Enter 6 -> Exit");
		printf("\n-----------------------------------------");
		printf("\n");
		for(i=0;i<80;i++)
		printf("-");
	    printf("\nCurrent date and time : %s",ctime(&t));
	    for(i=0;i<80;i++)
		printf("-");

		choice=getche();
		choice=toupper(choice);
		switch(choice)           // SWITCH STATEMENT
		{
			case '1':   add();      break;
			case '2':   list();     break;
			case '3':   del();      break;
			case '4':   search();   break;
			case '5':	edit();     break;
			case '6':
				system("cls");
				printf("\n\n\t *****THANK YOU*****");
				printf("\n\t FOR TRUSTING OUR SERVICE");
				Sleep(2000);
				exit(0);
				break;

            default:
				system("cls");
				printf("\t\t*****Incorrect Input*****\n");
				printf("\n Press any key to continue......");
				getch();
		}
	}
}


  void add()
{
    int i;
    system("cls");
    printf("\n\n");
    struct contact *temp=(struct contact*)malloc(sizeof(struct contact));

    for(i=0; i<78; i++) printf("-");
    printf("\n\t\tContact Assistant ::\n");
    printf("\t\tInsert Contact\n");
    for(i=0; i<78; i++) printf("-");
    getchar();
    printf("\n\t\tName\t : ");
    gets(temp->name);
    printf("\n\t\tOrganization\t : ");
    gets(temp->org);
    printf("\n\t\tPhone\t : ");
    gets(temp->phone);
    printf("\n\t\tAddress\t : ");
    gets(temp->add);
    printf("\n\t\tBlood Group\t : ");
    gets(temp->bldgrp);

    temp->next=contact;
    contact=temp;
}

void list()
{
    system("cls");
    int i,count = 0;
    struct contact *temp=contact;
    printf("\n\n\t\tContact Assistant ::\n");
    printf("\t\tContact List\n");
    for(i=0; i<78; i++) printf("-");
    printf("\n| No\t Name\t Phone\t\t Address\t Organization\t Blood Group |\n");
    for(i=0;i<78;i++) printf("-");

    while(temp!=NULL)
    {
        count++;
    printf("\n| %d\t %s\t %s\t %s\t %s\t %s ",count, temp->name, temp->phone, temp->add,temp->org,temp->bldgrp);

    temp=temp->next;
    printf("\n");
    }
    for(i=0;i<78;i++) printf("-");
    printf("\n\t\t\t\t----END----\n\n");

    getch();
}

void search()
{
    system("cls");
    char name[20], phnnum[20];
    char sw; char scan[25];
    int i,count = 0;
    struct contact *current = contact;

    printf("\n\n");
    for(i=0; i<78; i++) printf("-");
    printf("\n|\t\tContact Assistant ::\n");
    printf("|\t\tContact Search\n");
    for(i=0; i<78; i++) printf("-");
    printf("\n|\t1. Search by NAME\n");
    printf("|\t2. Search by PHONE Number\n");
    printf("|\t3. Search by Address\n");
    printf("|\t4. Search by Organization\n");
    printf("|\t5. Search by Blood Group\n");
    for(i=0; i<78; i++) printf("-");
    scanf("%s", &sw);
    for(i=0; i<78; i++) printf("-");

    system("cls");
    for(i=0; i<80; i++) printf("-");printf("\n");
    printf("|\t\tPlease Wait... Searching.... Press Any key to continue...\t|\n");
    for(i=0; i<80; i++) printf("-");

    switch(sw)
        {
            case '1':

                printf("\nInput Name :: ");
                scanf("%s", &scan);

                for(i=0; i<78; i++) printf("-");
                printf("\n| No\t Name\t Phone\t\t Address\t Organization\t Blood Group |\n");
                for(i=0;i<78;i++) printf("-");


                   while(current!=NULL) {
      count++;
      if(current->name == 'scan') {
         printf("%d found at position %d\n", scan, count); getchar(); break;
      }

      if(current->next != NULL)
         current = current->next;
      else
         getchar(); break;
   }

   printf("\n%s does not exist in the Contact list\n", scan); getchar(); break;




            case '2':
                printf("\nInput Phone Number :: ");
                gets(scan); getchar();

                for(i=0; i<78; i++) printf("-");
                printf("\n| No\t Name\t Phone\t\t Address\t Organization\t Blood Group |\n");
                for(i=0;i<78;i++) printf("-");

                while(current!=NULL)
                {
                if(current->phone==scan)
                {
                count++;
                printf("\n| %d\t %s\t %s\t %s\t %s\t %s ",count, current->name, current->phone, current->add,current->org,current->bldgrp);
                }
                current=current->next;
                }  break;

            case '3':
                printf("\nInput Address :: ");
                gets(scan);getchar();
                  break;
            case '4':
                printf("\nInput Organization :: ");
                gets(scan); getchar();
               break;
            case '5':
                printf("\nInput Blood Group :: ");
                gets(scan); getchar();

                 break;

            default:
				system("cls");
				for(i=0; i<78; i++) printf("-");
				printf("\t\t\t\tIncorrect Input");
				printf("\n\t\t\t\t Press any key to continue");
				for(i=0; i<78; i++) printf("-");
				getch();
        }


}

void del()
{
    int i=0;
    char name[20], phnnum[20];



}

void edit()
{

}
