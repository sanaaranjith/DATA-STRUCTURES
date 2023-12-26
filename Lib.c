//program to enter the library details
//delete the largest rate book code left (printing the node)
#include<stdio.h>
#include<stdlib.h> //to use malloc()
#include<string.h> //to use strdup() function 

                                                                                         /*struct lib
                                                                                          {   char bookname[50],author[50];
                                                                                                int price;
                                                                                                struct lib *link;
                                                                                            }
                                                                                            *ptr,*head,*new,*temp,*prev,*curr;*/
struct node
{
    int bkno,bkr;
    char *bkname,*bkau; //make sure to use * to declare each value of char
    struct node *next;
}*x,*temp,*start=NULL,*prev; 


void create();
void delete();

void main()
{
    int n,i,large;
    char name[20],au[20];
    printf("Enter the number of nodes\n");
    scanf("%d",&n);

    //creating the nodes
    for(i=0;i<n;i++)
    {
        create();
    }

    //displaying the created node
    printf("The linked list is\n");
    temp=start;
    while(temp!=NULL)
    {
        printf("Book number is %d \n",temp->bkno);
        printf("Book number is %d \n",temp->bkr);
        printf("Book name is %s \n",temp->bkname); //make sure to use %s
        printf("Book author is %s \n",temp->bkau);
        temp=temp->next;
    }

    //finding the book with highest rate
    temp=start;
    large=temp->bkr;
    //if required find a way to store book name and book author to character variables to print it 
    while(temp!=NULL)
    {
        if(temp->bkr>large)
        {
            large=temp->bkr;
        }
        temp=temp->next;
    }
    printf("The book with highest rate is %d ",large);

    //to delete the book with highest rate
    if(start==NULL)
    {
        printf("book cannot be removed as there are no books\n");
    }
    else if(temp->bkr==large)
    {
        temp=start;
        printf("Deleted book is %d ",temp->bkr);
        start=NULL;
        free(temp);
    }
    else
    {
        prev=start;
        temp=start;
        while(temp->bkr!=large && temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        if(temp->bkr!=large)
        {
            printf("Book cannot be deleted ");
        }
        else
        {
            prev->next=temp->next;
            printf("deleted  node is %d ",temp->bkr);
            free(temp);
        }
    }
}


void create()
{
    /*new=(struct lib*)malloc(sizeof(struct lib));
    printf("Enter the bookname :");
    scanf("%s",&new->bookname);
    printf("Enter the authorname :");
    scanf("%s",&new->author);
    printf("Enter the price of book :");
    scanf("%d",&new->price);*/
    int a,d;
    char b[20],c[20];
    printf("Enter the book number\n");
    scanf("%d",&a);
    printf("Enter the book rate\n");
    scanf("%d",&d);
    printf("Enter then book name\n");
    scanf("%s",b);                   //consider it as strings and use %s,name 
    printf("Enter the book author\n");
    scanf("%s",c);
    x=(struct node *)malloc(sizeof(struct node));
    x->bkno=a;
    x->bkr=d;
    x->bkname=strdup(b);
    x->bkau=strdup(c);
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

