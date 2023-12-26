//program to interchange the adjacent nodes in circular linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*x,*start=NULL,*temp,*last;

void create();
void interchange();

void main()
{
    int ch,n,i;
    while(1)
    {
        printf("\nMENU\n1.Create\n2.Display\n3.Interchange\n4.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter the number of nodes\n");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                create();
            }

            case 2:
            temp=start;
            while(temp != last) //keep in mind this condition
            {
                printf("%d ",temp->data);
                temp=temp->next;
            }
            printf("%d ",temp->data);

            case 3:
            interchange();
            break;

            case 4:
            exit(0);

            default :
            printf("WRONG CHOICE !!!");
        }
    }
}

void create()
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
        last=x;
        last->next=start;
    }
    else
    {
        last->next=x;
        last=x;
        last->next=start;
    }
}

void interchange()
{
    int pos,key,i;
    printf("Enter the position to interchange\n");
    scanf("%d",&pos);
    for(i=0;i<pos-1;i++)
    {
        temp=temp->next;
    }
    key=temp->data;
    temp->data=temp->next->data;
    temp->next->data=key;

    printf("Final list after interchanging\n");
    temp=start;
    while(temp != last) //keep in mind this condition
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);
}