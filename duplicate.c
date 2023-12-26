//program to delete duplicate elements from linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*x,*start=NULL,*temp,*curr,*dupli;

void create();

void main()
{
    int n,i;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        create();
    }
    printf("the linked list is \n");
    temp=start;
    while(temp!=NULL)
    {
        printf("%d \n",temp->data);
        temp=temp->next;
    }
    temp=start;
    while(temp->next!=NULL)
    {
        curr=temp;
        while(curr->next!=NULL)
        {
            if(temp->data==curr->next->data)
            {
                dupli=temp->next;
                temp->next=temp->next->next;
                free(dupli);
                curr=curr->next;
            }
            else
            {
                curr=curr->next;
            }
        }
        temp=temp->next;
    }
    printf("List is \n");
    temp=start;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }

}

void create()
{
    int item;
    printf("enter the item\n");
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