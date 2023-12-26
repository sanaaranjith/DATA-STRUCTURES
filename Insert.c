//program to insert nodes into BST
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *lchild,*rchild;
}*root=NULL,*temp,*x,*ptr,*q;

int sum=0;

void main()
{
    int n,i;
    printf("Enter the number of nodes \n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        insert();
    }

}

void insert()
{
    int item;
    printf("Enter the item\n");
    scanf("%d",&item);
    x=(struct node *)malloc(sizeof(struct node));
    x->data=item;
    x->lchild=NULL;
    x->rchild=NULL;
    if(root==NULL)
    {
        root=x;
    }
    else
    {
        ptr=root;
        while(ptr!=NULL)
        {
            q=ptr;
            if(ptr->data>item)
            {
                
            }
        }
    }
}