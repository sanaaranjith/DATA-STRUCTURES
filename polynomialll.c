//program to implement polynomial addition using linked list

#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int coeff, expo;
    struct node *next;
};

void main()
{
    typedef struct node poly;
    poly *start1=NULL,*start2=NULL,*start3=NULL,*temp,*p;
    int i,n,co,ex,m;

    //polynomial 1 creation
    printf("Enter the number of nodes \n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        temp = (poly *)malloc(sizeof(poly));
        printf("Coefficient\n");
        scanf("%d",&temp->coeff);
        printf("Exponent\n");
        scanf("%d",&temp->expo);
        temp->next=NULL;
        if(start1==NULL)
        {
            start1=temp;
        }
        else
        {
            p=start1;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=temp;
        }
    }

    //displaying polynomial 1
    printf("The polynomial 1 is\n");
    if(start1==NULL)
    {
        printf("Polynomial doesn't exist\n");
    }
    else
    {
        p=start1;
        while(p!=NULL)
        {
            printf("%d x^ %d+",p->coeff,p->expo);
            p=p->next;
        }
        printf("0");
    }

    //polynomial 2 creation
    printf("\nEnter the number of nodes \n");
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        temp = (poly *)malloc(sizeof(struct node));
        printf("Coefficient\n");
        scanf("%d",&temp->coeff);
        printf("Exponent\n");
        scanf("%d",&temp->expo);
        temp->next=NULL;
        if(start2==NULL)
        {
            start2=temp;
        }
        else
        {
            p=start2;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=temp;
        }
    }

    //displaying polynomial 2
    printf("The polynomial 2 is\n");
    if(start2==NULL)
    {
        printf("Polynomial doesn't exist\n");
    }
    else
    {
        p=start2;
        while(p!=NULL)
        {
            printf("%dx^ %d+",p->coeff,p->expo);
            p=p->next;
        }
        printf("0");
    }

    while(start1!=NULL && start2!=NULL)
    {
        if(start1->expo == start2->expo)
        {
            temp=(poly *)malloc(sizeof(poly));
            temp->coeff = start1->coeff + start2->coeff;
            temp->expo=start1->expo;
            temp->next=NULL;
            start1=start1->next;
            start2=start2->next;
        }
        else if(start1->expo > start2->expo)
        {
            temp=(poly *)malloc(sizeof(poly));
            temp->coeff=start1->coeff;
            temp->expo=start1->expo;
            temp->next=NULL;
            start1=start1->next;
        }
        else
        {
            temp=(poly *)malloc(sizeof(poly));
            temp->coeff=start2->coeff;
            temp->expo=start2->expo;
            temp->next=NULL;
            start2=start2->next;
        }

        //appending all these nodes
        if(start3==NULL)
        {
            start3=temp;
        }
        else
        {
            p=start3;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=temp;
        }
    }
    

    //leftover nodes in polynomial 1
    while(start1!=NULL)
    {
        temp=(poly *)malloc(sizeof(poly));
        temp->coeff=start1->coeff;
        temp->expo=start1->expo;
        temp->next=NULL;
        start1=start1->next;

        if(start3==NULL)
        {
            start3=temp;
        }
        else
        {
            p=start3;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=temp;
        }
    }

    while(start2!=NULL)
    {
        temp=(poly *)malloc(sizeof(poly));
        temp->coeff=start2->coeff;
        temp->expo=start2->expo;
        temp->next=NULL;
        start2=start2->next;

        if(start3==NULL)
        {
            start3=temp;
        }
        else
        {
            p=start3;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=temp;
        }
    }

    printf("Resultant polynomial is \n");
    p=start3;
    while(p->next != NULL)
    {
        printf("%dx^%d+",p->coeff,p->expo);
        p=p->next;
        printf("0");
    }
}
