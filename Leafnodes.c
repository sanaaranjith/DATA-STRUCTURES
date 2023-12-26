//program to print the leaf nodes

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lchild,*rchild;
}*x,*root=NULL,*ptr,*q;

void leafnode(struct node *ptr); //pass the root node
void create();

void main()
{
    int n,i;
    printf("Enter the number of nodes to insert\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        create();
    }
    printf("Leaf nodes\n");
    leafnode(root);
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
            while(q!=NULL)
            {
                if(ptr->data>item)
                    ptr=ptr->lchild;
                else if(ptr->data<item)
                    ptr=ptr->rchild;
            }
            if(q->lchild>item)
                q->lchild=x;
            else(q->rchild<item)
                q->rchild=x;
        }
    }
}


void leafnode(struct node *ptr)
{
    if(ptr!=NULL)
    {
        if(ptr->lchild==NULL)&&(ptr->rchild==NULL) //condition for leaf nodes
        {
            printf("%d ",ptr->data);
        }
        leafnode(p->lchild);
        leafnode(p->rchild);
    }
}