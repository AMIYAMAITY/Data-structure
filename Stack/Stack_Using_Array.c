#include<stdio.h>
#define size 5
int stk[size];
int top=0;

int isFull()
{
if(size==top)
return 1;
else
return 0;
}

int isEmpty()
{
if(top<0)
return 1;
else
return 0;
}

void push(int i)
{
if(isFull())
{
printf("\nStack is full,  not possible to insert right now:\n");
}
else
{
if(isEmpty())
top=0;

stk[top]=i;
top++;
}
}

void pop()
{
printf("\npop value:\n");

if(isEmpty())
printf("\nPop operation not possible right now\n");
else
{
if(isFull())
top--;


printf("%d",stk[top]);
stk[top]=0;
top--;
}
}

void display()
{
int i;
printf("\nData are:\n");
for(i=0;i<size;i++)
printf("%d  ",stk[i]);
printf("\n");
}


int main()
{
push(5);
push(3);
push(6);
push(4);
push(676);
push(500);
push(230);
pop();
pop();
pop();
pop();
pop();
pop();
pop();
push(100);
push(20);
display();
return 0;
}
