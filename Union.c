//program to find the intersection and union of two linked list
//some issue with union code
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*x,*y,*start1=NULL,*start2=NULL,*temp1,*temp2;

void create();

void main()
{   
    //creating linkedlist 1
    int n,m,item1,item2,i,j,flag=0;
    printf("Enter the number of elements in linkedlist 1\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the item1\n");
        scanf("%d",&item1);
        x=(struct node *)malloc(sizeof(struct node));
        x->data=item1;
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

    //creating linked list 2
    printf("Enter the number of elements in linkedlist 2\n");
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        printf("Enter the item2\n");
        scanf("%d",&item2);
        y=(struct node *)malloc(sizeof(struct node));
        y->data=item2;
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

   
   //printing first linkedlist
   printf("\nThe first linkedlist is \n");
   temp1=start1;
   while(temp1!=NULL)
   {    
        printf("%d ",temp1->data);
        temp1=temp1->next;
   }


    //printing second linkedlist
   printf("\nThe second linkedlist is \n");
   temp2=start2;
   while(temp2!=NULL)
   {    
        printf("%d ",temp2->data);
        temp2=temp2->next;
   }


   printf("\nINTERSECTION\n");
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
    

    printf("\nUNION\n");
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
            if(temp2->data==temp1->data)
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
