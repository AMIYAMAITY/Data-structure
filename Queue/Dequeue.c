#include<stdio.h>
#include<stdlib.h>
#define X 7
int dequeue[X];
int f=-1;
int r=-1;
int isEmpty();
int isFull();
void display();
int insertFront(int);
int deleteFront();
int insertRear(int);
int deleteRear();


int main()
{
int data,n;
while(1)
{
printf("\n1. Display\n");
printf("\n2. FrontInsert\n");
printf("\n3. RearInsert\n");
printf("\n4. FrontDeleted\n");
printf("\n5. RearDeleted\n");
printf("\n9. Exit\n");
printf("\n_______________________________________________\n");
scanf("%d",&n);
switch(n)
{
	case 1:
	{
	display();
	break;
	}
	case 2:
	{
	printf("\nEnter data for Front Insert:\n");
	scanf("%d",&data);
	insertFront(data);
	break;
	}
	case 3:
	{
	printf("\nEnter data for Rear Insert:\n");
	scanf("%d",&data);
	insertRear(data);
	break;
	}
	case 4:
	{
	deleteFront();
	break;
	}
	case 5:
	{
	deleteRear();
	break;
	}
	case 9:
	{
	exit(1);
	break;
	}
	default:
	{
	printf("\nInvalid Choice\n");
	break;
	}
}
}
return 0;
}

int isFull()
{
if((f==r+1)|| (f==0 && r==X-1))
return 1;
else
return 0;
}


int isEmpty()
{
if(f==-1 || r==-1)
return 1;
else
return 0;
}

void display()
{
int i;
for(i=0;i<X;i++)
{
printf("%d->",dequeue[i]);
}
printf("\nf=%d\nr=%d\n",f,r);
}



int insertFront(int data)
{
if(isFull())
printf("\nQueue is full\n");
else
{
if(isEmpty())
{
f=f+1;
r=r+1;
dequeue[f]=data;
printf("\nQueue Front Inserted data\n");
}
else if(f==0)
f=X-1;
else
f=f-1;
dequeue[f]=data;
printf("\nQueue Front Inserted data\n");
}

}

int insertRear(int data)
{
if(isFull())
printf("\nQueue is full\n");
else
{
if(isEmpty())
{
f=f+1;
r=r+1;
dequeue[r]=data;
printf("\nQueue Rear data Inserted \n");
}
else if(r==X-1)
r=0;
else
r=r+1;
dequeue[r]=data;
printf("\nQueue Rear data Inserted \n");

}
}


int deleteFront()
{
if(isEmpty())
printf("\nQueue is Empty\n");
dequeue[f]=0;
printf("\nQueue Front data Deleted \n");
if(f==r)
{
f=-1;
r=-1;
}
else
if(f==X-1)
f=0;
else
f=f+1;
}

int deleteRear()
{
if(isEmpty())
printf("\nQueue is Empty\n");
dequeue[r]=0;
printf("\nQueue Rear data Deleted \n");
if(f==r)
{
f=-1;
r=-1;
}
else
if(r==0)
r=X-1;
else
r=r-1;
}
