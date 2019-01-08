#include<stdio.h>
#define N 4

int main()
{
int array[N][N],i,j;
for(i=0;i<N;i++)
   for(j=0;j<N;j++)
	array[i][j]=1+(i*j);
printf("\nAssigned Data:\n");
for(i=0;i<N;i++)
 {
   for(j=0;j<N;j++)
	printf("%d ",array[i][j]);
	printf("\n");
 }
return 0;
}
