

#include<stdio.h>
#include<stdlib.h>
struct poly
{
   int coeff;
   int expo;
   struct poly *ptr;
};
int main()
{
    typedef struct poly POLY;
    int co,ex,i,m,n;
    POLY *start1=NULL,*start2=NULL,*start3=NULL,*temp,*p;
    printf("\nEnter the number of terms in first polynomial: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
          temp=(POLY*)malloc(sizeof(POLY));
          printf("\nEnter the coefficient and exponent: ");
          scanf("%d%d",&co,&ex);
          temp->coeff=co;
          temp->expo=ex;
          temp->ptr=NULL;
          if(start1==NULL)
          {
            start1=temp;
          }
          else
          {
             p=start1;
             while(p->ptr!=NULL)
             {
                 p=p->ptr;
             }
             p->ptr=temp;
          }
    }
    printf("\nFirst polynomial is: ");
    for(p=start1;p!=NULL;p=p->ptr)
    {
        printf("%dX^%d",p->coeff,p->expo);
        if(p->ptr!=NULL)
        printf("+");
    }
    printf("\nEnter the number of terms in second polynomial: ");
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
          temp=(POLY*)malloc(sizeof(POLY));
          printf("\nEnter the coefficient and exponent: ");
          scanf("%d%d",&co,&ex);
          temp->coeff=co;
          temp->expo=ex;
          temp->ptr=NULL;
          if(start2==NULL)
          {
            start2=temp;
          }
          else
          {
            p=start2;
            while(p->ptr!=NULL)
            {
                p=p->ptr;
            }
            p->ptr=temp;
          }
    }
    printf("\nSecond polynomial is: ");
    for(p=start2;p!=NULL;p=p->ptr)
    {
          printf("%dX^%d",p->coeff,p->expo);
          if(p->ptr!=NULL)
          printf("+");
    }
    while((start1!=NULL)&&(start2!=NULL))
    {
      if(start1->expo==start2->expo)
      {
         temp=(POLY*)malloc(sizeof(POLY));
         temp->coeff=start1->coeff+start2->coeff;
         temp->expo=start1->expo;
         temp->ptr=NULL;
         start1=start1->ptr;
         start2=start2->ptr;
      }
      else if(start1->expo>start2->expo)
      {
         temp=(POLY*)malloc(sizeof(POLY));
         temp->coeff=start1->coeff;
         temp->expo=start1->expo;
         temp->ptr=NULL;
         start1=start1->ptr;
      }
      else
      {
         temp=(POLY*)malloc(sizeof(POLY));
         temp->coeff=start2->coeff;
         temp->expo=start2->expo;
         temp->ptr=NULL;
         start2=start2->ptr;
      }
      if(start3==NULL)
      {
        start3=temp;
      }
      else
      {
         p=start3;
         while(p->ptr!=NULL)
         {
             p=p->ptr;
         }
         p->ptr=temp;
      }
   }
   while(start1!=NULL)
   {
      temp=(POLY*)malloc(sizeof(POLY));
      temp->coeff=start1->coeff;
      temp->expo=start1->expo;
      temp->ptr=NULL;
      start1=start1->ptr;

      if(start3==NULL)
      {
        start3=temp;
      }
      else
      {
          p=start3;
          while(p->ptr!=NULL)
          {
              p=p->ptr;
          }
          p->ptr=temp;
      }
   }
   while(start2!=NULL)
   {
       temp=(POLY*)malloc(sizeof(POLY));
       temp->coeff=start2->coeff;
       temp->expo=start2->expo;
       temp->ptr=NULL;
       start2=start2->ptr;
       if(start3==NULL)
       {
            start3=temp;
       }
       else
       {
           p=start3;
           while(p->ptr!=NULL)
           {
                p=p->ptr;
           }
           p->ptr=temp;
           }
    }
    printf("\nResultant polynomial is: ");
    for(p=start3;p!=NULL;p=p->ptr)
    {
       printf("%dX^%d",p->coeff,p->expo);
       if(p->ptr!=NULL)
	   printf("+");
   }
}




