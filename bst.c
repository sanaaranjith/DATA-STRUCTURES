//program to implement binary search tree
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lchild,*rchild;
}*root=NULL,*temp,*x,*q,*ptr;

void create();
void preorder(struct node *);
void postorder(struct node *);
void inorder(struct node *);
void search();

void main()
{
    int ch,n;
    while(1)
    {
        printf("\nMENU\n1.Create\n2.Pre-order traversal\n3.Post-order traversal\n4.In-order traversal\n5.Search\n");
        printf("\nEnter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            create();
            break;

            case 2:
            preorder(root);
            break;

            case 3:
            postorder(root);
            break;

            case 4:
            inorder(root);
            break;

            case 5:
            search();
            break;

            default:
            printf("WRONG CHOICE!!");
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

void preorder(struct node *ptr)
{
    if(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}

void postorder(struct node *ptr)
{
    if(ptr!=NULL)
    {
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        printf("%d ",ptr->data);
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

void search()
{
    int key,flag=0;
    printf("Enter the element to be searched\n");
    scanf("%d",&key);
    if(root==NULL)
    {
        printf("Search not possible bcus empty tree\n");
    }
    else
    {
        ptr=root; //important
        while(ptr!=NULL)
        {
            if(ptr->data==key)
            {
                flag=1;
                break;
            }
            else if(ptr->data>key)
            {
                ptr=ptr->lchild;
            }
            else if(ptr->data<key)
            {
                ptr=ptr->rchild;
            }
        }
        if(flag==1)
        {
            printf("Element is found\n");
        }
        else
        {
            printf("Element not found\n");
        }
    }
}