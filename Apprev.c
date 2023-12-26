//program to reverse the first n nodes of a linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*x,*temp,*start=NULL,*rev,*curr,*prev;

void create();
void reverse(struct node *temp, int k);
//void append(struct node *temp, int k);

void main()
{
    int n,i,k;
    printf("Enter the number of nodes to be created\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        create();
    }
    printf("Enter the number of nodes to reverse\n");
    scanf("%d",&k);
    reverse(struct node *temp,int k);
    //printf("Enter the number of nodes to append\n");
    //append(struct node *temp ,int k);
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
        temp=x;
    }
    else
    {
        temp->next=x;
        temp=x;
    }
}

void reverse(struct node *temp, int k)
{
    temp=start;
    int count=1;
    while(count<k)
    {
        temp=temp->next;
        count++;
    }
    struct node *jpnode=temp->next;
    temp->next=NULL;
    prev=NULL;
    curr=temp;
    while(curr!=NULL)
    {
        rev=curr->next;
        curr->next=prev;
        prev=curr;
        curr=rev;
    }
    start=prev;
    curr=start;
    while(curr!=NULL)
    {
        curr=curr->next;
    }
    curr->next=jpnode;
    start=prev;

    if(start==NULL) //display the nodes
    {
        printf("List is empty\n");   
    }
    else
    {
        temp=start;
        printf("The linked list is \n");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

