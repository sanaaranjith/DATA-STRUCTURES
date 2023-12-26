//program to reverse the first n nodes of a linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*x,*temp,*start=NULL,*rev,*curr,*prev;

void create();
void reverse(struct node *start, int k);

void main()
{
    int n,i,k,m;
    printf("Enter the number of nodes to be created\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        create();
    }
    printf("Enter the number of nodes to reverse\n");
    scanf("%d",&k);
    reverse(start,k);

    printf("Enter the number of nodes to append\n");
    scanf("%d",&m);
    int count=0;
    temp=start;
    curr=start;
    //traverse the ll to reach the mth node
    while(count<m && curr!=NULL)
    {
        curr=curr->next;
        count++;
    }
    //traverse to the end of the ll
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    
    //append last m nodes to the start of the ll 
    temp->next=start;
    start=curr->next;
    curr->next=NULL;

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

void reverse(struct node *start, int k)
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
    curr=start; //important
    while(curr!=NULL)
    {
        rev=curr->next;
        curr->next=prev;
        prev=curr;
        curr=rev;
    }
     
    start=prev;
    curr=start;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=jpnode;
    start=prev;
    printf("sup");
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

