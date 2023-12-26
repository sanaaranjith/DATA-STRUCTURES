#include<stdio.h>
#include<stdlib.h>
void create();
struct lib
{   char bookname[50],author[50];
    int price;
    struct lib *link;
}
*ptr,*head,*new,*temp,*prev,*curr;
void display()
{
    ptr=head;
    if(head==NULL)
    {
        printf("no");
    }
    else
    {
        printf("\nbookname\tauthorname\tprice\n");
        while(ptr!=NULL)
        {
            printf("%s\t%s\t%d\n",ptr->bookname,ptr->author,ptr->price);
            ptr=ptr->link;
        }
        printf("\n");
    }
}

void deltemax()
{
   int max=0;
   int x;
   ptr=head;
   max=head->price;//ptr->price
  while(ptr!=NULL)
 { 
    if((x=ptr->price)>max)
    {
        max=ptr->price;
        break;
    }
    ptr=ptr->link;
 }
//to del book having largest price
 printf("deleted book is:");
 if(head==NULL)
 {
 printf("del not possible");
 }
 else if(head->price==max)
 {
 temp=head;
 head=NULL;
 printf("deleted  node is %d ",temp->price);
 free(temp);
 }
 else
 {
 prev=head;
 curr=head;
 while(curr->price!=max && curr->link!=NULL)
 {
 prev=curr;
 curr=curr->link;
 }
 if(curr->price!=max)
 {
 printf("del not possible");
 }
 else
 {
 prev->link=curr->link;
 printf("deleted  node is %d ",curr->price);
 free(curr);
 }
 }
}


int main()
{
int n,i;
printf("Enter no of nodes:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
create();
}
display();
deltemax();
display();

return 0;
}
//to create lib linked list
void create()
{
new=(struct lib*)malloc(sizeof(struct lib));
printf("Enter the bookname :");
scanf("%s",&new->bookname);
printf("Enter the authorname :");
scanf("%s",&new->author);
printf("Enter the price of book :");
scanf("%d",&new->price);
new->link =NULL;
if(head==NULL)
{
head=new;
ptr=new;
}
else
{
ptr->link=new;
ptr=new;
}

}

