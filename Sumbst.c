//program to find the sum of all nodes in bst

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lchild,*rchild;
}*x,*ptr,*q,*root=NULL;

void create();
int sum(struct node *ptr);
void inorder(struct node *ptr);

void main()
{
    int ch,a=0;
    while(1)
    {
        printf("\nMENU\n1.Create\n2.Sum\n3.Inorder traversal\n");
        printf("\nEnter the choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            create();
            break;

            case 2:
            a=sum(root);
            printf("Sum : %d \n",a);
            break;

            case 3:
            inorder(root);
            break;

            default:
            printf("WRONG CHOICE..!!!");
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

void inorder(struct node *ptr)
{
    if(ptr!=NULL)
    {
        inorder(ptr->lchild);
        printf("%d ",ptr->data);
        inorder(ptr->rchild);
    }
}

int sum(struct node *ptr)
{
    if(ptr==NULL)
        return 0;
    else
    {
        return ptr->data+sum(ptr->lchild)+sum(ptr->rchild);
    }
}