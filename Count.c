//program to count the number of nodes in linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*x,*start=NULL,*temp;

void insert();
void display();

void main()
{
    int ch,count=0;
    printf("\nMENU\n1.Create\n2.Display\n3.Count\n4.Exit\n");
    while(1)
    {
        printf("\nEnter the choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            insert();
            break;

            case 2:
            display();
            break;

            case 3:
            temp=start;
            while(temp!=NULL)
            {
                count++;
                temp=temp->next;
            }
            printf("Number of nodes: %d\n",count);
            break;
            
            case 4:
            exit(0);

            default:
            printf("Invalid choice\n");
        }
    }
}


void insert()
{
    int item;
    printf("Enter the item\n");
    scanf("%d",&item);
    x=(struct node *)malloc(sizeof(struct node));
    x->data=item;
    x->next=NULL;
    if(start==NULL)
    {
        start=x;
        temp=x;
    }
    else
    {
        temp->next=x;
        temp=x;        
    }
}


void display()
{
    temp=start;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}