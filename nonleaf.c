//program to display non-leaf nodes

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lchild,*rchild;
}*root=NULL,*q,*ptr,*x;

void nonleaf(struct node *ptr);
void create();

void main()
{
    int ch,n,i;
    printf("Enter the number of nodes to be created\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        create();
    }
    printf("The non-leaf nodes are \n");
    nonleaf(root);
}

void create()
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
                ptr=ptr->lchild;
            }
            else if(ptr->data<item)
            {
                ptr=ptr->rchild;
            }
        }
        if(q->data>item)
        {
            q->lchild=x;
        }
        else if(q->data<item)
        {
            q->rchild=x;
        }
    }
}

void nonleaf(struct node *ptr)
{
    if(ptr!=NULL)
    {
        if((ptr->lchild != NULL)||(ptr->rchild != NULL))
        {
            printf("%d ",ptr->data);
        }
        nonleaf(ptr->lchild);
        nonleaf(ptr->rchild);
    }
}