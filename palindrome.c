//program to check whether the linked list is palindrome or not

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*x,*temp,*temp2,*start=NULL,*y,*start2=NULL;

void create();

void main()
{
    int n,i,flag=0;;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        create();
    }

    //displaying the linked list 
    temp=start;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }

    //checking if the linkled list is palindrome or not 
    temp=start;
    while(temp!=NULL)
    {
        y=(struct node *)malloc(sizeof(struct node));
        y->data=temp->data;
        y->next=NULL;
        if(start2!=NULL)
        {
            start2=x;
        }
        else
        {
            y->next=start2;
            start2=x;
        }
        temp=temp->next;
    }
    flag=1;
    temp=start;
    temp2=start2;
    while(temp!=NULL && temp2!=NULL)
    {
        if(temp->data != temp2->data)
        {
            flag=0;
            break;
        }
        temp=temp->next;
        temp2=temp2->next;
    }
    if(flag==1)
    {
        printf("Palindrome\n");
    }
    else
    {
        printf("Not palindrome\n");
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