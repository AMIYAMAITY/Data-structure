#include<stdio.h>

int compare(int a,int b)
{
return (a <= b)?-1:1;
}

void swap(int *a,int *b)
{
	int t=*b;
	*b=*a;
	*a=t;
}
int pertition(int a[],int start,int end,int (*comp)(int,int))
{
	int k=start-1,i;
	int pivot=a[end];
	for(i=start;i<=end-1;i++)
	{
		if(comp(a[i],pivot) > 0)
		{
			k +=1;
			swap(&a[i],&a[k]);
		}
	}
	swap(&a[k+1],&a[end]);
return k+1;
}

void quickSort(int a[],int start,int end,int (*comp)(int,int))
{
	if(start < end)
	{
		int pPosition=pertition(a,start,end,comp);
		    quickSort(a,start,pPosition-1,comp);
		    quickSort(a,pPosition+1,end,comp);
	}

}
int main()
{
int i;
int n=7;
int a[]={99,55,22,-99,5,0,-65};

quickSort(a,0,n-1,compare);

for(i=0;i<n;i++)
	printf("%d  ",a[i]);

return 0;
}
