//program to implement doubly linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next,*prev;
}*x,*temp,*start=NULL,*ptr;

void create();
void insert_beg();
void insert_end();
void insert_pos();
void delete_beg();
void delete_end();
void delete_pos();

void main()
{
    int ch,i,n;
    while(1)
    {
        printf("\nMENU\n1.Create\n2.Display\n3.Insert from beginning\n4.Insert from end\n5.Insert to position\n6.Delete from beginning\n7.Delete from end\n8.Delete from position\n");
        printf("Enter the choice\n");
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
                printf("%d ",temp->data);
                temp=temp->next;
            }
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

            default :
            printf("WRONG CHOICE !!");
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

void insert_beg()
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
        x->next=start;
        start->prev=x;
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
    x->prev=NULL;
    if(start==NULL)
    {
        start=x;
        temp=x;
    }
    else
    {
        temp=start;
        while(temp->next!=NULL) //temp!=NULL not correct 
        {
            temp=temp->next;
        }
        temp->next=x;
        x->prev=temp;
        temp=x;
    }
}

void insert_pos()
{
    int item,pos,k;
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
        printf("Enter the position\n");
        scanf("%d",&pos);
        temp=start;
        for(k=0;k<pos-1;k++)
        {
            ptr=temp;
            temp=temp->next;
        }
        /*x->prev=temp;
          x->next=temp->next;
          temp->next->prev=x;
          temp->next=x*/
        x->prev=ptr;  
        x->next=temp; 
        temp->prev=x;
        ptr->next=x;
    }
}

void delete_beg()
{
    if(start==NULL)
    {
        printf("List is empty\n");
    }
    else                        //else if is not imp in the case of deletion from beginning
    {
        temp=start;
        start=temp->next;
        start->prev=NULL;
        printf("Deleted element is %d\n",temp->data);
        free(temp);
    }
}

void delete_end()
{
    if(start==NULL)
    {
        printf("List is empty\n");
    }
    else if(start->next==NULL)
    {
        temp=start;
        printf("Deleted element : %d\n",temp->data);
        start=NULL;
        free(temp);
    }
    else
    {
        temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        
        printf("Deleted element is : %d \n",temp->data);
        ptr->next=NULL;
        free(temp);
    }
}

void delete_pos()
{
    int k,pos;
    if(start==NULL)
    {
        printf("List is empty\n");
    }
    else if(start->next==NULL)
    {
        temp=start;
        printf("Deleted element is %d\n",temp->data);
        start=NULL;
        free(temp);
    }
    else
    {
        temp=start;
        printf("Enter the position\n");
        scanf("%d",&pos);
        for(k=0;k<pos-1;k++)
        {
            ptr=temp;
            temp=temp->next;
        }
        ptr->next=temp->next;
        temp->next->prev=ptr;
        printf("Deleted elements is : %d \n",temp->data);
        free(temp);
    }
}