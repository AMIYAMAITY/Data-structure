#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>

void create_node();
void display(struct node *head);
void insert_node_beginning(struct node *head);
void insert_last(struct node *head);
void insert_any_position(struct node *head);
void destroy_all_node();
void delete_beginning_node();
void delete_last_node(struct node *head);
void delete_any_position(struct node *head);
void update_beginning();
void update_last(struct node *head);
void update_any_position(struct node *head);
void about_developer();
void sort_data(struct node *head);
void search(struct node *head);

struct node
{
int data;
struct node *next;
}*start;

int main()
{
int n,i,d,u;
//clrscr();
while(1){
printf("------------------|________________________|----------------\n");
printf("\n press 1 for create node");
printf("\n press 2 for display");
printf("\n press 3 for insert section");
printf("\n press 4 for delete section");
printf("\n press 5 for update section");
printf("\n press 6 for sort data");
printf("\n press 7 for data searching");
printf("\n\n press 8 for Destroy all node");
printf("\n press 9 for clear screen");
printf("\n press 0 for exit");
printf("\n press 10 About Developer");
printf("\n____________________________________________________________");
printf("\n                   Enter your choice\n");
fflush(stdin);
scanf("%d",&n);
switch(n)
{
	case 0:
	{
	exit(1);
	}
	case 1:
	{
	create_node();
	break;
	}
	case 2:
	{
	display(start);
	break;
	}
	case 3:
	{
		printf("\n press 1 for insert beginning");
		printf("\n press 2 for insert last");
		printf("\n press 3 for any position");
		printf("\n__________________________________________\n");
		scanf("%d",&i);
		switch(i)
		{
		case 1:
		{
		insert_node_beginning(start);
		break;
		}
		case 2:
		{
		insert_last(start);
		break;
		}
		case 3:
		{
		insert_any_position(start);
		break;
		}
		default:
		{
		printf("\n sorry wrong choice\n");
		break;
		}
		}

	break;
	}
	case 4:
	{

		printf("\n press 1 for delete node beginning");
		printf("\n press 2 for delete last node");
		printf("\n press 3 for delete any position of data");
		printf("\n______________________________________________\n");
		scanf("%d",&d);
		 switch(d)
		 {
			case 1:
			 {
			 delete_beginning_node();
			 break;
			 }
			 case 2:
			 {
			 delete_last_node(start);
			 break;
			 }
			 case 3:
			 {
			 delete_any_position(start);
			 break;
			 }
			 default:
			 {
			 printf("\n sorry ! your choice is wrong\n");
			 break;
			 }
		 }


	break;
	}
	case 5:
	{
		printf("\n press 1 for data update beginning");
		printf("\n press 2 for data update last node");
		printf("\n press 3 for data update any position\n");
		scanf("%d",&u);
		switch(u)
		{
			case 1:
			{
			update_beginning();
			break;
			}
			case 2:
			{
			update_last(start);
			break;
			}
			case 3:
			{
			update_any_position(start);
			break;
			}
			default:
			{
			printf("\n sorry! your choice is wrong\n");
			break;
			}
		}
	break;
	}
	case 7:
	{
	search(start);
	break;
	}
	case 8:
	{
	destroy_all_node();
	break;
	}
	case 6:
	{
	sort_data(start);
	break;
	}
	case 9:
	{
	//clrscr();
	
	break;
	}
	case 10:
	{
	about_developer();
	break;
	}
	default:
	{
	printf("\n sorry! wrong choice try again\n");
	}
 }
}
//getch();
return 0;
}

