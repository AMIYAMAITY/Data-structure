#include<stdio.h>
#include<string.h>

void dictionaryOrder(char s[][64],int n)
{
	int r,i,k;
	char t[64];
	for(r=1;r<=n;r++)
	{
		for(i=0;i<n-r;i++)
		{
			k=strcmp(s[i],s[i+1]);
			if(k > 0)
			{
				strcpy(t,s[i]);
				strcpy(s[i],s[i+1]);
				strcpy(s[i+1],t);
			}
		}
	}

}

int main()
{
int i;
char a[][64]={
	{"zira"},
	{"subrata"},
	{"arup"},
	{"aamir"},
	{"amiya"}

};

dictionaryOrder(a,5);

for(i=0;i<5;i++)
	puts(a[i]);	


return 0;
}
