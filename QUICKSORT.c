#include<stdio.h>
#define MAX 20
void quicksort(int a[], int low, int high);

void main()
{
	int a[MAX];
	int low, high, n;
	printf("Enter the number of numbers to be sorted\n");
	scanf("%d",&n);
	low = 0;
	high = n-1;
	printf("\nEnter the numbers: \n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\nBefore sorting\n");
	for(int i=0;i<n;i++)
		printf("%d",a[i]);
	quicksort(a,low,high);
	printf("\nAfter sorting\n");
	for(int i=0;i<n;i++)
		printf("%d",a[i]);
}

void quicksort(int a[], int low, int high)
{
	int temp,pivot,i,j;
	if(low<high){
		i=low;
		j=high;
		pivot = a[low];
		while(i<j){
			while(a[i]<=pivot && i<high)
				i++;
			while(a[j]>pivot)
				j--;
			if(i<j){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		temp = a[low];
		a[low]=a[j];
		a[j] = temp;
		quicksort(a,low,j-1);
		quicksort(a,j+1,high);
	}
}