void about_developer()
{
  printf("                ______________________________________________\n");
  printf("                 |                                          |\n");
  printf("                 |                                          |\n");
  printf("                 |   Developed by:- Amiya Maity             |");
  printf("\n");
  printf("                 |   Contact Us:-   amiyamaity23@gmail.com  |");
  printf("\n");
  printf("                 |                                          |\n");
  printf("                 |                                          |\n");
  printf("                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void create_node()
{
int n;
struct node *p,*ptr;
start=NULL;
printf("\n How many create node:\n");
scanf("%d",&n);
while(n>0)
	{
	  ptr=(struct node*)malloc(sizeof(struct node*));
	  ptr->next=NULL;
	  printf("\n Enter data:\n");
	  scanf("%d",&ptr->data);
	  if(start==NULL)
		{
		  start=ptr;
		  p=ptr;
		}
	  else
		{
		p->next=ptr;
		p=ptr;
		}
		n--;
	}
}

void display(struct node *head)
{
  if(head==NULL)
  {
  printf("\n sorry node is not create");
  printf("\n");
  }
  else
  {
  printf("\n your entered data:\n");
  printf("    ");
  while(head->next!=NULL)
  {
  printf("%d",head->data);
  printf("->");
  head=head->next;

  }
  printf("%d",head->data);
  printf("\n");
  }
}


void insert_node_beginning(struct node *head)
{
	struct node *ptr;
	  ptr=(struct node*)malloc(sizeof(struct node*));
	  ptr->next=NULL;
	  printf("\n Enter data for beginning insert:\n");
	  scanf("%d",&ptr->data);
	  ptr->next=head;
	  start=ptr;
	  printf("\n Data is inserted\n");
	  
}

void insert_last(struct node *head)
{
      struct node *ptr;
      if(head==NULL)
      {
	  ptr=(struct node*)malloc(sizeof(struct node*));
	  ptr->next=NULL;
	  printf("\n Enter data for last insert:\n");
	  scanf("%d",&ptr->data);
	  start=ptr;
	  printf("\n Data is inserted\n");

      }
      else{
	  ptr=(struct node*)malloc(sizeof(struct node*));
	  ptr->next=NULL;
	  printf("\n Enter data for last insert:\n");
	  scanf("%d",&ptr->data);
	  while(head->next!=NULL)
	  head=head->next;
	  head->next=ptr;
	  printf("\n Data is inserted\n");
	  }
}

void insert_any_position(struct node *head)
{
int i,n,c=0;
struct node *p,*ptr,*ch;
ch=head;
       while(ch!=NULL)
       {
       ch=ch->next;
       c++;
       }
	printf("\n Enter position for insert data\n");
	scanf("%d",&n);
	if(n<1 || n>c+1)
	printf("\n invalid position\n");
	else{
	if(n==1)
	insert_node_beginning(start);
	else
	{
	for(i=1;i<n-1;i++)
	{
	head=head->next;
	}
		p=head->next;
	  ptr=(struct node*)malloc(sizeof(struct node*));
	  ptr->next=NULL;
	  printf("\n Enter data for any position insert:\n");
	  scanf("%d",&ptr->data);
	  head->next=ptr;
	  ptr->next=p;
	  printf("\n Data is inserted\n");

      }
     }
}

void destroy_all_node()
{
struct node *z;


	while(start!=NULL)
	{
	z=start;
	start=start->next;
	free(z);
	}
	printf("\n ! All node is Destroyed !\n");


}



void delete_beginning_node()
{
struct node *z;
   if(start==NULL)
   display(start);
   else
   {
	z=start;
	start=start->next;
	free(z);
	printf("\n first node is deleted\n");
   }

}


void delete_last_node(struct node *head)
{
struct node *z;
	if(head==NULL)
	display(start);
	else if(start->next==NULL)
	{
	z=start;
	free(z);
	start=NULL;
	printf("\n last node is deleted\n");
	}
	else
	{
	while(head->next->next!=NULL)
	  head=head->next;
	  z=head->next;
	  free(z);
	  head->next=NULL;
	  printf("\n last node is deleted!\n");
	}
}

void delete_any_position(struct node *head)
{
    int i,n,c=0;
struct node *p,*ch,*q;
ch=head;
     if(head==NULL)
     display(start);
     else
     {
       while(ch!=NULL)
       {
       ch=ch->next;
       c++;
       }
	printf("\n Enter position for delete data\n");
	scanf("%d",&n);
	if(n<1 || n>c)
	printf("\n invalid position\n");
	else{
			if(n==1)
			delete_beginning_node();
		else
		{
			for(i=1;i<n-1;i++)
			{
			head=head->next;
			}
				p=head->next;
				q=p->next;
				head->next=q;
				free(p);
				printf("\n your position data is deleted !\n");
		}
	   }
      }
}


void update_beginning()
{
	if(start==NULL)
	display(start);
	else
	{
		printf("\n Enter update data for first\n");
		scanf("%d",&start->data);
		printf("\n Data is update\n");
	}
}

void update_last(struct node *head)
{
if(head==NULL)
display(start);
else{
      while(head->next!=NULL)
      head=head->next;
      printf("\n Enter update data for last\n");
      scanf("%d",&head->data);
      printf("\n Data is update\n");
     }

}


void update_any_position(struct node *head)
{
      int i,n,c=0;
struct node *ch;
ch=head;
     if(head==NULL)
     display(start);
     else
     {
       while(ch!=NULL)
       {
       ch=ch->next;
       c++;
       }
	printf("\n Enter position for update data\n");
	scanf("%d",&n);
	if(n<1 || n>c)
	printf("\n invalid position\n");
	else{
			if(n==1)
			update_beginning();
		else
		{
			for(i=1;i<n;i++)
			{
			head=head->next;
			}

			printf("\n Enter update data for last\n");
			scanf("%d",&head->data);
			printf("\n Data is update\n");

		}
	   }
      }
}



void sort_data(struct node *head)
{
int t;
struct node *hi,*hj;
hi=head;
hj=head;
	if(head==NULL)
	display(start);
	else
	{
		while(hi->next!=NULL)
		{
	       hj=head;
			while(hj->next!=NULL)
			{
				if(hj->data>hj->next->data)
				{
				  t=hj->data;
				  hj->data=hj->next->data;
				  hj->next->data=t;
				}
			 hj=hj->next;
			}
		hi=hi->next;
		}
	display(start);
	}
}

void search(struct node *head)
{
int n,c=1,f;
	if(head==NULL)
		printf("\n sorry! node is not created\n");

	else
	{
		printf("\n Enter item for searching:\n");
		scanf("%d",&n);

		while(head!=NULL)
		{
			if(head->data==n)
			{
			f=1;
			break;
			}
			else
			f=0;
			head=head->next;
			c++;
		}


	if(f==1)
	printf("\n Data %d is found following %d position\n",head->data,c);
	else
	printf("\n sorry item is not found\n");
	}
}

