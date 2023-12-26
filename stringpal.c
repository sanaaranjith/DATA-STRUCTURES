//program to check whether a string is palindrome or not

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node 
{
    char data;
    struct node *next;
}*x,*temp,*start=NULL;

boolean isPalindrome(node *start);
boolean result(string str);

void main()
{
    char str[100];
    int i;
    printf("Enter the string\n");
    scanf("%s",str);

    int len=strlen(str);
    start=NULL;
    for(i=0;i<len;i++)
    {
        create(start,str[i]);
    }
}

void create()
{

}


boolean ispalindrome(struct node *start)
{
    String str="";
    while(start!=NULL)
    {
        str.append(start->data);
        start=start->next;
    }
    return ispalindrome(str);
}

boolean result(String str)
{
    int length=str.length();
    for(int i=0;i<length/2;i++)
    {
        if(str[i] != str[length-i-1])
        {
            return false;
        }
    }
    return true;
}