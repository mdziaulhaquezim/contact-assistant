#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct contact{
    char name[15];
    char org[15];
    char phone[16];
    char add[200];
    char bldgrp[3];
    struct contact *next;
}*contacts;

void insert()
{
    struct contact *temp=(struct contact*)malloc(sizeof(struct contact));
    printf("\n\n\t\tContact Assistant ::\n");
    printf("\t\tInsert Contact\n");
    printf("\n\t\tName : ");
    gets(temp->name);
    printf("\n\t\tOrganization : ");
    gets(temp->org);
    printf("\n\t\tPhone : ");
    gets(temp->phone);
    printf("\n\t\tAddress : ");
    gets(temp->add);
    printf("\n\t\tBlood Group : ");
    gets(temp->bldgrp);

    temp->next=contacts;
    contacts=temp;
}

void display()
{
    struct contact *temp=contacts;
    printf("\n\n\t\tContact Assistant ::\n");
    printf("\t\tContact List\n");

    while(temp!=NULL)
    {
    printf("\n\t\tName : %s", temp->name);
    printf("\n\t\tOrganization : %s", temp->org);
    printf("\n\t\tPhone : "); puts(temp->phone);
    printf("\t\tAddress : %s", temp->add);
    printf("\n\t\tBlood Group : %s", temp->bldgrp);
    temp=temp->next;
    printf("\n");
    }
    printf("\n\t\t\t----END----\n\n");
}

void main()
{
    int i,n;
    char c;
    contacts=NULL;
    printf("\n\n\t\tContact Assistant ::\n");
    printf("\t\tWhat you want to do?\n");
    printf("\n\t\t(A) Insert Contact\t(B) Display Contacts");
    scanf("%c", &c);

    switch(c)
    {
        case 'A' :
        printf("\n\t\tHow many number of contacts do you want to insert?");
        scanf("%d", &n);
        getchar();
        for(i=0; i<n; i++)
        {
            insert();
        }
        display();
        break;

        case 'B' : display(); break;
    }

}
