#include<stdio.h>
#include<stdlib.h>

struct Node *insert(struct Node *start);
struct Node *create(struct Node *start,float co,int ex);
void display(struct Node *start);
struct Node *checkExpo(struct Node *start);
struct Node *addPolynomial(struct Node *start,struct Node *start2);
struct Node *addMemo(struct Node *fAddr);


struct Node 
{
float coef;
int expo;
struct Node *link;
};

int main()
{
struct Node *start=NULL,*start2=NULL,*start3=NULL;
printf("\nfirst polynomial form:\n");
start=insert(start);
printf("\nsecond polynomial form:\n");
start2=insert(start2);
printf("\nfirst polynomial form result:\n");
display(start);
printf("\nsecond polynomial form result:\n");
display(start2);
start3=addPolynomial(start,start2);
printf("\nThe result of  polynomial Addition:\n");
display(start3);
return 0;
}

struct Node *insert(struct Node *start)
{
int n,i,ex;
float co;
printf("\nEnter terms:\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\nEnter Coefficient:\n");
scanf("%f",&co);
printf("\nEnter Exponent:\n");
scanf("%d",&ex);
start=create(start,co,ex);
}
return checkExpo(start);
}

struct Node *create(struct Node *start,float co,int ex)
{
struct Node *temp,*ptr,*ptr1;
temp=(struct Node *)malloc(sizeof(struct Node));
temp->coef=co;
temp->expo=ex;
temp->link=NULL;
if( start==NULL || start->expo<=ex )
{
temp->link=start;
start=temp;
}
else
{
ptr=start;
while( ptr->expo>ex && ptr->link!=NULL )
{
	ptr1=ptr;
	ptr=ptr->link;
}
	if( ptr->link==NULL && ptr->expo>ex )
	{
		temp->link=ptr->link;
		ptr->link=temp;
	}
	else
	{
		temp->link=ptr1->link;
		ptr1->link=temp;
	}
}
return start;
}


struct Node *checkExpo(struct Node *start)
{
struct Node *ptr=start,*ptr1;
if(start==NULL)
return NULL;
while(ptr->link!=NULL)
{
	if(ptr->expo==ptr->link->expo)
	{
		ptr->coef +=ptr->link->coef;
		ptr1=ptr->link;
		ptr->link=ptr1->link;
		free(ptr1);
	}
	else
		ptr=ptr->link;
}
return start;
}

struct Node *addPolynomial(struct Node *start,struct Node *start2)
{

struct Node *start3=NULL,*head3=NULL,*ptr=NULL;

if(start==NULL && start2==NULL)
return NULL;
else
while( start!=NULL || start2!=NULL )
{
	if(start==NULL || start2==NULL )
	{
		if(start==NULL)
		{
			if(start3==NULL)
			{
				start3=addMemo(start2);
				start2=start2->link;
				head3=start3;
			}
			else
			{
				while(start3->link!=NULL)
				start3=start3->link;
				while(start2!=NULL)
				{
					start3->link=addMemo(start2);
					start2=start2->link;
					start3=start3->link;
				
				}
			}
		}
		if(start2==NULL)
		{

			if(start3==NULL)
			{
				start3=addMemo(start);
				start=start->link;
				head3=start3;
			}
			else
			{
				while(start3->link!=NULL)
				start3=start3->link;
				while(start!=NULL)
				{
					start3->link=addMemo(start);
					start=start->link;
					start3=start3->link;
					
				}
			}
		}
	}
	else
	{
		if(start->expo>start2->expo)
		{
			if(start3==NULL)
			{
			start3=addMemo(start);
			head3=start3;
			}
			else
			{
			start3->link=addMemo(start);
			start3=start3->link;
			}
			start=start->link;
		}
		else
		{
			if(start3==NULL)
			{
			start3=addMemo(start2);
			head3=start3;
			}
			else
			{
			start3->link=addMemo(start2);
			start3=start3->link;
			}
			start2=start2->link;
		}
		
	}

}


return checkExpo(head3);
}



struct Node *addMemo(struct Node *fAddr)
{
struct Node *temp=NULL;
		temp=(struct Node *)malloc(sizeof(struct Node *));
		if(temp==NULL)
		return NULL;
		else
		{
		temp->coef=fAddr->coef;
		temp->expo=fAddr->expo;
		temp->link=NULL;
		}
return temp;
}



void display(struct Node *start)
{
if(start==NULL)
printf("\n");
else
while(start->link!=NULL)
{
printf("(%1.1fX^%d)+",start->coef,start->expo);
start=start->link;
}
printf("(%1.1fX^%d)\n",start->coef,start->expo);
}
