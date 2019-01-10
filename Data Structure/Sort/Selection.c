#include<stdio.h>

int compare(int a,int b)
{
return (a>b)?-1:1;
}

void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
void selectionSort(int a[],int n,int (*comp)(int,int))
{
	int i,j,k;
	
	for(i=0;i<n-1;i++)
	{
		k=i;
		
		for(j=i+1;j<n;j++)
		{
			if(comp(a[k],a[j]) > 0)
				k=j;
		}
	swap(&a[i],&a[k]);
	}
}


int main()
{
int a[]={33,99,0,-88,1};
int i;
int n=5;
selectionSort(a,n,compare);
for(i=0;i<n;i++)
	printf("%d  ",a[i]);
return 0;
}
