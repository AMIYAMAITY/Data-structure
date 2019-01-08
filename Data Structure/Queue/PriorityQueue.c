#include<stdio.h>
#include<stdlib.h>

struct pQueue
{
int data;
int priority;
struct pQueue *next;
}*front;

int insert(int item,int prio);
int delete();
int isEmpty();
int display();


int main()
{
int data,p,i;
while(1)
{
printf("\n1. Insert\n");
printf("\n2. Display\n");
printf("\n3. Delete\n");
printf("\n9. Exit\n");
printf("\n________________________________________\n");
scanf("%d",&i);
switch(i)
{
case 1:
	{
	printf("\nEnter priority and data:\n");
	scanf("%d%d",&p,&data);
	insert(data,p);
	break;
	}

case 2:
	{
	display();
	break;
	}
case 3:
	{
	delete();
	break;
	}
case 9:
	{
	exit(1);
	break;
	}
default:
	{
	printf("\nInvalid Choise\n");
	break;
	}

}
}
return 0;
}

int isEmpty()
{
if(front==NULL)
return 1;
else
return 0;
}
int insert(int item,int prio)
{
struct pQueue *p,*temp;
temp=(struct pQueue *)malloc(sizeof(struct pQueue *));
if(temp==NULL)
printf("\nMemory is not available\n");
else
{
	temp->data=item;
	temp->priority=prio;
	temp->next=NULL;
	if(isEmpty())
	front=temp;
	else
	{
		p=front;
		if(p->priority>=prio)
		{
			temp->next=p;
			p=temp;
			front=p;
		}
		else
		{
			while(p->next!=NULL && (p->next->priority<=prio))
			p=p->next;
			temp->next=p->next;
			p->next=temp;
		}
	}
}
}

int delete()
{
struct pQueue *s;
s=front->next;
printf("\nDeleted priority: %d and data: %d\n",front->priority,front->data);
free(front);
front=s;
}

int display()
{
struct pQueue *s;
s=front;
while(s!=NULL)
{
printf("(p:%d and D:%d)->",s->priority,s->data);
s=s->next;
}
}
