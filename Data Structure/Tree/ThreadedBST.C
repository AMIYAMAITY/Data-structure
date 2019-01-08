#include<stdio.h>
#include<stdlib.h>
struct TBST
{
struct TBST *left,*right;
int lthreaded,rthreaded;
int data;
};

struct TBST* getNode(int key)
{
struct TBST *node=(struct TBST*)malloc(sizeof(struct TBST));
node->left=NULL;
node->right=NULL;
node->lthreaded=1;
node->rthreaded=1;
node->data=key;
return node;
}

struct TBST* insert(struct TBST *root,int key)
{
struct TBST *ptr=NULL,*temp;
	
	ptr=root;
	while(ptr!=NULL)
	{
		if(key==ptr->data)
		{
		printf("\nDuplicate data present\n");
		return root;
		}
		
		if(key < ptr->data && ptr->lthreaded==0)
		ptr=ptr->left;
		else if(key > ptr->data && ptr->rthreaded==0)
		ptr=ptr->right;
		else
		break;

	}

		if(ptr==NULL)
		{
		root=getNode(key);
		}
			
		else if(key < ptr->data)
		{
		temp=getNode(key);
		temp->left=ptr->left;
		temp->right=ptr;
		ptr->lthreaded=0;
		ptr->left=temp;
		}
		else
		{
		temp=getNode(key);
		temp->left=ptr;
		temp->right=ptr->right;
		ptr->rthreaded=0;
		ptr->right=temp;
		}
		
return root;
}


void preorderTraversal(struct TBST *root)
{
struct TBST *ptr;
if(root==NULL)
{
printf("\nTree is Empty!\n");
return;
}
else
{
ptr=root;
while(ptr!=NULL)
{
	printf("%d ",ptr->data);
	if(ptr->lthreaded==0)
	ptr=ptr->left;
	else if(ptr->rthreaded==0)
	ptr=ptr->right;
	else
	{
		while(ptr!=NULL && ptr->rthreaded==1)
		ptr=ptr->right;
		if(ptr!=NULL)
		ptr=ptr->right;
	}
}
}
printf("\n");
}

int case_a(struct TBST *ptr,struct TBST *par)
{

if(ptr->left==NULL && ptr->lthreaded==1 && ptr->right==NULL && ptr->rthreaded==1)
{
free(ptr);
return 1;
}
else if(ptr->right==par)
{
par->lthreaded=1;
par->left=ptr->left;
free(ptr);
return 1;
}
else if(ptr->left==par)
{
par->rthreaded=1;
par->right=ptr->right;
free(ptr);
return 1;
}
return 0;
}


int case_b(struct TBST *ptr,struct TBST *par)
{
struct TBST *temp,*p;
if(ptr->rthreaded==0)
{
temp=ptr->left;
p=ptr->right;
while(p->lthreaded!=1)
p=p->left;
p->left=temp;
if(par->left==ptr)
par->left=ptr->right;
else
par->right=ptr->right;
free(ptr);
return 1;
}
else if(ptr->lthreaded==0)
{
temp=ptr->right;
p=ptr->left;
while(p->rthreaded!=1)
p=p->right;
p->right=temp;
if(par->right==ptr)
par->right=ptr->left;
else
par->left=ptr->left;
free(ptr);
return 1;
}
return 0;
}

int case_c(struct TBST *ptr)
{
struct TBST *p,*p1;
p=ptr->right;
p1=ptr;
while(p->lthreaded!=1)
{
p1=p;
p=p->left;
}
ptr->data=p->data;
	if(p->lthreaded==0)
	return case_b(p,p1);
	else if(p->rthreaded==0)
	return case_b(p,p1);
	else if(p->rthreaded==1 && p->lthreaded==1)
	return case_a(p,p1);
return 0;
}

int delete(struct TBST *root,int key)
{
struct TBST *ptr=root,*par=NULL;
int found=0,r;
	while(ptr!=NULL)
	{
		if(ptr->data==key)
		{
		found=1;
		break;
		}
		par=ptr;
		if(key<ptr->data)
		{
			if(ptr->lthreaded==0)
			ptr=ptr->left;
			else
			break;
		}
		else
		{
			if(ptr->rthreaded==0)
			ptr=ptr->right;	
			else
			break;
		}
	}
	
	if(found==0)
	return 0;
	else if(ptr->lthreaded==0 && ptr->rthreaded==0)
	return case_c(ptr);
	else if(ptr->lthreaded==0)
	return case_b(ptr,par);
	else if(ptr->rthreaded==0)
	return case_b(ptr,par);
	else if(ptr->rthreaded==1 && ptr->lthreaded==1)
	return case_a(ptr,par);
return 0;
}

int main()
{
struct TBST *root=NULL;
root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 30);
    root = insert(root, 16);
    root = insert(root, 14);
    root = insert(root, 13);
    root = insert(root, 15);
preorderTraversal(root);
delete(root,20);
preorderTraversal(root);
return 0;
}
