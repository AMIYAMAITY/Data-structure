#include<stdio.h>

int compare(int a,int b)
{
return (a > b)?-1:1;
}
void insertionSort(int a[],int n,int (*comp)(int,int))
{
int i,j,k;
	if(n<2)
	return;

	for(i=1;i<n;i++)
	{
		j=i-1;
		k=a[i];
		
		while(j >= 0 && comp(a[j],k) > 0)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=k;
	}
}
int main()
{
int a[]={5,88,-99,99,0};
int i;
int n=5;
insertionSort(a,n,compare);
	for(i=0;i<n;i++)
	printf("%d  ",a[i]);
return 0;
}
