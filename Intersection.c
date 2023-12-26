//program to implement the code to find union or intersection

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*x,*y,*temp1,*temp2,*start1=NULL,*start2=NULL;

void create1();
void create2();
void display1();
void display2();
void union1();
void intersection();

void main()
{
    int ch,n1,n2,i;
    while(1)
    {
        printf("\nMENU\n1.Create1\n2.Create2\n3.Display1\n4.Display2\n5.Union\n6.Intersection\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter the number of nodes in linked list 1 \n");
            scanf("%d",&n1);
            for(i=0;i<n1;i++)
            {
                create1();
            }
            break;

            case 2:
            printf("Enter the number of nodes in linked list 2 \n");
            scanf("%d",&n2);
            for(i=0;i<n2;i++)
            {
                create2();
            }
            break;

            case 3:
            display1();
            break;

            case 4:
            display2();
            break;

            case 5:
            union1();
            break;

            case 6:
            intersection();
            break;

            default:
            printf("WRONG CHOICE..!!!");
        }
    }
}

void create1()
{
    int item;
    printf("Enter the item\n");
    scanf("%d",&item);
    x=(struct node *)malloc(sizeof(struct node));
    x->data=item;
    x->next=NULL;
    if(start1==NULL)
    {
        start1=x;
        temp1=x;
    }
    else
    {
        temp1->next=x;
        temp1=x;
    }
}

void create2()
{
    int item;
    printf("Enter the item\n");
    scanf("%d",&item);
    y=(struct node *)malloc(sizeof(struct node));
    y->data=item;
    y->next=NULL;
    if(start2==NULL)
    {
        start2=y;
        temp2=y;
    }
    else
    {
        temp2->next=y;
        temp2=y;
    }
}

void display1()
{
    if(start1==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp1=start1;
        while(temp1!=NULL)
        {
            printf("%d ",temp1->data);
            temp1=temp1->next;
        }
    }
}

void display2()
{
    if(start2==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp2=start2;
        while(temp2!=NULL)
        {
            printf("%d ",temp2->data);
            temp2=temp2->next;
        }
    }
}

void union1()
{
    int flag=0;
    temp1=start1;
    while(temp1!=NULL)
    {
        printf("%d ",temp1->data);
        temp1=temp1->next;
    }
    temp2=start2;
    while(temp2!=NULL)
    {
        temp1=start1;
        while(temp1!=NULL)
        {
            flag=1;
            if(temp1->data==temp2->data)
            {
                flag=0;
                break;
            }
            temp1=temp1->next;
        }
        if(flag==1)
        {
            printf("%d ",temp2->data);
        }
        temp2=temp2->next;
    }
   
}

void intersection()
{
    temp1=start1;
    while(temp1!=NULL)
    {
        temp2=start2;
        while(temp2!=NULL)
        {
            if(temp1->data==temp2->data)
            {
                printf("%d ",temp1->data);
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
   
}