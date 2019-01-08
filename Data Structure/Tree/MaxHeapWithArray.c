#include<stdio.h>
#include <stdlib.h>
int *array;
int p=0;

void swap(int *a1,int *a2)
{
int temp;
temp=*a1;
*a1=*a2;
*a2=temp;
}

void delete()
{
int lv,maxI,r=0,lc=1,rc=2;
lv=*(array+(p-1));
*array=lv;
p=p-1;

while(*(array+r) < *(array+lc) || *(array+r) < *(array+rc))
{
	if(*(array+rc) > *(array+lc))
	maxI=rc;
	else
	maxI=lc;
	swap((array+r),(array+maxI));
	r=maxI;
	lc=(2*r+1);
	rc=(2*r+2);
}

}

void insert(int n)
{
int k=p,index;
array[k]=n;
while(*(array+abs((k-1)/2))< *(array+k))
{
index=abs((k-1)/2);
swap((array+index),(array+k));
k=index;
}
p++;
}

void display()
{
printf("\n");
int i;
for(i=0;i<p;i++)
{
printf("[%d]-",*(array+i));
}
printf("\n");
}



int main()
{
array=(int*)calloc(9,sizeof(int*));
if(array==NULL)
{
printf("\n Insert not possible\n");
}
else
{
insert(15);
insert(12);
insert(11);
insert(9);
insert(10);
insert(8);
insert(20);
insert(13);
display();
delete();
display();
free(array);
}
return 0;
}
