//program to find the largest element in a doubly linked list 
//try implementing the code to find the position of the nodes as well  

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev,*next;
}*x,*temp,*start=NULL,*prev;

void create();

void main()
{
    int n,i,largest,count=0,position=0;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        create();
    }
    printf("The list is\n");
    temp=start;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }

    //code to find the greatest element in the doubly linked list
    temp=start;
    largest=temp->data;
    while(temp!=NULL)
    {
        if(largest<temp->data)
        {
            largest=temp->data;
        }
        temp=temp->next;
    }
    printf("\nThe largest element is %d\n",largest);

    //code to delete the largest element
    temp=start;
    while(temp!=NULL)
    {
        if(temp->data==largest)
        {
            if(start->next==NULL)
            {
                start=NULL;
            }
            else
            {
                prev->next=temp->next;
                temp->next->prev=prev;
            }
            printf("Deleted element is %d\n",temp->data);
            free(temp);
            break;
        }
        else if(temp->data != largest)
        {
            prev=temp;
            temp=temp->next;
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
    x->prev=NULL;
    if(start==NULL)
    {
        start=x;
        temp=x;
    }
    else
    {
        temp->next=x;
        x->prev=temp;
        temp=x;
    }
}