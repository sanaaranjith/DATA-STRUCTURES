//program to find odd and even nodes in the singly linked list
//some issue with even and odd code
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*x,*temp,*start=NULL;

void create();

void main()
{
    int n,i;
    //creating the linked list
    printf("Enter the number of nodes to be created\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        create();
    }
    //printing the linked list
    printf("The linked list is \n");
    temp=start;
    while(temp!=NULL)
    {
        printf("%d \n",temp->data);
        temp=temp->next;
    }
    printf("The even numbers in the linked list are \n");
    temp=start;
    while(temp!=NULL)
    {
          if(temp->data %  2 == 0)
            {
                printf("%d ",temp->data);
            }
            temp=temp->next; //give it to outside the if loop
    }
    printf("The odd numbers in the linked list are \n");
    temp=start;
    while(temp!=NULL)
    {
       if(temp->data % 2 != 0)
            {
                printf("%d ",temp->data);
                
            }
            temp=temp->next; //give it outside the if loop
    }

}


void create()
{
    int item;
    printf("Enter the element to be entered \n");
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