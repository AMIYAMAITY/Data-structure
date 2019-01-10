#include<stdio.h>
#include<stdlib.h>
#define HTS 11
int HT[HTS];


void nullSetup()
{
int i;
for(i=0;i<HTS;i++)
{
HT[i]=-1;
}
}

int getHashKey(int k)
{
int key,i=1;
key=k%HTS;
return key;
}

void delete(int kv)
{
int k,i=1;
k=getHashKey(kv);
while(HT[k]!=kv && k<(HTS-1))
{
k=getHashKey(kv+i);
i++;
}
HT[k]=-1;
}



int insert(int kv)
{
int k,i=1;
k=getHashKey(kv);
while(HT[k]!=-1)
{
k=getHashKey(kv+i);
i++;
}
HT[k]=kv;
}

int search(int kv)
{
int key,i=1;
key=getHashKey(kv);
while(HT[key]!=kv)
{
key=getHashKey(kv+i);
i++;
if(key==HTS)
{
break;
}
printf("\nkey value=%d",key);
}
if(key==HTS)
return -1;
else
return key;
}

void display()
{
int i;
for(i=0;i<HTS;i++)
{
printf("HT[%d]=%d\n",i,HT[i]);
}
}
int main()
{
int n,k;
nullSetup();
while(1)
{
printf("\n1. Insert\n");
printf("2. Display\n");
printf("3. Search\n");
printf("4. Delete");
printf("9. Exit\n");
printf("____________________________________\n");
scanf("%d",&n);
switch(n)
{
case 1:
	{
	printf("Enter key:\n");
	scanf("%d",&k);
	insert(k);
	break;
	}
case 2:
	{
	display();
	break;
	}
case 3:
	{
	printf("Enter key:\n");
	scanf("%d",&k);
	printf("search key:%d\n",search(k));
	break;
	}
case 4:
	{
	printf("Enter key:\n");
	scanf("%d",&k);
	delete(k);
	break;
	}
case 9:
	{
	exit(1);
	break;
	}
default:
	{
	printf("!Invalid Entry\n");
	break;
	}
}
}

return 0;
}
