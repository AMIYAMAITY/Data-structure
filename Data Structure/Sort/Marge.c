#include<stdio.h>
#include<stdlib.h>

int compare(int a,int b)
{
return (a<b)?1:-1;
}

void marge(int array[],int left[],int lN,int right[],int rN,int (*fun)(int,int))
{
int i,j,k;
i=j=k=0;
	while(i<lN && j<rN)
	{
		if(fun(left[i],right[j]) > 0)
		array[k++]=left[i++];
		else
		array[k++]=right[j++];
	}
	while(i<lN)
		array[k++]=left[i++];
	while(j<rN)
		array[k++]=right[j++];
}


void margeSort(int a[],int n,int (*fun)(int,int))
{
int mid,i;
int *left,*right;

if(n<2)
return;

mid=n/2;
left=(int *)malloc(mid*sizeof(int));
right=(int *)malloc((n-mid)*sizeof(int));

for(i=0;i<mid;i++)
	left[i]=a[i];
for(i=mid;i<n;i++)
	right[i-mid]=a[i];

margeSort(left,mid,fun);
margeSort(right,n-mid,fun);
marge(a,left,mid,right,n-mid,fun);
free(left);
free(right);
}

int main()
{
int i;
int a[]={3,6,-99,-66,1,0};
margeSort(a,6,compare);
for(i=0;i<6;i++)
	printf("%d  ",a[i]);
return 0;
}
