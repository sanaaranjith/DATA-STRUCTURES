//program to get the sum of all nodes
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*start=NULL,*x,*temp;

void create();

void main()
{
    int n,i,sum=0;
    printf("\nEnter the number of nodes \n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        create();
    }
    printf("\nThe linked list \n");
    temp=start;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    temp=start;
    while(temp!=NULL)
    {
        sum=sum+temp->data;
        temp=temp->next;
    }
    printf("\nThe sum is %d\n",sum);
}

void create()
{
    int item;
    printf("\nEnter the item\n");
    scanf("%d",&item);
    x=(struct node*)malloc(sizeof(struct node));
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
