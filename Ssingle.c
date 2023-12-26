//program to implement singly linked list 
#include <stdio.h>
#include <stdlib.h>  //required for malloc()

void create();
void insert_beg();
void insert_end();
void insert_pos();
void delete_beg();
void delete_end();
void delete_pos();

struct node
{
    int data;
    struct node *next;
}*temp,*start=NULL,*x,*prev;


void main()
{
    int ch,n,i,count=0;
    printf("\nMENU\n1.Create\n2.Count\n3.Insert at beginning\n4.Insert at end\n5.Inser at position\n6.Delete from beginning\n7.Delete from end\n8.Delete from position\n9.Display\n");
    while(1)
    {
       
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
            break;

            case 2:
            temp=start;
            while(temp!=NULL)
            {
                count++;
                temp=temp->next;
            }
            printf("Number of nodes: %d\n",count);
            break;

            case 3:
            insert_beg();
            break;

            case 4:
            insert_end();
            break;

            case 5:
            insert_pos();
            break;

            case 6:
            delete_beg();
            break;

            case 7:
            delete_end();
            break;

            case 8:
            delete_pos();
            break;

            case 9:
            temp=start;
            while(temp!=NULL)
            {
                printf("%d\n",temp->data);
                temp=temp->next;
            }
            break;

            default:
            printf("WRONG CHOICE !!");

        }
    }
}

void create()
{
    int item;
    printf("Enter the item");
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

void insert_beg()
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
        x->next=start;
        start=x;
    }
}

void insert_end()
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
        temp->next=x; //insert from end condition
        temp=x;
    }
}

void insert_pos()
{
    int item,pos,k;
    printf("Enter the item");
    scanf("%d",&item);
    printf("Enter the position\n");
    scanf("%d",&pos);
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
        temp=start;
        prev=NULL;
        for(k=0;k<pos-1;k++)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=x;
        x->next=temp;

    }
}

void delete_beg()
{
    if(start==NULL)
    {
        printf("List is empty\n");
    }
    else                                 //else if not important
    {
        temp=start;
        start=temp->next;
        printf("deleted element : %d \n",temp->data);
        free(temp);
    }
}

void delete_end()
{
    if(start==NULL)
    {
        printf("List is empty\n");
    }
    else if(start->next!=NULL)
    {
        temp=start;
        printf("Deleted element is : %d ",temp->data);
        free(temp);
        start=NULL;
    }
    {
        while(temp!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
          prev->next=NULL;
        printf("Deleted element : %d ",temp->data);
        free(temp);
      
    }
}

void delete_pos()
{
    
    if(start==NULL)
    {
        printf("List is empty\n");
    }
    else if (start->next==NULL)
    {
        temp=start;
        printf("Deleted elements is %d ",temp->data);
        start==NULL;
        free(temp);
    }
    else 
    {
        int pos,k;
        printf("Enter the position\n");
        scanf("%d",&pos);
        temp=start;   //important 
        for(k=0;k<pos-1;k++)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        printf("Deleted element is :%d \n",temp->data);
        free(temp);
    }
}