#include<stdio.h>
#define N 20
int main()
{
float array[N];
int i;
for(i=0;i<N;i++)
array[i]=i*0.7;

printf("\nAssigned data:\n");
for(i=0;i<N;i++)
printf("%.2f ",array[i]);
return 0;
}
