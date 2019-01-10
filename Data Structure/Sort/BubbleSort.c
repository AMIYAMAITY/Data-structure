#include<stdio.h>

int compare(int i,int j)
{
	return (i>j?1:-1);
}

void bubbleSort(int array[],int n,int (*fun)(int a,int b))
{
int i,j,t;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(fun(array[j],array[j+1])>0)
			{
				t=array[j];
				array[j]=array[j+1];
				array[j+1]=t;
			}
		}
	}

}

int main()
{
int i;
int n=6;
int array[]={6,4,9,-3,66,0};

int (*p)(int,int)=&compare;

bubbleSort(array,n,p);

for(i=0;i<n;i++)
{
printf("%d  ",array[i]);
}
return 0;
}
